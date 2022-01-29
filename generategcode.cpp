#include "common/logger/log.h"
#include "generategcode.h"
#include <QtMath>
#include <QString>
#include "gcode/gcode.h"

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{
    gcodes.clear();
    _tools.clear();
    _selected_tool_ix = -1;
    _last_tool_ix=-1;
    _last_hole_diameter =-1;
    _last_cutZ = -1;
    _last_cutZ0 = -1;

    for(auto l:g){
        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        // todo 5 ha tartalmaz =-t akkor bal oldalon van a kulcs, a jobb oldalon az érték
        // ha az =-től balra van " akkor szar, nem jó nem értékadás az a sor akkor
        // baloldalon a trimmelt stringben nem lehet szóköz, írásjel
        // jobb oldalon ha "val kezdődik, és " val végződik, közte ami van az string
        // ha number, akkor szám

        switch(l[0].unicode()){
            case u'#':break;
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
    if(g.isEmpty()) return false;
    //gcodes.append("\n");
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
    return GenerateLineHorizontal(m);
}

auto GenerateGcode::GenerateLineHorizontal(const Line& m) -> QString
{
    auto msg = "G:"+m.ToString();

    if(!ValidateTool()) return QString();

    QStringList g;
    Point p = m.p0;

    g.append(QStringLiteral("(line)"));

    g.append(TravelXY(p));

    if(m.sp!=-1) _selected_spindle_speed = m.sp;
    if(m.f!=-1)_selected_feed_rate=m.f;
    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    g.append(LiftDown(m.p0.z));

    int steps = qCeil(m.z/m.s)+1;
    QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){
        if(!(i%2))
        {
            p=m.p1;
        }
        else
        {
            p=m.p0;
        }
        qreal z = p.z-(i+1)*m.s;

        if(z<p.z-m.z) p.z = p.z-m.z; else p.z = z;

        g.append(p.GoToXYZ(GMode::Linear));
    }

    g.append(LiftUp(m.p1.z));

    zInfo(msg +' ' + msg2);
    //zInfo(g);
    return g.join('\n');
}

/*HOLE*/

auto GenerateGcode::GenerateHole(const QString &txt) -> QString
{
    if(!txt.startsWith('h')) return QString();    
    Hole m = ParseHole(txt);
    return GenerateHole(m);
}

auto GenerateGcode::GenerateHole(const Hole &m) -> QString
{
    auto msg = "G:"+m.ToString();

    if(!ValidateTool()) return QString();
    if(_last_hole_diameter==-1 && m.diameter==-1) return QString();
    if(_last_cutZ==-1 && m.cutZ==-1) return QString();
    if(_last_cutZ0==-1 && m.cutZ0==-1) return QString();

    if(m.diameter!=-1) _last_hole_diameter = m.diameter;
    if(m.cutZ!=-1) _last_cutZ = m.cutZ;
    if(m.cutZ0!=-1) _last_cutZ0 = m.cutZ0;

    if(_last_hole_diameter<=0) return {};
    Tool t = _tools[_selected_tool_ix];
    if(_last_hole_diameter<t.d) return {};
    if(_last_cutZ<=0) return {};
    if(_last_cutZ0>_last_cutZ) return {};

    QStringList g;
    Point p = m.p; // középpont    

    double path_r = _last_hole_diameter/t.d/2;
    p.x -= path_r; //szerszámpálya kezdő pontja

    g.append(QStringLiteral("(hole - helical interpolation)"));

    g.append(TravelXY(p));

    if(m.spindleSpeed!=-1) _selected_spindle_speed = m.spindleSpeed;
    if(m.feed!=-1)_selected_feed_rate=m.feed;
    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    g.append(LiftDown(m.p.z));

    int steps = qCeil(_last_cutZ/_last_cutZ0)+1;
    QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){        
        qreal z = m.p.z-(i+1)*_last_cutZ0;

        if(z<m.p.z-_last_cutZ) p.z = m.p.z-_last_cutZ; else p.z = z;

        g.append(p.GoToZ(GMode::Circular)+" i"+GCode::r(path_r));
    }

    g.append(LiftUp(m.p.z));  //ahol bement, ott is jön ki

    zInfo(msg +' ' + msg2);
    //zInfo(g);
    return g.join('\n');
}

/*BOX*/

auto GenerateGcode::GenerateBox(const QString &txt) -> QString
{
    if(!txt.startsWith('b')) return QString();    
    Box m = ParseBox(txt);
    return GenerateBox(m);
}

auto GenerateGcode::GenerateBox(const Box &m) -> QString
{
    auto msg = "G:"+m.ToString();

    if(!ValidateTool()) return QString();

    Tool t = _tools[_selected_tool_ix];     

    int steps = qCeil(m.cutZ/m.cutZ0)+1;
    QString msg2 = " (steps="+QString::number(steps)+')';
    zInfo(msg +' ' + msg2);

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
        g.append(GenerateHole({ba, m.corner_diameter, m.cutZ, m.cutZ0, m.spindleSpeed, m.feed}));
        g.append(GenerateHole({ja, m.corner_diameter, m.cutZ, m.cutZ0, m.spindleSpeed, m.feed}));
        g.append(GenerateHole({jf, m.corner_diameter, m.cutZ, m.cutZ0, m.spindleSpeed, m.feed}));
        g.append(GenerateHole({bf, m.corner_diameter, m.cutZ, m.cutZ0, m.spindleSpeed, m.feed}));
    } else {
        // lemegy egyben a gapig
        qreal z2 = m.cutZ-m.gap.height;
        QVarLengthArray<Line> lines0 = {{ba,ja, z2, m.cutZ0, m.spindleSpeed, m.feed},
                        {ja,jf, z2, m.cutZ0, m.spindleSpeed, m.feed},
                        {jf,bf, z2, m.cutZ0, m.spindleSpeed, m.feed},
                        {bf,ba, z2, m.cutZ0, m.spindleSpeed, m.feed}};
        //gap layer
        ba.z-=z2;
        bf.z-=z2;
        ja.z-=z2;
        jf.z-=z2;
        QVarLengthArray<Line> lines = {{ba,ja, m.gap.height, m.cutZ0, m.spindleSpeed, m.feed},
                        {ja,jf, m.gap.height, m.cutZ0, m.spindleSpeed, m.feed},
                        {jf,bf, m.gap.height, m.cutZ0, m.spindleSpeed, m.feed},
                        {bf,ba, m.gap.height, m.cutZ0, m.spindleSpeed, m.feed}};

        QList<Line> segments;

        for(int i=0;i<4;i++){
            auto&l=lines[i];
            auto&l0=lines0[i];
            segments.append(l0);
            auto s = l.Divide(m.gap, t.d);
            if(s.isEmpty()){
                zInfo(QStringLiteral("cannot divide line"));
                segments.append(l);
            }else{
                segments.append(s);
            }
        }

        for(auto&bl:segments){
            if(_verbose) g.append('('+bl.ToString()+')');
            zInfo("bl:"+bl.ToString());
        }
        for(auto&bl:segments){
            auto ls = GenerateLineHorizontal(bl);
            g.append(ls);
        }
    }
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
    if(_selected_spindle_speed<=0) return QString();
    auto sp = SetSpindleSpeed();
    return (sp.isEmpty()?T:T+' '+sp)+"(spindle start)";
}

auto GenerateGcode::SetSpindleSpeed() ->QString
{
    if(_selected_spindle_speed<=0) return QString();
    if(_last_spindle_speed == _selected_spindle_speed){
        zInfo(QStringLiteral("spindle speed not changed"));
        return QString();
    }
    _last_spindle_speed = _selected_spindle_speed;
    return QStringLiteral("s")+GCode::r(_selected_spindle_speed)+" (set spindle speed)";
}

auto GenerateGcode::SpindleStop() ->QString
{
    return QStringLiteral("m5 (spindle stop)");
}

auto GenerateGcode::SetFeed() ->QString
{
    if(_selected_feed_rate<=0) return QString();

    if(_last_feed_rate == _selected_feed_rate){
        zInfo(QStringLiteral("feed rate not changed"));
        return QString();
    }
    _last_feed_rate = _selected_feed_rate;
    return QStringLiteral("f")+GCode::r(_selected_feed_rate)+" (set feed)";
}



auto GenerateGcode::SetFeedRate(const QString &txt) -> QString
{
    if(!txt.startsWith('f')) return QString();
    bool isok;
    auto f = txt.midRef(1).toDouble(&isok);
    if(isok && f>0) _selected_feed_rate=f;
    return SetFeed();
    //return 'f'+rToGcode(f)+" (set feed rate)";
}

auto GenerateGcode::SetSpindleSpeed(const QString &txt) -> QString
{
    if(!txt.startsWith('s')) return QString();
    bool isok;
    auto f = txt.midRef(1).toDouble(&isok);
    if(isok && f>0) _selected_spindle_speed=f;
    //return 's'+rToGcode(f)+" (set spindle speed)";
    return SetSpindleSpeed();
}




