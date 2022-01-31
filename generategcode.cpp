#include "common/logger/log.h"
#include "generategcode.h"
#include <QtMath>
#include <QString>
#include "gcode/gcode.h"
#include "gcode/variable.h"
#include "gcode/string.h"

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{
    gcodes.clear();
    _tools.clear();
    _selected_tool_ix = -1;
    _last_tool_ix=-1;
    _last_hole_diameter =-1;
    _last_cut.z = -1;
    _last_cut.z0 = -1;
    GCode::_variables.Clear();

    for(auto l:g){
        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        if(l.startsWith('#')) continue;
        if(GCode::_variables.Parse(l)) continue;
        if(AppendGcode(GeneratePrintString(l))) continue;
        switch(l[0].unicode()){            
            case u'(':AppendGcode(GenerateComment(l));break;
            case u'y':
            case u'x':setXYMode(l);break;
            case u'l':AppendGcode(GenerateLineHorizontal(l));break;
            case u'h':AppendGcode(GenerateHole(l));break;
            case u't':AppendGcode(SetTool(l));break;
            case u'f':AppendGcode(SetFeedRate(l));break;
            case u's':AppendGcode(SetSpindleSpeed(l));break;
            case u'b':AppendGcode(GenerateBox(l));break;
        }
    }
    return gcodes;
}

auto GenerateGcode::AppendGcode(const QString &g) -> bool
{
    if(g.isEmpty()){
        if(!_lasterr.isEmpty()) {
            zInfo(_lasterr)
        }
        return false;
    }
    gcodes.append(g);
    return true;
}

auto GenerateGcode::setXYMode(const QString &txt) -> bool
{
    if(txt==QStringLiteral("xyz")){ _XYMode=XY; return true;}
    if(txt==QStringLiteral("yxz")){_XYMode=YX; return true;}
    return false;
}



auto GenerateGcode::ParsePoint(const QString &txt) -> Point
{
    return Point::Parse(txt, _XYMode);
}

auto GenerateGcode::ParseLine(const QString &txt) -> Line
{
    return Line::Parse(txt, _XYMode);
}


auto GenerateGcode::ParseBox(const QString &txt) -> Box
{
    return Box::Parse(txt, _XYMode);
}

auto GenerateGcode::ParseHole(const QString &txt) -> Hole
{
    return Hole::Parse(txt, _XYMode);
}

/**/

auto GenerateGcode::GenerateComment(const QString &txt) -> QString
{    
    if(!txt.startsWith('(')) return QString();
    zInfo("G:"+txt);
    if(!txt.endsWith(')')) return txt+')';
    return txt;
}

auto GenerateGcode::LiftUp(const QVariant& z=QVariant()) -> QString
{
    QStringList g;

    if(!z.isNull())g.append(GMode::ToGCcode(GMode::Linear)+ " z"+GCode::r(z.value<double>())+" (pull)");
    g.append(GMode::ToGCcode(GMode::Rapid)+ " z"+GCode::r(_movZ)+" (lift up)");

    return g.join('\n');
}

//auto GenerateGcode::LiftUp(Point p)-> QString
//{
//    QStringList g;

//    g.append(p.GoToXYZ(Rapid)+" (pull)");
//    g.append(Gcode(Rapid)+ " z"+rToGcode(_movZ)+" (lift up)");

//    return g.join('\n');
//}

auto GenerateGcode::LiftDown(qreal z)-> QString
{
    QStringList g;

    g.append(GMode::ToGCcode(GMode::Rapid)+ " z"+GCode::r(z+1)+" (lift down)");
    g.append(GMode::ToGCcode(GMode::Linear)+ " z"+GCode::r(z)+" (push)");

    return g.join('\n');
}

auto GenerateGcode::TravelXY(Point p) -> QString
{
    QStringList g;

    g.append(LiftUp());
    g.append(p.GoToXY(GMode::Rapid)+" (travel)");

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

/*LINE*/

auto GenerateGcode::GenerateLineHorizontal(const QString &txt) -> QString
{
    if(!txt.startsWith('l')) return QString();
    Line m = ParseLine(txt);
    if(m.isValid()){
        return GenerateLineHorizontal(m);
    }

    zInfo("Line: "+m.lasterr());
    return {};
}

auto GenerateGcode::GenerateLineHorizontal(const Line& m) -> QString
{
    _lasterr.clear();
    zInfo("G:"+m.ToString());
    if(!ValidateTool()) {_lasterr=L("no tool"); return {};}

    /*nincs sem letárolt, sem megadott*/
    if(_last_cut.z==-1 && m.cut.z==-1){_lasterr=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){_lasterr=L("no cut depth"); return {};}

    /*tároljuk le a megadottat*/
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;

    /*validáció*/
    if(_last_cut.z<=0) {_lasterr=L("no toal cut depth");return {};}
    if(_last_cut.z0>_last_cut.z) {
        _lasterr=L("wrong cut depth: ")+GCode::r(_last_cut.z0)+
            " total: "+GCode::r(_last_cut.z);return {};
    }

    if(m.p0.isValid()){
        _lastLineP0=m.p0;
    }
    if(m.rp.isValid()){
        _lastLineP0.x+=m.rp.x;
        _lastLineP0.y+=m.rp.y;
        _lastLineP0.z+=m.rp.z;
    }
    if(m.p1.isValid()){
        _lastLineP1=m.p1;
    }
    if(m.rp.isValid()){
        _lastLineP1.x+=m.rp.x;
        _lastLineP1.y+=m.rp.y;
        _lastLineP1.z+=m.rp.z;
    }

    if(m.feed.spindleSpeed!=-1) _selected_feed.spindleSpeed = m.feed.spindleSpeed;
    if(m.feed.f!=-1)_selected_feed.f=m.feed.f;

    //zInfo("->"+_last_cut.ToString()+_last_feed.ToString());
    QStringList g(QStringLiteral("(line)"));
    Point p = _lastLineP0;

    g.append(TravelXY(p));


    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    g.append(LiftDown(p.z));

    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    //int steps = qCeil(m.cut.z/m.cut.z0)+1;
    //QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){
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

        g.append(p.GoToXYZ(GMode::Linear));
    }

    g.append(LiftUp(p.z));
    //zInfo(g);
    return g.join('\n');
}

/*HOLE*/

auto GenerateGcode::GenerateHole(const QString &txt) -> QString
{
    if(!txt.startsWith('h')) return QString();    
    Hole m = ParseHole(txt);
    if(m.isValid()) {
        return GenerateHole(m);
    }
    zInfo("Hole: "+m.lasterr());
    return {};
}

auto GenerateGcode::GenerateHole(const Hole &m) -> QString
{
    _lasterr.clear();
    auto msg = "G:"+m.ToString();
    zInfo(msg);

    if(!ValidateTool()) {_lasterr=L("no tool"); return {};}
    if(_last_hole_diameter==-1 && m.diameter==-1){_lasterr=L("no diameter"); return {};}
    if(_last_cut.z==-1 && m.cut.z==-1){_lasterr=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){_lasterr=L("no cut depth"); return {};}

    if(m.diameter!=-1) _last_hole_diameter = m.diameter;
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;

    if(_last_hole_diameter<=0) {
        _lasterr=L("wrong diameter: ")+GCode::r(_last_hole_diameter);return {};
    }
    Tool t = _tools[_selected_tool_ix];
    if(_last_hole_diameter<t.d) {
        _lasterr=L("wrong diameter: ")+GCode::r(_last_hole_diameter)+
            " tool: "+t.ToString();return {};}
    if(_last_cut.z<=0) {_lasterr=L("no toal cut depth");return {};}
    if(_last_cut.z0>_last_cut.z) {
        _lasterr=L("wrong cut depth: ")+GCode::r(_last_cut.z0)+
            " total: "+GCode::r(_last_cut.z);return {};
    }

    // todo c megcsinálni box->vonal
    if(m.p.isValid()){
        _lastHoleP=m.p;
    }
    if(m.rp.isValid()){
        _lastHoleP.x+=m.rp.x;
        _lastHoleP.y+=m.rp.y;
        _lastHoleP.z+=m.rp.z;
    }

    if(m.feed.spindleSpeed!=-1) _selected_feed.spindleSpeed = m.feed.spindleSpeed;
    if(m.feed.f!=-1)_selected_feed.f=m.feed.f;

    QStringList g(QStringLiteral("(hole - helical interpolation)"));
    Point p = _lastHoleP; // középpont , a szerszámpálya kezdőpontja

    double path_r = _last_hole_diameter/t.d/2;
    p.x -= path_r; //szerszámpálya kezdő pontja

    g.append(TravelXY(p));


    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    //g.append(LiftDown(m.p.z));
    g.append(LiftDown(p.z));

    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    //QString msg2 = " (steps="+QString::number(steps)+')';

//    for(int i=0;i<steps;i++){
//        qreal z = m.p.z-(i+1)*_last_cutZ0;

//        if(z<m.p.z-_last_cutZ) p.z = m.p.z-_last_cutZ; else p.z = z;

//        g.append(p.GoToZ(GMode::Circular)+" i"+GCode::r(path_r));
//    }

    for(int i=0;i<steps;i++){
        qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kiszámol
        qreal zz = _lastHoleP.z-_last_cut.z;
        if(z<zz){    //beállítjuk a p-t
            p.z = zz;
        } else {
            p.z = z;
        }

        g.append(p.GoToZ(GMode::Circular)+" i"+GCode::r(path_r));
    }

    g.append(LiftUp(p.z));  //ahol bement, ott is jön ki

    //g.append(LiftUp(p.z));  //ahol bement, ott is jön ki
//g.append(LiftUp(m.p.z));  //ahol bement, ott is jön ki
    //zInfo(msg +' ' + msg2);
    //zInfo(g);
    return g.join('\n');
}

/*BOX*/

auto GenerateGcode::GenerateBox(const QString &txt) -> QString
{
    if(!txt.startsWith('b')) return QString();    
    Box m = ParseBox(txt);
    if(m.isValid()) {
        return GenerateBox(m);
    }
    //auto a = QString(typeid(m).name());

    zInfo(L("Box: ")+m.lasterr());
    return {};
}

auto GenerateGcode::GenerateBox(const Box &m) -> QString
{
    _lasterr.clear();
    auto msg = "G:"+m.ToString();
    zInfo(msg);

    if(!ValidateTool()) {_lasterr=L("no tool"); return {};}
    if(m.type==BoxType::Undefined) { _lasterr=L("undefined type"); return QString();}
    if(m.type==BoxType::Corners){
        if(_last_hole_diameter==-1 && m.corner_diameter==-1){_lasterr=L("no diameter"); return {};}
        //todo d átmérőcheck
        // szerszám átmérő
        // fogásmélység
        // minta a hole
    }


    Tool t = _tools[_selected_tool_ix];

    //QString msg2 = " (steps="+QString::number(steps)+')';

    QStringList g(QStringLiteral("(box with gaps)"));

    Point ba = {qMin(m.p0.x, m.p1.x), qMin(m.p0.y, m.p1.y), m.p0.z};
    Point jf = {qMax(m.p0.x, m.p1.x), qMax(m.p0.y, m.p1.y), m.p0.z};
    qreal tool_r = t.d/2;

    switch(m.type){
    case BoxType::Outline:
        ba.y-=tool_r;
        jf.y+=tool_r;
        ba.x-=tool_r;
        jf.x+=tool_r;
        break;
    case BoxType::Inline:
        ba.y+=tool_r;
        jf.y-=tool_r;
        ba.x+=tool_r;
        jf.x+=tool_r;
        break;
    default: break;
    }

    Point ja = {jf.x,ba.y,ba.z};
    Point bf = {ba.x,jf.y,ba.z};

    if(m.type == BoxType::Corners){
        QVarLengthArray<Hole> holes = {
            {ba, m.corner_diameter, m.cut, m.feed},
            {ja, m.corner_diameter, m.cut, m.feed},
            {jf, m.corner_diameter, m.cut, m.feed},
            {bf, m.corner_diameter, m.cut, m.feed}
        };
        if(_verbose){
            for(int i=0;i<holes.length();i++){
                auto&l=holes[i];
                g.append('('+l.ToString()+')');
                zInfo('h'+QString::number(i)+':'+l.ToString());
            }
        }
        for(auto&h:holes){
            auto gl = GenerateHole(h);
            if(!gl.isEmpty()){
                g.append(gl);
            } else{
                zInfo("err: "+_lasterr);
            }
        }
    } else {
        zInfo(L("(border)"));
        // lemegy egyben a gapig
        qreal z2 = m.cut.z-m.gap.height;
        Cut cut_border{z2, m.cut.z0};

        QVarLengthArray<Line> lines_border = {
            {ba,ja, cut_border, m.feed},
            {ja,jf, cut_border, m.feed},
            {jf,bf, cut_border, m.feed},
            {bf,ba, cut_border, m.feed}};
        //gap layer
        ba.z-=z2;
        bf.z-=z2;
        ja.z-=z2;
        jf.z-=z2;

        Cut cut_gap{m.gap.height, m.cut.z0};
        QVarLengthArray<Line> lines_gap = {
            {ba,ja, cut_gap, m.feed},
            {ja,jf, cut_gap, m.feed},
            {jf,bf, cut_gap, m.feed},
            {bf,ba, cut_gap, m.feed}};

        zInfo(L("(gaps_segments)"));
        QList<Line> segments;

        for(int i=0;i<4;i++){
            auto&l_gap=lines_gap[i];
            auto&l_border=lines_border[i];
            segments.append(l_border);
            auto s = l_gap.Divide(m.gap, t.d);
            if(s.isEmpty()){
                zInfo(QStringLiteral("cannot divide line"));
                segments.append(l_gap);
            }else{
                segments.append(s);
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
            g.append(GenerateLineHorizontal(bl));
        }
    }
    //zInfo(msg);// +' ' + msg2);
    return g.join('\n');
}

auto GenerateGcode::SetTool(const QString &txt) -> QString
{
    if(!txt.startsWith('t')) return QString();
    auto m = Tool::Parse(txt);
    if(m.ix==-1) return QString();
    QString g;

    if(_tools.contains(m.ix)){ // ha van már ilyen tool
        if(m.type==Tool::None){ //selectelni akarjuk
            _selected_tool_ix = m.ix;
            //g = 't'+QString::number(_selected_tool_ix)+"(change tool)";
            g=ChangeTool();
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

auto GenerateGcode::ChangeTool() ->QString
{
    if(_selected_tool_ix==-1){
        zInfo(QStringLiteral("no tool selected"));
        return QString();
    }
    if(!_tools.contains(_selected_tool_ix)) {
        zInfo(QStringLiteral("tool not found: ")+QString::number(_selected_tool_ix));
        return QString();
    }
    if(_last_tool_ix == _selected_tool_ix){
        zInfo(QStringLiteral("tool not changed"));
        return QString();
    }

    Tool t = _tools[_selected_tool_ix];

    QStringList g;

    g.append(QStringLiteral("(change tool)"));
    g.append(SpindleStop());
    g.append(TravelXY({0,0,0}));
    g.append(QStringLiteral("g0 z")+GCode::r(_maxZ));
    g.append('t'+QString::number(t.ix)+" (tool select)");
    g.append(QStringLiteral("m6 (tool change)"));
    g.append(QStringLiteral("(msg, change tool to ")+Tool::TypeToString(t.type)+
             ", diameter="+GCode::r(t.d));
    g.append(QStringLiteral("m0 (machine stop)"));
    g.append(QStringLiteral("g0 z")+GCode::r(_maxZ));

    _last_tool_ix=_selected_tool_ix;
    return g.join('\n');
}

auto GenerateGcode::SpindleStart() ->QString
{
    auto const T = QStringLiteral("m3");
    if(_selected_feed.spindleSpeed<=0) return QString();
    auto sp = SetSpindleSpeed();
    return (sp.isEmpty()?T:T+' '+sp)+"(spindle start)";
}

auto GenerateGcode::SetSpindleSpeed() ->QString
{
    if(_selected_feed.spindleSpeed<=0) return QString();
    if(_last_feed.spindleSpeed == _selected_feed.spindleSpeed){
        //zInfo(QStringLiteral("spindle speed not changed"));
        return QString();
    }
    _last_feed.spindleSpeed = _selected_feed.spindleSpeed;
    return QStringLiteral("s")+GCode::r(_selected_feed.spindleSpeed)+" (set spindle speed)";
}

auto GenerateGcode::SpindleStop() ->QString
{
    return QStringLiteral("m5 (spindle stop)");
}

auto GenerateGcode::SetFeed() ->QString
{
    if(_selected_feed.f<=0) return QString();

    if(_last_feed.f == _selected_feed.f){
        //zInfo(QStringLiteral("feed rate not changed"));
        return QString();
    }
    _last_feed.f = _selected_feed.f;
    return QStringLiteral("f")+GCode::r(_selected_feed.f)+" (set feed)";
}



auto GenerateGcode::SetFeedRate(const QString &txt) -> QString
{
    if(!txt.startsWith('f')) return QString();
    bool isok;
    auto f = txt.midRef(1).toDouble(&isok);
    if(isok && f>0) _selected_feed.f=f;
    return SetFeed();
    //return 'f'+rToGcode(f)+" (set feed rate)";
}

auto GenerateGcode::SetSpindleSpeed(const QString &txt) -> QString
{
    if(!txt.startsWith('s')) return QString();
    bool isok;
    auto f = txt.midRef(1).toDouble(&isok);
    if(isok && f>0) _selected_feed.spindleSpeed=f;
    //return 's'+rToGcode(f)+" (set spindle speed)";
    return SetSpindleSpeed();
}


auto GenerateGcode::GeneratePrintString(const QString &txt) -> QString
{
    if(!txt.startsWith(QStringLiteral("print"))) return QString();

    String m = String::Parse(txt);
    return GeneratePrintString(m);
}

auto GenerateGcode::GeneratePrintString(const String &m) -> QString
{
    auto g = m.ToString();
    auto msg = QStringLiteral("G:")+g;
    zInfo(msg);
    return g;
}

