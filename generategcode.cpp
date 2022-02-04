#include "common/logger/log.h"
#include "generategcode.h"
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

const QString GenerateGcode::G1 = L("G:");
const QString GenerateGcode::G2 = L("    ->");
const QString GenerateGcode::T1 = L("T:");

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{
    gcodes.clear();

    _XYMode=XYMode::XY;
    _tools.clear();

    _selected_tool_ix = -1;
    _selected_feed ={};
    _selected_cut ={};

    _last_tool_ix=-1;
    _last_feed ={};
    _last_cut = {};
    _lastHoleP={};
    _last_hole_diameter =-1;    
    _lastLineP0={};
    _lastLineP1={};
    _lastBoxP0={};
    _lastBoxP1={};
    _lastBoxType=BoxType::Undefined;
    _last_position = {};
    _last_gmode=GMode::Undefined;

    _total_time=0;
    _total_length=0;
    _total_cut=0;

    GCode::_variables.Clear();
    _lastBoxType = BoxType::Undefined;

    for(auto l:g){
        QString err;
        QString gcode;

        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        if(l.startsWith('#')) continue;
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
        if(XYMode::ValidateLineType(l)){
            if(ParseSetXYModeToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
        }
        switch(l[0].unicode()){
        case Comment::keyUniCode:
            if(ParseCommentToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        //case XYMode::keyUniCode1:
        //case XYMode::keyUniCode2:setXYMode(l);break;
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
        case Feed::keyUniCode_feed:
            if(ParseSetFeedToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Feed::keyUniCode_spindleSpeed:
            if(ParseSetSpindleSpeedToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        case Box::keyUniCode:
            if(ParseBoxToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        }
    }


    return gcodes;
}

auto GenerateGcode::ParseArcToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Arc m;
    auto state = Arc::Parse(str, _XYMode, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed ) // ha Arc típusú sor
    {
        zInfo(T1+str)
        if(gcode)*gcode=ArcToGCode(m,err);
    }
    return true;
}

auto  GenerateGcode::ParseLineToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Line m;
    auto state = Line::Parse(str, _XYMode, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed ) // ha Arc típusú sor
    {
        zInfo(T1+str)
        if(gcode)*gcode=LineToGCode(m,err);
    }
    return true;
}

auto GenerateGcode::ParseHoleToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Hole m;
    auto state = Hole::Parse(str, _XYMode, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed ) // ha Arc típusú sor
    {
        zInfo(T1+str);
        if(gcode)*gcode=HoleToGCode(m,err);
    }
    return true;
}

auto GenerateGcode::ParseBoxToGcode(const QString& str, QString *gcode, QString *err) -> bool
{
    Box m;
    auto state = Box::Parse(str, _XYMode, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed ) // ha Arc típusú sor
    {
        zInfo(T1+str)
        if(gcode)*gcode=BoxToGCode(m,err);
    }
    return true;
}

auto GenerateGcode::ParseCommentToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    Comment m;
    auto state = Comment::Parse(str, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        if(gcode)*gcode=m.text;
    }
    return true;
}

auto GenerateGcode::ParseStringToGCode(const QString& str, QString *gcode, QString *err)-> bool
{
    Q_UNUSED(err)
    String m;
    auto state = String::Parse(str, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        if(gcode)*gcode=m.ToString();
    }
    return true;
}

auto GenerateGcode::ParseSetToolToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    Tool m;
    auto state = Tool::Parse(str, &m);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        if(gcode)*gcode=SetToolToGCode(m, err);
    }
    return true;
}

auto GenerateGcode::ParseSetFeedToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    //Feed m;
    auto state = _selected_feed.ParseIntoFeed(str);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        //_selected_feed.f=m.f;
        if(gcode)*gcode=SetFeedToGCode(err);
    }
    return true;
}

auto GenerateGcode::ParseSetSpindleSpeedToGCode(const QString& str, QString *gcode, QString *err) -> bool
{
    //Feed m;
    auto state = _selected_feed.ParseIntoSpindleSpeed(str);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        //_selected_feed.spindleSpeed=m.spindleSpeed;
        if(gcode)*gcode=SetSpindleSpeedToGCode(err);
    }
    return true;
}

auto GenerateGcode::ParseSetXYModeToGcode(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    //Feed m;
    auto state = XYMode::Parse(str, &_XYMode);
    if(state==ParseState::NoData) return false;
    if(state == ParseState::Parsed )
    {
        zInfo(T1+str)
        //_selected_feed.f=m.f;
        if(gcode)*gcode=SetXYModeToGCode();
    }
    return true;
}


// todo 10 arc: a p0,p1,po
// todo 11 circle: c - mint a hole, csak nincs belül kimarva - a gaps eset
// todo 12 o: forgatás minden elemre - o középpont, és szög

auto GenerateGcode::AppendGCode(QStringList* gs, const QString &g, const QString& err) -> bool
{
    if(!gs) return false;
    if(!g.isEmpty())gs->append(g);
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
        auto gcode = GoToZ(GMode::Linear,{0,0,z0}, l)+ " (pull)";
        AppendGCode(&g, gcode, err);
    }
    qreal l = _movZ-_last_position.z;
    auto gcode = GoToZ(GMode::Rapid,{0,0,_movZ}, l) + "(lift up)";
    AppendGCode(&g, gcode, err);
    return g.join('\n');
}

auto GenerateGcode::LiftDownToGCode(qreal z)-> QString
{
    QStringList g;
    QString err;

    if(_last_position.z==z){ return {};}
    auto z2 = z+1;
    qreal l = _last_position.z-z2;
    auto gcode = GoToZ(GMode::Rapid,{0,0,z2},l)+ " (lift down)";
    AppendGCode(&g, gcode, err);
    l = _last_position.z-z;
    gcode = GoToZ(GMode::Linear,{0,0,z}, l)+ " (push)";
    AppendGCode(&g, gcode, err);

    return g.join('\n');
}

auto GenerateGcode::TravelXYToGCode(const Point& p) -> QString
{
    QStringList g;

    g.append(LiftUpToGCode());
    qreal l = GeoMath::Distance(_last_position, p);
    g.append(GoToXY(GMode::Rapid, p, l)+" (travel)");

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

void GenerateGcode::SetSelectedFeed(const Feed& feed){
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
        _lastLineP0=m.p0;
    }
    if(m.rp.isValid()){
        if(_lastLineP0.isValid()){
            _lastLineP0.x+=m.rp.x;
            _lastLineP0.y+=m.rp.y;
            _lastLineP0.z+=m.rp.z;
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }
    if(m.p1.isValid()){
        _lastLineP1=m.p1;
    }
    if(m.rp.isValid()){
        if(_lastLineP1.isValid()){
            _lastLineP1.x+=m.rp.x;
            _lastLineP1.y+=m.rp.y;
            _lastLineP1.z+=m.rp.z;
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(GeoMath::Distance(_lastLineP0, _lastLineP1)<t.d) {
        if(err){*err=L("line too short");}
        return {};
    }

    //zInfo(G2+_last_cut.ToString()+_last_feed.ToString());
    QStringList g(QStringLiteral("(line)"));
    Point p = _lastLineP0;

    msg=G2+ _lastLineP0.ToString()+' '+_lastLineP1.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();
    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);

    g.append(TravelXYToGCode(p));

    auto sp = SpindleStartToGCode();
    if(!sp.isEmpty()) g.append(sp);
    //_selected_feed
    auto f = SetFeedToGCode();
    if(!f.isEmpty()) g.append(f);

    g.append(LiftDownToGCode(p.z));

    //int steps = qCeil(m.cut.z/m.cut.z0)+1;
    //QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){
        Point pd=p;
        if(!(i%2))
        {
            p=_lastLineP1;
        }
        else
        {
            p=_lastLineP0;
        }

//        qreal z = p.z-(i+1)*m.cut.z0;
//        if(z<p.z-m.cut.z) p.z = p.z-m.cut.z; else p.z = z;

        qreal z = p.z-(i+1)*_last_cut.z0;
        qreal zz = p.z-_last_cut.z;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal d=GeoMath::Distance(pd,p);
        g.append(GoToXYZ(GMode::Linear, p, d));
    }

    g.append(LiftUpToGCode(p.z));
    zInfo(msg);
    return g.join('\n');
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
// todo 11 a line két pont nem lehet azonos, box, arc
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
    if(_last_hole_diameter<t.d) {
        if(err){*err=L("wrong diameter: ")+GCode::r(_last_hole_diameter)+
                " tool: "+t.ToString();
        }
        return {};
    }

    double path_r = (_last_hole_diameter-t.d)/2; // a furat belső szélét érintő pályapont
    Gap mgap;

    bool pre_drill, pre_mill,hasGaps, drillOnly=m.diameter==t.d;
    if(drillOnly){
        pre_drill=true;
        pre_mill=false;
        hasGaps = false;
    } else{
        hasGaps = _last_hole_diameter>5*t.d; //
        if(hasGaps){
            pre_drill=false;
            pre_mill=false;
            int gapn = (2*path_r*M_PI)/(2*t.d+m.gap.length); // hány gap fér ki
            if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
            if(m.gap.n>gapn) { gapn=m.gap.n;}
            mgap = {(m.gap.n>gapn)?gapn:m.gap.n,// ha többet kért, mint ami kifér
                    m.gap.length,m.gap.height};

        } else {
            pre_drill = _last_hole_diameter>2*t.d; //d=0
            pre_mill = _last_hole_diameter>3*t.d; //d=2*t.d
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

    Point p = _lastHoleP; // _lastHoleP középpont , p a szerszámpálya kezdőpontja lesz

    msg=G2+ p.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_selected_feed.ToString();
    msg+=" d"+GCode::r(_last_hole_diameter);
    if(pre_drill) msg+=L(" predrill");
    if(pre_mill) msg+=L(" premill");
    if(hasGaps) msg+=L(" gap");
    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);

    if(pre_drill){
        // 81: depth<3-5*t.d;
        // normal: 5*t.d
        // 83 peck:5-7
        // ha hőre lágyul az anyag, homlokmarónál előfúrásnál kellhet a peck
        //bool is_peck = t.type==Tool::Milling&&_last_cut.z>3;
        qreal zz = _lastHoleP.z-_last_cut.z;

       g.append(L("(predrill)"));
       g.append(TravelXYToGCode(p)); //TRAVEL
       auto sp = SpindleStartToGCode(); // selected->last
       if(!sp.isEmpty()) g.append(sp);
       auto f = SetFeedToGCode();
       if(!f.isEmpty()) g.append(f);
       //g.append(LiftDown(p.z));
       g.append(L("G98 G81")+" z"+GCode::r(zz)+" r"+GCode::r(p.z));
       if(_last_feed.feed()>0){
           qreal l0 = _last_position.z-zz;
           qreal l1 = p.z-zz;

           _total_time+=l1/_last_feed.feed()+l0/1500;
       }

       _last_position.z = p.z;
    }
    if(!drillOnly){
        if(pre_mill){
            Point pm = p;
            pm.x -= t.d;
            g.append(L("(premill)"));
            g.append(TravelXYToGCode(pm));
            g.append(LiftDownToGCode(pm.z));

            auto sp = SpindleStartToGCode();
            if(!sp.isEmpty()) g.append(sp);
            auto f = SetFeedToGCode();
            if(!f.isEmpty()) g.append(f);

            for(int i=0;i<steps;i++){
                Point pp=p;
                qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kiszámol
                qreal zz = _lastHoleP.z-_last_cut.z;
                if(z<zz){    //beállítjuk a p-t
                    pm.z = zz;
                } else {
                    pm.z = z;
                }

                qreal l = path_r*2*M_PI;
                qreal lz = pp.z-p.z;
                qreal l1 = qSqrt(l*l+lz*lz);
                g.append(GoToZ(GMode::Circular, pm, l1)+" i"+GCode::r(t.d));
            }
            //g.append(LiftUp(p.z));
        }

        p.x -= path_r; //szerszámpálya kezdő pontja
        qreal z2 = hasGaps?_last_cut.z-mgap.height:_last_cut.z;

        if(z2>0){
            g.append(TravelXYToGCode(p));
            auto sp = SpindleStartToGCode();
            if(!sp.isEmpty()) g.append(sp);
            auto f = SetFeedToGCode();
            if(!f.isEmpty()) g.append(f);
            g.append(LiftDownToGCode(p.z));

            steps = qCeil(z2/_last_cut.z0)+1;
            for(int i=0;i<steps;i++){
                Point pp=p;
                qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kiszámol
                qreal zz = _lastHoleP.z-z2;//_last_cut.z;
                if(z<zz){    //beállítjuk a p-t
                    p.z = zz;
                } else {
                    p.z = z;
                }

                qreal l = path_r*2*M_PI;
                qreal lz = pp.z-p.z;
                qreal l1 = qSqrt(l*l+lz*lz);
                g.append(GoToZ(GMode::Circular,p, l1)+" i"+GCode::r(path_r));
            }
            g.append(LiftUpToGCode(_lastHoleP.z));  //ahol bement, ott ki is jön
        }


        if(hasGaps){
            qreal b = (mgap.length+t.d)/(4*path_r);
            qreal ab = (2*M_PI)/mgap.n;

            Point p0,p1;
            //qreal r = path_r;
            qreal aa=0;
            for(int i=0;i<mgap.n;i++){

                Point k01{0,0,p.z},k11{0,0,p.z};
                GeoMath::Polar(_lastHoleP, p, aa+b, path_r, &k01);
                GeoMath::Polar(_lastHoleP, p, aa+ab, path_r, &k11);
//                k01.z=p.z;
//                k11.z=p.z;
                QString err2;

                g.append(ArcToGCode(
                    {k01, k11, _lastHoleP,
                     {mgap.height,_last_cut.z0},//cut
                     _last_feed//feed
                    }, &err2));
                aa+=ab;
            }
        }
    }
    zInfo(msg);
    return g.join('\n');
}
// todo ha már fent van a szerszám a travelZ-n akkor felesleges liftelni
// ha a pozíció már az xy akkor nem kell travelezni
// ha már le van engedve, nem kell leengedni


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

    msg=G2+ m.p0.ToString()+' '+m.p1.ToString()+' '+m.o.ToString();

    msg+= " h:"+GCode::r(m.cut.z);
    int steps = qCeil(m.cut.z/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);

    QStringList g(L("(arc begin)"));

    g.append(TravelXYToGCode(m.p0));
    g.append(LiftDownToGCode(m.p0.z));
    Point p;//invalid!!!
    GMode::Mode mode;
    QString ij;
    qreal i,j,i1,j1,i0,j0;
    i1=m.o.x-m.p0.x;
    j1=m.o.y-m.p0.y;

    i0=m.o.x-m.p1.x;
    j0=m.o.y-m.p1.y;

    for(int step=0;step<steps;step++){
        Point pp = p;
        if(!(step%2))
        {
            p=m.p1;
            mode = GMode::Circular;            
            i=i1;
            j=j1;
        }
        else
        {
            p=m.p0;
            mode = GMode::Circular_ccw;            
            i=i0;
            j=j0;
        }
        QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
        qreal z = p.z-(step+1)*_last_cut.z0;
        qreal zz = p.z-m.cut.z;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal d=GeoMath::ArcLength(pp,p, m.o);
        //qreal k1 = GeoMath::Distance(p,m.p)*2*M_PI;
        //qreal k2 = GeoMath::Distance(p,pp);
        //qreal l = qSqrt(d*d+k2*k2);
        g.append(GoToXYZ(mode, p, d)+' '+ij2);
    }
    g.append(LiftUpToGCode(m.p0.z));

    zInfo(msg);
    return g.join('\n');
}


/*BOX*/

auto GenerateGcode::BoxToGCode(const Box &m,QString*err) -> QString
{
    //_lasterr.clear();
    auto msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);
    zInfo(msg);

    /*BOXTYPE*/
    if(_lastBoxType==BoxType::Undefined && m.type==BoxType::Undefined){
        if(err)*err=L("no box type");
        return {};
    }
    if(m.type!=BoxType::Undefined) _lastBoxType = m.type;
    if(_lastBoxType==BoxType::Undefined) {
        if(err)*err=L("undefined box type");
        return {};
    }
    /*CORNER_DIAMETER*/
    if(_lastBoxType==BoxType::Corners){
        if(_last_hole_diameter==-1 && m.corner_diameter==-1){
            if(err){*err=L("no diameter");}
            return {};
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
        _lastBoxP0=m.p0;
    }
    if(m.rp.isValid()){
        if(_lastBoxP0.isValid()){
            _lastBoxP0.x+=m.rp.x;
            _lastBoxP0.y+=m.rp.y;
            _lastBoxP0.z+=m.rp.z;
        } else{
            if(err)*err=L("p0 not valid");
            return {};
        }
    }
    if(m.p1.isValid()){
        _lastBoxP1=m.p1;
    }
    if(m.rp.isValid()){
        if(_lastBoxP1.isValid()){
            _lastBoxP1.x+=m.rp.x;
            _lastBoxP1.y+=m.rp.y;
            _lastBoxP1.z+=m.rp.z;
        } else{
            if(err)*err=L("p1 not valid");
            return {};
        }
    }

    if(GeoMath::Distance(_lastBoxP0, _lastBoxP1)<(t.d/1.4)) {
        if(err)*err=L("line too short");
        return {};
    }

    /*rectangle normalizálás*/
    auto zz = (_lastBoxP0.z+_lastBoxP1.z)/2;
    Point ba,jf,ja,bf;
    if(_lastBoxP0.x<_lastBoxP1.x){
        //p0b, p1j
        if(_lastBoxP0.y<_lastBoxP1.y){
            //p0ba, p1jf
            ba=_lastBoxP0;
            jf=_lastBoxP1;
            //1
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        } else{
            //p0bf, p1ja
            bf=_lastBoxP0;
            ja=_lastBoxP1;
            //2
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        }
    } else{
        //p0j, p1b
        if(_lastBoxP0.y<_lastBoxP1.y){
            //p0ja, p1bf
            ja=_lastBoxP0;
            bf=_lastBoxP1;
            //3
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        } else{
            //p0jf, p1ba
            jf=_lastBoxP0;
            ba=_lastBoxP1;
            //4
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        }
    }

    QStringList g(QStringLiteral("(box with gaps)"));

    /*szerszámpálya*/
    qreal tool_r = t.d/2;

    Point bao=ba, jfo=jf;
    switch(_lastBoxType){
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

    ba1.x=bf3.x=bao.x;
    ja1.x=jf3.x=jfo.x;

    ja2.y=ba4.y=bao.y;
    jf2.y=bf4.y=jfo.y;

    msg=G2+ ba.ToString()+' '+jf.ToString();
    msg+=' '+BoxType::ToString(_lastBoxType);
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();

    if(_lastBoxType == BoxType::Corners){
        msg+=" d"+GCode::r(_last_hole_diameter);
        QVarLengthArray<Hole> holes = {
            {ba, _last_hole_diameter, _last_cut, _last_feed, {}},
            {ja, _last_hole_diameter, _last_cut, _last_feed, {}},
            {jf, _last_hole_diameter, _last_cut, _last_feed,{}},
            {bf, _last_hole_diameter, _last_cut, _last_feed, {}}
        };
        if(_verbose){
            for(int i=0;i<holes.length();i++){
                auto&l=holes[i];
                g.append('('+l.ToString()+')');
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
                {ba1,ja1, cut_border, _last_feed},
                {ja2,jf2, cut_border, _last_feed},
                {jf3,bf3, cut_border, _last_feed},
                {bf4,ba4, cut_border, _last_feed}};
            }

        QVarLengthArray<Line> lines_gap;
        if(hasGaps){
            msg+=' '+m.gap.ToString();
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

            Cut cut_gap{m.gap.height, _last_cut.z0};

            lines_gap = {
                {ba1,ja1, cut_gap, _last_feed},
                {ja2,jf2, cut_gap, _last_feed},
                {jf3,bf3, cut_gap, _last_feed},
                {bf4,ba4, cut_gap, _last_feed}
            };
        }
        zInfo(L("(segments)"));
        QList<Line> segments;

        for(int i=0;i<4;i++){
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

        if(_verbose){
            for(int i=0;i<segments.length();i++){
                auto&l=segments[i];
                g.append('('+l.ToString()+')');
                zInfo('l'+QString::number(i)+':'+l.ToString());
            }
        }

        for(auto&bl:segments){
            auto px0 = _lastLineP0;
            auto px1 = _lastLineP1;
            g.append(LineToGCode(bl,err));
            _lastLineP0 = px0; // azonnal vissza is állítjuk
            _lastLineP1 = px1;
        }

    }
    zInfo(msg);
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

    if(_tools.contains(m.ix)){ // ha van már ilyen tool
        if(m.type==Tool::None){ //selectelni akarjuk
            _selected_tool_ix = m.ix;
            //g = 't'+QString::number(_selected_tool_ix)+"(change tool)";
            g=ChangeToolToGCode();
        }
    }else{
        if(m.type!=Tool::None){ // beállítani akarjuk
            _tools.insert(m.ix, m); // ha nincs még ilyen tool
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
    g.append(TravelXYToGCode({0,0,0}));//kiáll nullára
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
        zInfo("invalid point");
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
            zInfo("cutting movement with zero feed");
            //return {};
        }
        else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo("cutting movement with zero spindleSpeed");
            // return {};
        }
    }
    else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position.z = p.z;
    _last_gmode=i;

    if(length>0){
        if(_last_feed.feed()<=0){
            zInfo("no feed")
        } else{
            _total_length+=length;
            _total_time+=length/v;
        }
    } else {
        zInfo("no calculated movement length")
    }

    return GMode::ToGCcode(i)+' '+p.ToStringZ();
}

auto GenerateGcode::GoToXY(GMode::Mode i, const Point& p, qreal length) -> QString
{
    if(!p.isValid()){
        zInfo("invalid point");
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
            zInfo("cutting movement with zero feed");
            //return {};
        }
        else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo("cutting movement with zero spindleSpeed");
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
        if(_last_feed.feed()<=0){
            zInfo("no feed")
        } else{
            _total_length+=length;
            _total_time+=length/v;
        }
    } else {
        zInfo("no calculated movement length")
    }

    return GMode::ToGCcode(i)+' '+p.ToStringXY();
}

auto GenerateGcode::GoToXYZ(GMode::Mode i, const Point& p, qreal length) -> QString
{
    if(!p.isValid()){
        zInfo("invalid point");
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
            zInfo("cutting movement with zero feed");
            //return {};
        } else{
            v = _last_feed.feed();
            _total_cut+=length;
        }
        if(_last_feed.spindleSpeed()<=0){
            zInfo("cutting movement with zero spindleSpeed");
            // return {};
        }
    } else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position = p;
    _last_gmode=i;

    if(length>0){
        if(_last_feed.feed()<=0){
            zInfo("no feed")
        } else{
            _total_length+=length;
            _total_time+=length/v;
        }
    } else {
        zInfo("no calculated movement length")
    }

    return GMode::ToGCcode(i)+' '+p.ToStringXYZ();
}
