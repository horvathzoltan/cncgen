#include "common/logger/log.h"
#include "generategcode.h"
#include "messages.h"
#include <QtMath>
#include <QString>
#include <QStringList>
#include "gcode/gcode.h"
#include "gcode/variable.h"
#include "gcode/string.h"
#include "gcode/comment.h"
#include "geometry/geomath.h"
#include "gcode/feed.h"
#include "helpers/stringhelper.h"
#include "common/helper/textfilehelper/textfilehelper.h"
#include <QDir>

const QString GenerateGcode::G1 = L("G:");
const QString GenerateGcode::G2 = L("    ->");
const QString GenerateGcode::T1 = L("T:");
const QString GenerateGcode::T_ERR = L("E:");
const QString GenerateGcode::T_W = L("W:");
const QString GenerateGcode::safeKey = L("safe");
const QString GenerateGcode::offsetKey = L("offset");

void GenerateGcode::Init(){
    gcodes.clear();

    _XYMode=XYMode::XY;
    _MMode = {};
    _tools.clear();

    _selected_tool_ix = -1;
    _selected_feed ={};
    _selected_cut ={};

    _last_tool_ix=-1;
    _last_feed ={};
    _last_cut = {};
    _lastHoleP={};
    _last_hole_diameter =-1;
    _lastLine={};
    _lastBox={{},{},BoxType::Undefined};
    //    _lastBoxP1={};
    //    _lastBoxType=BoxType::Undefined;
    _last_position = {};
    _last_gmode=GMode::Undefined;

    _total_time=0;
    _total_length=0;
    _total_cut=0;
    _ratio=1;

    _offset_xyz = {};

    GCode::_variables.Clear();
}

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{

    //_lastBox.type = BoxType::Undefined;

    for(auto l:g){
        QString err;
        QString gcode;

        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        if(l.startsWith('#')) continue;
        if(l.startsWith('/')) continue;

        if(GCode::_variables.Parse(l)){
            zInfo(T1+l)
            continue;
        }
        if(l.startsWith(String::key)){
            if(ParseStringToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
        }
        // XYMode::ValidateLineType -> XYMode::Parse(l)
        if(XYMode::ValidateLineType(l)){
            if(ParseSetXYModeToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
        }

        if(MMode::ValidateLineType(l)){
            if(ParseSetMModeToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
        }

        if(Box::Parse(l).state()!=ParseState::NoData){
            if(ParseBoxToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
            }
            continue;
        }

        if(Point::Parse(l, safeKey).state()!=ParseState::NoData){
            Point ps;
            auto s1 = Point::Parse(l,  _XYMode, _MMode, safeKey, &ps, nullptr);
            if(s1.state()==ParseState::Parsed){
                _safe_place = ps;
            }
            continue;
        }

        if(Point::Parse(l, offsetKey).state()!=ParseState::NoData){
            Point ps;
            auto s1 = Point::Parse(l,  _XYMode, _MMode, offsetKey, &ps, nullptr);
            if(s1.state()==ParseState::Parsed){
                _offset_xyz = ps;
            }
            continue;
        }

        if(l.startsWith(L("ratio"))){
            qreal r;
            bool isok = GCode::ParseValue(l, L("ratio"), &r);
            if(isok) _ratio = r;
            continue;
        }

        if(l.startsWith(L("include"))){
            QString fn;
            bool isok = GCode::ParseValue(l, L("include"), &fn);
            if(isok){
                _includeFn = fn;

                auto d = QDir(_workingFolder);

                auto inf = d.filePath(fn);

                auto geomLines = com::helper::TextFileHelper::loadLines(inf);

                if(!geomLines.isEmpty()){
                    QStringList gcodes2 = Generate(geomLines);
                    QString gcodes3 = gcodes2.join('\n');
                    AppendGCode(&gcodes, gcodes3, err);
                } else{
                    zInfo("include: empty file: "+fn )
                }
            } else{
                zInfo("include is not ok")
            }
            continue;
        }

        if(Feed::Parse(l).state()!=ParseState::NoData){
            if(ParseSetFeedToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
            }
            continue;
        }


        switch(l[0].unicode()){
        case Comment::keyUniCode:
            if(ParseCommentToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Hole::keyUniCode:
            if(ParseHoleToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Line::keyUniCode:
            if(ParseLineToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Arc::keyUniCode:
            if(ParseArcToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Tool::keyUniCode:
            if(ParseSetToolToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
//        case Feed::keyUniCode_feed:
//            if(ParseSetFeedToGCode(l, &gcode, &err)){
//                AppendGCode(&gcodes, gcode, err);
//                continue;
//            }
//            break;
//        case Feed::keyUniCode_spindleSpeed:
//            if(ParseSetSpindleSpeedToGCode(l, &gcode, &err)){
//                AppendGCode(&gcodes, gcode, err);
//                continue;
//            }
//            break;
        }
    }

    _last_position.z=0;
    auto gc2=TravelXYToGCode(_safe_place);
    if(gc2.isEmpty()){
        zInfo("no safe place")
    } else {
        gcodes.insert(0, gc2);
        gcodes.insert(1, '('+Messages::travelSafe+')');
        gcodes.append(gc2);
        gcodes.append('('+Messages::travelSafe+')');
    }

    return gcodes;
}

auto GenerateGcode::ParseArcToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Arc m;
    auto s = Arc::Parse(str, _XYMode, &m, _MMode, &_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed ) // ha Arc t??pus?? sor
    {
        if(gcode)*gcode=ArcToGCode(m,err);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto  GenerateGcode::ParseLineToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Line m;
    auto s = Line::Parse(str, _XYMode, _MMode, &m, &_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed ) // ha Arc t??pus?? sor
    {        
        if(gcode)*gcode=LineToGCode(m,err);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseHoleToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Hole m;
    auto s = Hole::Parse(str, _XYMode, _MMode, &m, &_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed ) // ha Box t??pus?? sor
    {
        if(gcode)*gcode=HoleToGCode(m,err);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseBoxToGcode(const QString& str, QString *gcode, QString *err) -> bool
{
    Box m;
    auto s = Box::Parse(str, _XYMode, _MMode, &m, &_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed ) // ha Box t??pus?? sor
    {
        if(gcode)*gcode=BoxToGCode(m,err);
    }
    QString msg;
    msg+=s.ToString();
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseCommentToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    Comment m;
    auto s = Comment::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed )
    {
        if(gcode)*gcode=m.text;
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseStringToGCode(const QString& str, QString *gcode, QString *err)-> bool
{
    Q_UNUSED(err)
    String m;
    auto s = String::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed )
    {        
        auto mm = m.ToString();
        if(gcode)*gcode=mm;//.ToString();
        auto msg1 = G1+mm;//.ToString();
        StringHelper::Tabulate(&msg1, G2);
        zInfo(msg1);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg+" "+s.ToString());
    return true;
}

auto GenerateGcode::ParseSetToolToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Tool m;
    auto s = Tool::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    QString msg(T1+str);
    if(s.state() == ParseState::Parsed )
    {
        if(gcode)*gcode=SetToolToGCode(m, err);
    }
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseSetFeedToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    //Feed m;
    auto s = Feed::Parse(str, &_selected_feed);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);

    //QString gcode1, gcode2;
    //gcode1=SetFeedToGCode(err);
    //gcode2=SetSpindleSpeedToGCode(err);

    if(s.state() == ParseState::Parsed )
    {
        if(gcode){
            auto g1=SetFeedToGCode(err);
            if(!g1.isEmpty()) g1+='\n';
            g1+=SetSpindleSpeedToGCode(err);
            *gcode=g1;
        }
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

//auto GenerateGcode::ParseSetSpindleSpeedToGCode(const QString& str, QString *gcode, QString *err) -> bool
//{
//    //Feed m;
//    auto s = _selected_feed.ParseIntoSpindleSpeed(str);
//    if(s.state()==ParseState::NoData) return false;
//    zInfo(T1+str);
//    if(s.state() == ParseState::Parsed )
//    {
//        //_selected_feed.spindleSpeed=m.spindleSpeed;
//        if(gcode)*gcode=SetSpindleSpeedToGCode(err);
//    }
//    QString msg;
//    StringHelper::Append(&msg, s.ToString(), '\n');
//    if(!msg.isEmpty())zInfo(msg);
//    return true;
//}

auto GenerateGcode::ParseSetXYModeToGcode(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    //Feed m;
    auto s = XYMode::Parse(str, &_XYMode);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed )
    {
        //_selected_feed.f=m.f;
        if(gcode)*gcode=SetXYModeToGCode();
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

auto GenerateGcode::ParseSetMModeToGcode(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    //Feed m;
    auto s = MMode::Parse(str, &_MMode);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);
    if(s.state() == ParseState::Parsed )
    {
        //_selected_feed.f=m.f;
        //if(gcode)*gcode=SetXYModeToGCode();
        *gcode='('+_MMode.ToString()+')';
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

// todo 11 circle: c - mint a hole, csak nincs bel??l kimarva - a gaps eset -> ventill??tor kiv??g??s
// todo 12 o: forgat??s minden elemre - o k??z??ppont, ??s sz??g

auto GenerateGcode::AppendGCode(QStringList* gs, const QString &g, const QString& err, const QString& comment) -> bool
{
    if(!gs) return false;
    if(!g.isEmpty()){
        if(comment.isEmpty()){gs->append(g);}
        else{gs->append(g+" ("+comment+')');}
    }
    if(!err.isEmpty()){
        zInfo(err);
        return false;
    }
    return true;
}

auto GenerateGcode::LiftUpToGCode(const QVariant& z=QVariant()) -> QString
{
    QStringList g;
    QString err;

    if(_last_position.z >=_movZ){ return {};}
    if(!z.isNull()){
        auto z0 = z.value<double>();
        qreal l = z0-_last_position.z;
        auto gcode = GoToZ(GMode::Linear,{0,0,z0}, l);//+ " (pull)";
        AppendGCode(&g, gcode, err, QStringLiteral("pull"));
    }
    qreal l = _movZ-_last_position.z;
    auto gcode = GoToZ(GMode::Rapid,{0,0,_movZ}, l);// + "(lift up)";
    AppendGCode(&g, gcode, err, "lift up");
    return g.join('\n');
}

auto GenerateGcode::LiftDownToGCode(qreal z)-> QString
{
    QStringList g;
    QString err;

    if(_last_position.z==z){ return {};}
    auto z2 = z+1;
    qreal l = _last_position.z-z2;
    auto gcode = GoToZ(GMode::Rapid,{0,0,z2},l);//+ " (lift down)";
    AppendGCode(&g, gcode, err, L("lift down"));
    l = _last_position.z-z;
    gcode = GoToZ(GMode::Linear,{0,0,z}, l);//+ " (push)";
    AppendGCode(&g, gcode, err, L("push"));

    return g.join('\n');
}

auto GenerateGcode::TravelXYToGCode(const Point& p) -> QString
{
    QStringList g;
    QString err;

    auto g1 = LiftUpToGCode();
    AppendGCode(&g, g1, "", "");
    //g.append(g1);
    qreal l = GeoMath::Distance(_last_position, p);
    auto gcode = GoToXY(GMode::Rapid, p, l);
    //if(!gcode.isEmpty())gcode+=" (travel)";
    AppendGCode(&g, gcode, err, L("travel"));
    return g.join('\n');
}

/*GENERATE GEOMETRY*/
auto GenerateGcode::ValidateTool()->bool
{
    if(_selected_tool_ix==-1){
        zInfo(QStringLiteral("no tool selected"));
        return false;
    }
    if(!_tools.contains(_selected_tool_ix)) {
        zInfo("tool not found: "+QString::number(_selected_tool_ix));
        return false;
    }
    return true;
}

void GenerateGcode::SetSelectedFeed(Feed feed){
    if(feed.spindleSpeed()!=-1) _selected_feed.setSpindleSpeed(feed.spindleSpeed());
    if(feed.feed()!=-1)_selected_feed.setFeed(feed.feed());
}

/*LINE*/
auto GenerateGcode::LineToGCode(const Line& m,QString *err) -> QString
{
    //_lasterr.clear();/*LINE*/
    QString msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);    
    zInfo(msg);

    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){if(err)*err=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return {};
    /*FEED*/
    SetSelectedFeed(m.feed);
    /*TOOL*/
    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = _tools[_selected_tool_ix];


    /**/
    if(m.p0.isValid()){
        _lastLine.p0=m.p0;
    }
    if(m.rp.isValid()){
        if(_lastLine.p0.isValid()){
            _lastLine.p0.x+=m.rp.x;
            _lastLine.p0.y+=m.rp.y;
            _lastLine.p0.z+=m.rp.z;
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }
    if(m.p1.isValid()){
        _lastLine.p1=m.p1;
    }
    if(m.rp.isValid()){
        if(_lastLine.p1.isValid()){
            _lastLine.p1.x+=m.rp.x;
            _lastLine.p1.y+=m.rp.y;
            _lastLine.p1.z+=m.rp.z;
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(_lastLine.p0==_lastLine.p1){
        if(err){*err=L("start and end points are equal");}
        return{};
    }

    auto distance = GeoMath::Distance(_lastLine.p0, _lastLine.p1);
    if(distance<t.d) {
        if(err){*err=L("line too short");}
        return {};
    }

    Gap mgap; // megval??s??tand?? gap
    if(m.gap.isValid()){//gapeket akar
        //if(mgap.height<_last_cut.z0){if(err)*err=L("gap he"); return{};}
        int gapn = qFloor(distance/(t.d+m.gap.length)); // h??ny gap f??r ki
        if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
         if(m.gap.n>gapn) { gapn=m.gap.n;} // ha t??bb is kif??r, annyit kap amennyit k??r
         mgap = {(m.gap.n>gapn)?gapn:m.gap.n,// ha t??bbet k??rt, mint ami kif??r
                 m.gap.length,m.gap.height};
    }

    QStringList g(QStringLiteral("(line)"));    
    g.append(TotalTimeToGCode());
    msg=G2+ _lastLine.p0.ToString()+' '+_lastLine.p1.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();    
    if(mgap.isValid()) msg+= " gaps:"+QString::number(mgap.n);
    zInfo(msg);
    /*CUT*/
    qreal z2 = mgap.isValid()?_last_cut.z-mgap.height:_last_cut.z;
    if(z2>0){ g.append(LinearCut(z2)); }
    if(mgap.isValid()){
        Point ba1=GeoMath::Translation(_lastLine.p0, 0, 0, -z2);
        Point ja1=GeoMath::Translation(_lastLine.p1, 0, 0, -z2);
        Cut cut_gap{mgap.height, _last_cut.z0};
        Line l_gap={ba1,ja1, cut_gap, _last_feed,{}};
        auto segments = l_gap.Divide(m.gap, t.d);
        for(auto&segment:segments){
            auto px0 = _lastLine.p0;
            auto px1 = _lastLine.p1;
            _lastLine.p0=segment.p0;
            _lastLine.p1=segment.p1;
            g.append(LinearCut(segment.cut.z));            
            _lastLine.p0 = px0; // azonnal vissza is ??ll??tjuk
            _lastLine.p1 = px1;
        }

    }


    g.append(TotalTimeToGCode());
    return g.join('\n');
}

auto GenerateGcode::TotalTimeToGCode() -> QString
{
    return "(time: "+QString::number(_total_time)+")";
}

void GenerateGcode::GoToCutposition(QStringList *g, const Point& p){
    AppendGCode(g, TravelXYToGCode(p));
    AppendGCode(g, SpindleStartToGCode());
    AppendGCode(g, SetFeedToGCode());
    AppendGCode(g, LiftDownToGCode(p.z));
}

// koordin??t??k minden param??ter be van ??ll??tva
auto GenerateGcode::LinearCut(qreal total_depth) -> QStringList{
    QStringList g(QStringLiteral("(linear cut)"));
    QString msg;
    Point p = _lastLine.p0;

    GoToCutposition(&g, p);

    int steps_0 = qCeil(total_depth/_last_cut.z0)+1;

    msg+= "cut:"+_lastLine.p0.ToString()+"->"+_lastLine.p1.ToString();
    msg+= " total_depth:"+QString::number(total_depth);
    msg+= " steps:"+QString::number(steps_0);

    for(int i=0;i<steps_0;i++){
        Point pd=p;
        if(!(i%2))
        {
            p=_lastLine.p1;
        }
        else
        {
            p=_lastLine.p0;
        }

        qreal z = p.z-(i+1)*_last_cut.z0;
        qreal zz = p.z-total_depth;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal d=GeoMath::Distance(pd,p);
        AppendGCode(&g, GoToXYZ(GMode::Linear, p, d));
        if(d<=10) AppendGCode(&g, Dwell(100));//250
    }

    AppendGCode(&g, LiftUpToGCode(p.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
}

auto GenerateGcode::HelicalCut(qreal total_depth, qreal path_r) -> QStringList{
    QStringList g(QStringLiteral("(helical cut)"));
    QString msg;
    Point p = GeoMath::Translation(_lastHoleP, -path_r, 0, 0);

    GoToCutposition(&g, p);

    int steps_0 = qCeil(total_depth/_last_cut.z0)+1;

    msg+= "cut:"+_lastHoleP.ToString()+"r="+GCode::r(path_r);
    msg+= " total_depth:"+QString::number(total_depth);
    msg+= " steps:"+QString::number(steps_0);

    for(int i=0;i<steps_0;i++){
        Point pp=p;
        qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kisz??mol
        qreal zz = _lastHoleP.z-total_depth;//_last_cut.z;
        if(z<zz){    //be??ll??tjuk a p-t
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal l = path_r*2*M_PI;
        qreal lz = pp.z-p.z;
        qreal l1 = qSqrt(l*l+lz*lz);
        g.append(
            GoToZ(GMode::Circular,p, l1)+" i"+GCode::r(path_r));
    }

    AppendGCode(&g, LiftUpToGCode(_lastHoleP.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
}

auto GenerateGcode::CircularArcCut(qreal total_depth) -> QStringList{
    QStringList g(QStringLiteral("(circular_arc cut)"));
    QString msg;

    GoToCutposition(&g, _lastArc.p0);
    Point p;
    GMode::Mode mode;
    QString ij;
    qreal i,j,i1,j1,i0,j0;
    i1=_lastArc.o.x-_lastArc.p0.x;
    j1=_lastArc.o.y-_lastArc.p0.y;

    i0=_lastArc.o.x-_lastArc.p1.x;
    j0=_lastArc.o.y-_lastArc.p1.y;

    int steps = qCeil(total_depth/_last_cut.z0)+1;

    msg+= "cut:"+_lastArc.p0.ToString()+"->"+_lastArc.p1.ToString()+"o="+_lastArc.o.ToString();
    msg+= " total_depth:"+QString::number(total_depth);
    msg+= " steps:"+QString::number(steps);

    for(int step=0;step<steps;step++){
        Point pp = p;
        if(!(step%2))
        {
            p=_lastArc.p1;
            mode = GMode::Circular;
            i=i1;
            j=j1;
        }
        else
        {
            p=_lastArc.p0;
            mode = GMode::Circular_ccw;
            i=i0;
            j=j0;
        }
        QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
        qreal z = p.z-(step+1)*_last_cut.z0;
        qreal zz = p.z-total_depth;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal d=GeoMath::ArcLength(pp,p, _lastArc.o);
        g.append(GoToXYZ(mode, p, d)+' '+ij2);
    }
    g.append(LiftUpToGCode(_lastArc.p0.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
}


auto GenerateGcode::CheckCut(QString *err) -> bool
{
    if(_last_cut.z<=0) {if(err)*err=L("no toal cut depth");return false;}
    if(_last_cut.z0>_last_cut.z) {
        if(err){
            *err=L("wrong cut depth: ")+GCode::r(_last_cut.z0)+
                " total: "+GCode::r(_last_cut.z);
        }
        return false;
    }
    return true;
}

/*HOLE*/
auto GenerateGcode::HoleToGCode(const Hole &m, QString*err) -> QString
{
    //_lasterr.clear();
    auto msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);
    zInfo(msg);

    /*DIAMETER*/
    if(_last_hole_diameter==-1 && m.diameter==-1){if(err){*err=L("no diameter");} return {};}
    if(m.diameter!=-1) _last_hole_diameter = m.diameter;
    if(_last_hole_diameter<=0) {
        if(err){*err=L("wrong diameter: ")+GCode::r(_last_hole_diameter);}
        return {};
    }
    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){
        if(err){*err=L("no total cut depth");} return {};
    }
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return{};
    /*FEED*/
    SetSelectedFeed(m.feed);
    /*TOOL*/
    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = _tools[_selected_tool_ix];
    qreal holeDiameter = _last_hole_diameter+m.jointGap;
    if(holeDiameter<t.d) {
        if(err){*err=L("wrong diameter: ")+GCode::r(holeDiameter)+
                " tool: "+t.ToString();
        }
        return {};
    }


    double path_r = (holeDiameter-t.d)/2; // a furat bels?? sz??l??t ??rint?? p??lyapont
    Gap mgap = m.gap.isValid()?m.gap:Gap{2, .5, 0.5};

    bool pre_drill, pre_mill,hasGaps, drillOnly=holeDiameter==t.d;
    if(m.np){
        pre_drill = false;
        pre_mill =false;

        if(m.gap.n>0){
            hasGaps = true; //
            int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // h??ny gap f??r ki
            if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
            if(mgap.n>gapn){mgap.n=gapn;}// ha t??bbet k??rt, mint ami kif??r
        } else{
            hasGaps=false;
        }

    }else{
        if(drillOnly){
            pre_drill=true;
            pre_mill=false;
            hasGaps = false;
        } else{
            hasGaps = holeDiameter>5*t.d; //
            if(hasGaps){
                pre_drill=false;
                pre_mill=false;

                int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // h??ny gap f??r ki
                if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
                if(mgap.n>gapn){mgap.n=gapn;}// ha t??bbet k??rt, mint ami kif??r

            } else {
                pre_drill = holeDiameter>2*t.d; //d=0
                pre_mill = holeDiameter>3*t.d; //d=2*t.d
            }
        }
    }
    if(m.p.isValid()){
        _lastHoleP=m.p;
    }
    if(m.rp.isValid()){
        _lastHoleP.x+=m.rp.x;
        _lastHoleP.y+=m.rp.y;
        _lastHoleP.z+=m.rp.z;
    }

    SetSelectedFeed(m.feed);

    QStringList g(QStringLiteral("(hole - helical interpolation)"));
    g.append(TotalTimeToGCode());

    Point p = _lastHoleP; // _lastHoleP k??z??ppont , p a szersz??mp??lya kezd??pontja lesz

    msg=G2+ p.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_selected_feed.ToString();
    msg+=" d"+GCode::r(holeDiameter);
    if(pre_drill) msg+=L(" predrill");
    if(pre_mill) msg+=L(" premill");
    if(hasGaps) msg+=L(" gap");
    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);
    zInfo(msg);

    if(pre_drill){
        // 81: depth<3-5*t.d;
        // normal: 5*t.d
        // 83 peck:5-7
        // ha h??re l??gyul az anyag, homlokmar??n??l el??f??r??sn??l kell a peck
        //bool is_peck = t.type==Tool::Milling&&_last_cut.z>3;
        qreal zz = _lastHoleP.z-_last_cut.z;

       g.append(L("(predrill)"));
       g.append(TravelXYToGCode(p)); //TRAVEL
       auto sp = SpindleStartToGCode(); // selected->last
       if(!sp.isEmpty()) g.append(sp);
       auto f = SetFeedToGCode();
       if(!f.isEmpty()) g.append(f);

       //g.append(L("G98 G81")+" z"+GCode::r(zz)+" r"+GCode::r(p.z));
       // zz: m??lys??g
       // r: visszah??z??s z-je
       // q: m??lys??g inkrement per peck
       g.append(L("G98 G83")+" z"+GCode::r(zz)+" r"+GCode::r(p.z+1)+" q"+GCode::r(m.cut.z0) );

       if(_last_feed.feed()>0){
           qreal l0 = _last_position.z-zz;
           qreal l1 = p.z-zz;

           _total_time+=l1/_last_feed.feed()+l0/1500;
       }

       _last_position.z = p.z;
    }
    if(!drillOnly){
        if(pre_mill){
            g.append(L("(premill)"));
            auto g1=HelicalCut(_last_cut.z, t.d);
            g.append(g1);
        }

        p.x -= path_r; //szersz??mp??lya kezd?? pontja
        qreal z2 = hasGaps?_last_cut.z-mgap.height:_last_cut.z;

        if(z2>0){
            auto g1=HelicalCut(z2, path_r);
            g.append(g1);
        }

        if(hasGaps){
            Point p=GeoMath::Translation(_lastLine.p0, 0, 0, -z2);
            qreal b = (mgap.length+t.d)/(path_r);
            qreal ab = (2*M_PI)/mgap.n;

            Point p0,p1;
            qreal aa=0;

            for(int i=0;i<mgap.n;i++){
                Point k01{0,0,p.z},k11{0,0,p.z};
                GeoMath::Polar(_lastHoleP, p, aa+b, path_r, &k01);
                GeoMath::Polar(_lastHoleP, p, aa+ab, path_r, &k11);
                QString err2;

                auto q1=_lastArc.p0;
                auto q2=_lastArc.p1;
                auto q3=_lastArc.o;

                _lastArc.p0=k01;
                _lastArc.p1=k11;
                _lastArc.o=_lastHoleP;

                g.append(CircularArcCut(mgap.height));

                _lastArc.p0=q1;
                _lastArc.p1=q2;
                _lastArc.o=q3;

                aa+=ab;
            }
        }
    }

    g.append(TotalTimeToGCode());
    return g.join('\n');
}

auto GenerateGcode::ArcToGCode(const Arc& m ,QString* err) -> QString
{
    QString msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);
    zInfo(msg);

    /*POSITION*/
    if(m.p1==m.p0){
        if(err){*err=L("start and end points are equal");} return {};
    }
    if(m.p0==m.o){
        if(err){*err=L("start and origo are equal");} return {};
    }
    if(m.p1==m.o){
        if(err){*err=L("end pouint and origo are equal");} return {};
    }
    auto d01 = GeoMath::Distance(m.p0,m.p1);
    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){
        if(err){*err=L("no total cut depth");} return {};
    }
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return{};
    /*FEED*/
    SetSelectedFeed(m.feed);
    /*TOOL*/
    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = _tools[_selected_tool_ix];
    if(d01<t.d){
        if(err){*err=L("wrong length: ")+GCode::r(d01)+
                " tool: "+t.ToString();
        }
    }

    /**/
    if(m.p0.isValid()){
        _lastArc.p0=m.p0;
    }
    if(m.rp.isValid()){
        if(_lastArc.p0.isValid()){
            _lastArc.p0.x+=m.rp.x;
            _lastArc.p0.y+=m.rp.y;
            _lastArc.p0.z+=m.rp.z;
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }

    if(m.p1.isValid()){
        _lastArc.p1=m.p1;
    }
    if(m.rp.isValid()){
        if(_lastArc.p1.isValid()){
            _lastArc.p1.x+=m.rp.x;
            _lastArc.p1.y+=m.rp.y;
            _lastArc.p1.z+=m.rp.z;
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(m.o.isValid()){
        _lastArc.o=m.o;
    }
    if(m.rp.isValid()){
        if(_lastArc.o.isValid()){
            _lastArc.o.x+=m.rp.x;
            _lastArc.o.y+=m.rp.y;
            _lastArc.o.z+=m.rp.z;
        } else {
            if(err){*err=L("o not valid");}
            return {};
        }
    }

    if(_lastArc.p0==_lastArc.p1){
        if(err){*err=L("start and end points are equal");}
        return{};
    }

    auto distance = GeoMath::Distance(_lastArc.p0, _lastArc.p1);
    if(distance<t.d) {
        if(err){*err=L("arc line too short");}
        return {};
    }

    msg=G2+ m.p0.ToString()+' '+m.p1.ToString()+' '+m.o.ToString();

    msg+= " h:"+GCode::r(_last_cut.z);
    zInfo(msg);

    QStringList g(L("(arc)"));
    g.append(TotalTimeToGCode());

    auto g2 = CircularArcCut(_last_cut.z);
    g.append(g2);

    g.append(TotalTimeToGCode());
    return g.join('\n');
}
/*
//    g.append(TravelXYToGCode(m.p0));
//    g.append(LiftDownToGCode(m.p0.z));
//    Point p;//invalid!!!
//    GMode::Mode mode;
//    QString ij;
//    qreal i,j,i1,j1,i0,j0;
//    i1=m.o.x-m.p0.x;
//    j1=m.o.y-m.p0.y;

//    i0=m.o.x-m.p1.x;
//    j0=m.o.y-m.p1.y;

//    for(int step=0;step<steps;step++){
//        Point pp = p;
//        if(!(step%2))
//        {
//            p=m.p1;
//            mode = GMode::Circular;
//            i=i1;
//            j=j1;
//        }
//        else
//        {
//            p=m.p0;
//            mode = GMode::Circular_ccw;
//            i=i0;
//            j=j0;
//        }
//        QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
//        qreal z = p.z-(step+1)*_last_cut.z0;
//        qreal zz = p.z-_last_cut.z;
//        if(z<zz){
//            p.z = zz;
//        } else {
//            p.z = z;
//        }

//        qreal d=GeoMath::ArcLength(pp,p, m.o);
//        //qreal k1 = GeoMath::Distance(p,m.p)*2*M_PI;
//        //qreal k2 = GeoMath::Distance(p,pp);
//        //qreal l = qSqrt(d*d+k2*k2);
//        g.append(GoToXYZ(mode, p, d)+' '+ij2);
//    }
//    g.append(LiftUpToGCode(m.p0.z));

*/

/*BOX*/

auto GenerateGcode::BoxToGCode(const Box &m,QString*err) -> QString
{
    //_lasterr.clear();
    auto msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);
    zInfo(msg);
    msg = "(time: "+QString::number(_total_time)+")";
    zInfo(msg);

    /*BOXTYPE*/
    if(_lastBox.type==BoxType::Undefined && m.type==BoxType::Undefined){
        if(err)*err=L("no box type");
        return {};
    }
    if(m.type!=BoxType::Undefined) _lastBox.type = m.type;
    if(_lastBox.type==BoxType::Undefined) {
        if(err)*err=L("undefined box type");
        return {};
    }
    /*CORNER_DIAMETER*/
    if(_lastBox.type==BoxType::Corners){
        if(_last_hole_diameter==-1 && m.corner_diameter==-1){
            if(err){*err=L("no diameter");}
            return {};
        } else{
            if(m.corner_diameter!=-1) _last_hole_diameter=m.corner_diameter;
        }
    }
    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){if(err)*err=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return{};
    /*FEED*/
    SetSelectedFeed(m.feed);
    /*TOOL*/
    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = _tools[_selected_tool_ix];

    if(m.p0.isValid()){
        _lastBox.p0=m.p0;
    }
    if(m.rp.isValid()){
        if(_lastBox.p0.isValid()){
            _lastBox.p0.x+=m.rp.x;
            _lastBox.p0.y+=m.rp.y;
            _lastBox.p0.z+=m.rp.z;
        } else{
            if(err)*err=L("p0 not valid");
            return {};
        }
    }    
    if(m.p1.isValid()){        
        _lastBox.p1=m.p1;
    } else{
        if(m.size.isValid()){ // ha van m??ret megadva az az els??dleges
            _lastBox.p1=GeoMath::Translation(_lastBox.p0,m.size.width(), m.size.height());
        } else if(m.rp.isValid() && _lastBox.p1.isValid()){
            _lastBox.p1=GeoMath::Translation(_lastBox.p1,m.rp);
        }
    }


    if(GeoMath::Distance(_lastBox.p0, _lastBox.p1)<(t.d/1.4)) {
        if(err)*err=L("box line too short");
        return {};
    }



    /*rectangle normaliz??l??s*/
    auto zz = (_lastBox.p0.z+_lastBox.p1.z)/2;
    Point ba,jf,ja,bf;
    if(_lastBox.p0.x<_lastBox.p1.x){
        //p0b, p1j
        if(_lastBox.p0.y<_lastBox.p1.y){
            //p0ba, p1jf
            ba=_lastBox.p0;
            jf=_lastBox.p1;
            //1
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        } else{
            //p0bf, p1ja
            bf=_lastBox.p0;
            ja=_lastBox.p1;
            //2
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        }
    } else{
        //p0j, p1b
        if(_lastBox.p0.y<_lastBox.p1.y){
            //p0ja, p1bf
            ja=_lastBox.p0;
            bf=_lastBox.p1;
            //3
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        } else{
            //p0jf, p1ba
            jf=_lastBox.p0;
            ba=_lastBox.p1;
            //4
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        }
    }


    QStringList g(QStringLiteral("(box)"));
    g.append(TotalTimeToGCode());

    if(m.jointGap!=0){
        switch(_lastBox.type){
        case BoxType::Outline:
            ba.x+=m.jointGap;
            ba.y+=m.jointGap;
            jf.x-=m.jointGap;
            jf.y-=m.jointGap;
            break;
        case BoxType::Inline:
            ba.y-=m.jointGap;
            ba.x-=m.jointGap;
            jf.y+=m.jointGap;
            jf.x+=m.jointGap;
            break;
        default: break;
        }
    }

    if(jf.x-ba.x<t.d)
    {
        if(err)*err=L("box w is too small");
        return {};
    }

    if(jf.y-ba.y<t.d)
    {
        if(err)*err=L("box h is too small");
        return {};
    }

    /*szersz??mp??lya*/
    qreal tool_r = t.d/2;

    Point bao=ba, jfo=jf;
    switch(_lastBox.type){
    case BoxType::Outline:
        ba.x-=tool_r;
        ba.y-=tool_r;
        jf.x+=tool_r;
        jf.y+=tool_r;

        //
        ja.x=jf.x;
        ja.y=ba.y;
        bf.x=ba.x;
        bf.y=jf.y;
        break;
    case BoxType::Inline:
        ba.y+=tool_r;
        ba.x+=tool_r;
        jf.y-=tool_r;        
        jf.x-=tool_r;        
        //
        ja.x=jf.x;
        ja.y=ba.y;
        bf.x=ba.x;
        bf.y=jf.y;
        break;
    default: break;
    }

    Point ba1 = ba;
    Point ja1 = ja;
    Point ja2 = ja;
    Point jf2 = jf;
    Point jf3 = jf;
    Point bf3 = bf;
    Point bf4 = bf;
    Point ba4 = ba;

    switch(_lastBox.type){
    case BoxType::Outline:
        ba1.x=bf3.x=bao.x;
        ja1.x=jf3.x=jfo.x;
        ja2.y=ba4.y=bao.y;
        jf2.y=bf4.y=jfo.y;
        break;
    case BoxType::Inline:
        ba1.x=bf3.x=ba.x;
        ja1.x=jf3.x=jf.x;
        ja2.y=ba4.y=ba.y;
        jf2.y=bf4.y=jf.y;
        break;
    default: break;
    }

    msg=G2+ ba.ToString()+' '+jf.ToString();
    msg+=' '+BoxType::ToString(_lastBox.type);
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();
    msg+=" d"+GCode::r(_last_hole_diameter);
    msg+=' '+m.gap.ToString();

    zInfo(msg);

    if(_lastBox.type == BoxType::Corners){

        QVarLengthArray<Hole> holes = {
            {ba, _last_hole_diameter, _last_cut, _last_feed, {},0},
            {ja, _last_hole_diameter, _last_cut, _last_feed, {},0},
            {jf, _last_hole_diameter, _last_cut, _last_feed, {},0},
            {bf, _last_hole_diameter, _last_cut, _last_feed, {},0}
        };
        if(_verbose){
            for(int i=0;i<holes.length();i++){
                auto&l=holes[i];
                //g.append('('+l.ToString()+')');
                zInfo('h'+QString::number(i)+':'+l.ToString());
            }
        }
        for(auto&h:holes){
            auto gl = HoleToGCode(h,err);
            if(!gl.isEmpty()){
                g.append(gl);
            } else{
                zInfo("err: "+(err?*err:QString()));
            }
        }
    } else {        
        // lemegy egyben a gapig
//        bool hasGaps = m.gap.isValid() && m.gap.n>0;
//        qreal z2 = hasGaps?m.cut.z-m.gap.height:m.cut.z;
//        Cut cut_border{z2, m.cut.z0};
        bool hasGaps = m.gap.isValid() && m.gap.n>0;
        qreal z2 = hasGaps?_last_cut.z-m.gap.height:_last_cut.z;
        QVarLengthArray<Line> lines_border;
        Cut cut_border;//{z2, _last_cut.z0};
        if(z2>0){
            cut_border = {z2, _last_cut.z0};

            lines_border= {
                {ba1,ja1, cut_border, _last_feed,{}},
                {ja2,jf2, cut_border, _last_feed,{}},
                {jf3,bf3, cut_border, _last_feed,{}},
                {bf4,ba4, cut_border, _last_feed,{}}};
            }

        QVarLengthArray<Line> lines_gap;
        if(hasGaps){
            //gap layer
            ba.z-=z2;
            bf.z-=z2;
            ja.z-=z2;
            jf.z-=z2;

            ba1.z-=z2;
            ja1.z-=z2;
            ja2.z-=z2;
            jf2.z-=z2;
            jf3.z-=z2;
            bf3.z-=z2;
            bf4.z-=z2;
            ba4.z-=z2;

            auto cz0 = m.gap.height<_last_cut.z0?m.gap.height:_last_cut.z0;
            Cut cut_gap{m.gap.height,  cz0};

            lines_gap = {
                {ba1,ja1, cut_gap, _last_feed,{}},
                {ja2,jf2, cut_gap, _last_feed,{}},
                {jf3,bf3, cut_gap, _last_feed,{}},
                {bf4,ba4, cut_gap, _last_feed,{}}
            };
        }
        zInfo(L("(segments)"));
        QList<Line> segments;

        for(int i=0;i<4;i++){
            if(m.nl[i]==0) continue;
            if(lines_border.length()>i){
                auto&l_border=lines_border[i];
                //if(cut_border.z>0){ segments.append(l_border);}
                segments.append(l_border);
            }
            if(hasGaps){
                auto&l_gap=lines_gap[i];
                auto s = l_gap.Divide(m.gap, t.d);
                if(s.isEmpty()){
                    zInfo(QStringLiteral("cannot divide line"));
                    segments.append(l_gap);
                }else{
                    segments.append(s);
                }
            }
        }

//        if(_verbose){
//            for(int i=0;i<segments.length();i++){
//                auto&l=segments[i];
//                g.append('('+l.ToString()+')');
//                zInfo('l'+QString::number(i)+':'+l.ToString());
//            }
//        }

        for(auto&bl:segments){
            auto px0 = _lastLine.p0;
            auto px1 = _lastLine.p1;
            g.append(LineToGCode(bl,err));
            _lastLine.p0 = px0; // azonnal vissza is ??ll??tjuk
            _lastLine.p1 = px1;
        }

    }
    g.append(TotalTimeToGCode());
    return g.join('\n');
}

auto GenerateGcode::SetToolToGCode(Tool m, QString *err) -> QString
{
    Q_UNUSED(err)
//    QString msg = G1+m.ToString();
//    StringHelper::Tabulate(&msg, G2);
//    zInfo(msg);
    //_lasterr.clear();
    //if(!txt.startsWith(Tool::key)) return QString();
    //Tool m;
    //auto state = Tool::Parse(txt, &m);
    if(m.ix==-1) return {};
    QString g;

    if(_tools.contains(m.ix)){ // ha van m??r ilyen tool
        if(m.type==Tool::None){ //selectelni akarjuk
            _selected_tool_ix = m.ix;
            //g = 't'+QString::number(_selected_tool_ix)+"(change tool)";
            g=ChangeToolToGCode();
        }
    }else{
        if(m.type!=Tool::None){ // be??ll??tani akarjuk
            _tools.insert(m.ix, m); // ha nincs m??g ilyen tool
            //_selected_tool_ix = m.ix;
            g = "(set tool "+QString::number(m.ix)+" to "+m.ToString()+')';
            zInfo("tool "+QString::number(m.ix)+':'+m.ToString());
        }
    }
    return g;
}


auto GenerateGcode::SetFeedToGCode(QString* err) ->QString
{
    Q_UNUSED(err)
    if(_selected_feed.feed()<=0) return {};
    if(_last_feed.feed() == _selected_feed.feed()){
        return {};
    }
    _last_feed.setFeed(_selected_feed.feed());
    return _selected_feed.ToStringFeed()+" (set feed)";
}

auto GenerateGcode::SetSpindleSpeedToGCode(QString* err) ->QString
{
    Q_UNUSED(err)
    if(_selected_feed.spindleSpeed()<=0) return {};
    if(_last_feed.spindleSpeed() == _selected_feed.spindleSpeed()){
        return {};
    }
    _last_feed.setSpindleSpeed(_selected_feed.spindleSpeed());
    return _selected_feed.ToStringSpindleSpeed()+" (set spindle speed)";
}

auto GenerateGcode::SetXYModeToGCode() ->QString
{
    return L("(set mode to ")+_XYMode.ToString()+')';
}

auto GenerateGcode::ChangeToolToGCode() ->QString
{
    if(_selected_tool_ix==-1){
        zInfo(QStringLiteral("no tool selected"));
        return {};
    }
    if(!_tools.contains(_selected_tool_ix)) {
        zInfo(QStringLiteral("tool not found: ")+QString::number(_selected_tool_ix));
        return {};
    }
    if(_last_tool_ix == _selected_tool_ix){
        zInfo(QStringLiteral("tool not changed"));
        return {};
    }

    Tool t = _tools[_selected_tool_ix];

    QStringList g;

    g.append(QStringLiteral("(change tool)"));
    g.append(SpindleStopToGCode());//spindle stop
    g.append(TravelXYToGCode(_safe_place));
    //g.append(TravelXYToGCode({0,0,0}));//ki??ll null??ra
    g.append(QStringLiteral("g0 z")+GCode::r(_maxZ));
    g.append('t'+QString::number(t.ix)+" (tool select)");
    g.append(QStringLiteral("m6 (tool change)"));
    g.append(QStringLiteral("(msg, change tool to ")+Tool::TypeToString(t.type)+
             ", diameter="+GCode::r(t.d)+')');
    g.append(QStringLiteral("m0 (machine stop)"));
    g.append(QStringLiteral("g0 z")+GCode::r(_maxZ));

    _last_tool_ix=_selected_tool_ix;

    return g.join('\n');
}

auto GenerateGcode::SpindleStartToGCode() ->QString
{
    auto const M3 = QStringLiteral("m3");
    if(_selected_feed.spindleSpeed()<=0) return {};
    auto sp = SetSpindleSpeedToGCode();
    return (sp.isEmpty()?M3:M3+' '+sp)+"(spindle start)";
}

auto GenerateGcode::SpindleStopToGCode() ->QString
{
    //_selected_feed.spindleSpeed=0;
    return QStringLiteral("m5 (spindle stop)");    
}

/*Move*/
auto GenerateGcode::GoToZ(GMode::Mode i, const Point& p, qreal length) -> QString
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }
    if(i==GMode::Undefined){ return {};}

    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        _last_gmode==i &&
        _last_position.z==p.z){return {};}

    qreal v = 0;


    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){
        if(_last_feed.feed()<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo(Messages::zero_spindleSpeed);
            // return {};
        }
    }
    else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position.z = p.z;
    _last_gmode=i;

    if(length>0){
        _total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{            
            _total_time+=length/v;
        }
    } else {
        zInfo(Messages::zero_spindleSpeed)
    }

    return GMode::ToGCcode(i)+' '+p.ToStringZ();
}

auto GenerateGcode::GoToXY(GMode::Mode i, const Point& p, qreal length) -> QString
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }
    if(i==GMode::Undefined){ return {};}

    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        _last_gmode==i &&
        _last_position.x==p.x &&
        _last_position.y==p.y){return {};}

    qreal v = 0;

    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){
        if(_last_feed.feed()<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo(Messages::zero_spindleSpeed);
           // return {};
        }
    }
    else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position.x = p.x;
    _last_position.y = p.y;
    _last_gmode=i;


    if(length>0){
        _total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{
            _total_time+=length/v;
        }
    } else {
        zInfo(Messages::no_calc_length)
    }

    QString a = (_ratio>0&&_ratio!=1)?p.ToStringXY(_ratio):p.ToStringXY();
    //QString a = p.ToStringXY();
    return GMode::ToGCcode(i)+' '+a;
}

auto GenerateGcode::Dwell(int p) -> QString
{
    _total_time+=p/1000;
    auto str =  "G04 P"+QString::number(p);
    //QString str;
    return str;
}

auto GenerateGcode::GoToXYZ(GMode::Mode i, const Point& p, qreal length) -> QString
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }
    if(i==GMode::Undefined){ return {};}
    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        _last_gmode==i && _last_position==p){return {};}

    qreal v = 0;
    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){

        if(_last_feed.feed()<=0){
            zInfo(Messages::zero_feed);
            //return {};
        } else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo(Messages::zero_spindleSpeed);
            // return {};
        }
    } else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position = p;
    _last_gmode=i;

    if(length>0){
        _total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{
            _total_time+=length/v;
        }
    } else {
        zInfo(Messages::no_calc_length)
    }

    QString a = (_ratio>0&&_ratio!=1)?p.ToStringXYZ(_ratio):p.ToStringXYZ();

    return GMode::ToGCcode(i)+' '+a;
}
