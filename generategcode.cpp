#include "common/logger/log.h"
#include "generategcode.h"
#include <QtMath>
#include <QString>
#include "gcode/gcode.h"
#include "gcode/variable.h"
#include "gcode/string.h"
#include <geometry/geomath.h>


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
    _lastBoxType = BoxType::Undefined;

    for(auto l:g){
        QString err;
        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        if(l.startsWith('#')) continue;
        if(GCode::_variables.Parse(l)) continue;
        if(l.startsWith(L("print"))){
            auto a = GeneratePrintString(l);
            AppendGcode(a, err);
            continue;
            }
        switch(l[0].unicode()){
        case u'(':AppendGcode(GenerateComment(l), err);break;
        case u'y':
        case u'x':setXYMode(l);break;
        case u'l':AppendGcode(GenerateLineHorizontal(l, &err), err);break;
        case u'h':AppendGcode(GenerateHole(l, &err), err);break;
        case u't':AppendGcode(SetTool(l), err);break;
        case u'f':AppendGcode(SetFeedRate(l), err);break;
        case u's':AppendGcode(SetSpindleSpeed(l), err);break;
        case u'b':AppendGcode(GenerateBox(l, &err), err);break;
        }
    }
    return gcodes;
}

auto GenerateGcode::AppendGcode(const QString &g, const QString& err) -> bool
{
    if(!g.isEmpty())gcodes.append(g);
    if(!err.isEmpty()){
        zInfo(err);
        return false;
    }
    return true;
}

auto GenerateGcode::setXYMode(const QString &txt) -> bool
{
    //_lasterr.clear();
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

auto GenerateGcode::GenerateLineHorizontal(const QString &txt,QString *err) -> QString
{
    if(!txt.startsWith('l')) return QString();
    Line m = ParseLine(txt);
    if(m.isValid()){        
        auto a = GenerateLineHorizontal(m,err);
        return a;
    }

    zInfo("Line: "+m.lasterr());
    return {};
}

auto GenerateGcode::GenerateLineHorizontal(const Line& m,QString *err) -> QString
{
    //_lasterr.clear();
    QString msg = "G:"+m.ToString();
    zInfo(msg);

    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){if(err)*err=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return {};
    /*FEED*/
    if(m.feed.spindleSpeed!=-1) _selected_feed.spindleSpeed = m.feed.spindleSpeed;
    if(m.feed.f!=-1)_selected_feed.f=m.feed.f;
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

    //zInfo("->"+_last_cut.ToString()+_last_feed.ToString());
    QStringList g(QStringLiteral("(line)"));
    Point p = _lastLineP0;

    msg=L("->")+ _lastLineP0.ToString()+' '+_lastLineP1.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();
    int steps = qCeil(_last_cut.z/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);

    g.append(TravelXY(p));

    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    g.append(LiftDown(p.z));

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
    zInfo(msg);
    return g.join('\n');
}

/*HOLE*/

auto GenerateGcode::GenerateHole(const QString &txt,QString*err) -> QString
{
    if(!txt.startsWith('h')) return QString();    
    Hole m = ParseHole(txt);
    if(m.isValid()) {
        return GenerateHole(m,err);
    }
    zInfo("Hole: "+m.lasterr());
    return {};
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

auto GenerateGcode::GenerateHole(const Hole &m, QString*err) -> QString
{
    //_lasterr.clear();
    auto msg = "G:"+m.ToString();
    zInfo(msg);

    /*DIAMETER*/
    if(_last_hole_diameter==-1 && m.diameter==-1){if(err){*err=L("no diameter");} return {};}
    if(m.diameter!=-1) _last_hole_diameter = m.diameter;
    if(_last_hole_diameter<=0) {
        if(err){*err=L("wrong diameter: ")+GCode::r(_last_hole_diameter);}
        return {};
    }
    /*CUT*/
    if(_last_cut.z==-1 && m.cut.z==-1){if(err)*err=L("no total cut depth"); return {};}
    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
    if(!CheckCut(err)) return{};
    /*FEED*/
    if(m.feed.spindleSpeed!=-1) _selected_feed.spindleSpeed = m.feed.spindleSpeed;
    if(m.feed.f!=-1)_selected_feed.f=m.feed.f;
    /*TOOL*/
    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = _tools[_selected_tool_ix];
    if(_last_hole_diameter<t.d) {
        if(err){*err=L("wrong diameter: ")+GCode::r(_last_hole_diameter)+
                " tool: "+t.ToString();
        }
        return {};
    }

    bool hasGaps = _last_hole_diameter>5*t.d; //
    bool pre_drill = hasGaps?false:_last_hole_diameter>2*t.d; //d=0
    bool pre_mill = hasGaps?false:_last_hole_diameter>3*t.d; //d=2*t.d
    // todo c0 ha az átmérő akkora, mint a szerszám, akkkor csak fúrunk

    // todo c1 ha kell gap, akkor a boxhoz hasonlóan kell eljárni,
    // ki kell számolni, hány gap kell,
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

    msg=L("->")+ p.ToString();
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();
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
       g.append(TravelXY(p)); //TRAVEL
       auto sp = SpindleStart();
       if(!sp.isEmpty()) g.append(sp);
       auto f = SetFeed();
       if(!f.isEmpty()) g.append(f);
       //g.append(LiftDown(p.z));
       g.append(L("G98 G81")+" z"+GCode::r(zz)+" r"+GCode::r(p.z));
    }
    if(pre_mill){
        Point pm = p;
        pm.x -= t.d;
        g.append(L("(premill)"));
        g.append(TravelXY(pm));
        g.append(LiftDown(pm.z));

        auto sp = SpindleStart();
        if(!sp.isEmpty()) g.append(sp);
        auto f = SetFeed();
        if(!f.isEmpty()) g.append(f);

        for(int i=0;i<steps;i++){
            qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kiszámol
            qreal zz = _lastHoleP.z-_last_cut.z;
            if(z<zz){    //beállítjuk a p-t
                pm.z = zz;
            } else {
                pm.z = z;
            }

            g.append(pm.GoToZ(GMode::Circular)+" i"+GCode::r(t.d));
        }
        //g.append(LiftUp(p.z));
    }

    double path_r = (_last_hole_diameter-t.d)/2; // a furat belső szélét érintő pályapont

    p.x -= path_r; //szerszámpálya kezdő pontja

    g.append(TravelXY(p));

    auto sp = SpindleStart();
    if(!sp.isEmpty()) g.append(sp);
    auto f = SetFeed();
    if(!f.isEmpty()) g.append(f);

    //g.append(LiftDown(m.p.z));
    g.append(LiftDown(p.z));

    Gap mgap{4,4,0.5};
    qreal z2 = hasGaps?_last_cut.z-mgap.height:_last_cut.z;
    Cut cut_border{z2, _last_cut.z0};

    for(int i=0;i<steps;i++){
        qreal z = _lastHoleP.z-(i+1)*_last_cut.z0;//kiszámol
        qreal zz = _lastHoleP.z-z2;//_last_cut.z;
        if(z<zz){    //beállítjuk a p-t
            p.z = zz;
        } else {
            p.z = z;
        }

        g.append(p.GoToZ(GMode::Circular)+" i"+GCode::r(path_r));
    }

    g.append(LiftUp(_lastHoleP.z));  //ahol bement, ott is jön ki

    if(hasGaps){
        qreal b = qDegreesToRadians(45.0);//QtMath.qDegreesToRadians(30);//mgap.length/(2*path_r);
        //for(int i=0;i<mgap.n;i++){

        //}
//        Point k0 = {5,40,-2.5};
//        Point k1 = {10,45,-2.5};
//        Point ko = {10,40,0};
        Point k0 = {-5,0,-2.5};
        Point k1 = {0,5,-2.5};
        Point ko = {0,0,0};

        Point k01;
        qreal r = GeoMath::Distance(k0,ko);
        auto isA = GeoMath::Polar(ko, k0, b, r, &k01);
        k01.z=k0.z;
        QString err2;
        g.append(GenerateArc(k01, k1, ko, .5, &err2));
        //g.append(GenerateArc({10,45,-2.5},{5,40,-2.5}, {10,40,0}, .5, &err2));
        //g.append(GenerateArc(k0,k1,ko, .5, &err2));
    }

    //g.append(LiftUp(p.z));  //ahol bement, ott is jön ki
//g.append(LiftUp(m.p.z));  //ahol bement, ott is jön ki
    zInfo(msg);
    //zInfo(g);
    return g.join('\n');
}
/*
(arc begin)
G0 z10.000 (lift up)
G0 x-3.535y3.535 (travel)
G0 z-1.500 (lift down)
G1 z-2.500 (push)
G2 x0.000y5.000z-2.650 i3.553 j-3.553
G3 x-3.553y3.55z-2.800 i0.000 j-5.000
G2 x0.000y5.000z-2.950 i3.553 j-3.553
G3 x-3.535y3.535z-3.000 i0.000 j-5.000
G2 x0.000y5.000z-3.000 i3.553 j-3.553
G1 z-2.500 (pull)
G0 z10.000 (lift up)
*/

/*ARC*/
auto GenerateGcode::GenerateArc(const Point &p0, const Point& p1, const Point&o, qreal h ,QString*err) -> QString
{
    QString msg = "G: a"+o.ToString();
    zInfo(msg);

    msg=L("->")+ p0.ToString()+' '+p1.ToString()+' '+o.ToString();
//    msg+=' '+_last_cut.ToString();
//    msg+=' '+_last_feed.ToString();
    msg+= " h:"+GCode::r(h);
    int steps = qCeil(h/_last_cut.z0)+1;
    msg+= " steps:"+QString::number(steps);

    QStringList g(L("(arc begin)"));

    g.append(TravelXY(p0));
    g.append(LiftDown(p0.z));
    Point p;
    GMode::Mode mode;
    QString ij;
    qreal i,j,i1,j1,i0,j0;
    i1=o.x-p0.x;
    j1=o.y-p0.y;

    i0=o.x-p1.x;
    j0=o.y-p1.y;

    for(int step=0;step<steps;step++){
        if(!(step%2))
        {
            p=p1;
            mode = GMode::Circular;
            ij="i5j0";
            i=i1;
            j=j1;
        }
        else
        {
            p=p0;
            mode = GMode::Circular_ccw;
            ij="i0j-5";
            i=i0;
            j=j0;
        }
        QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
        //        qreal z = p.z-(i+1)*m.cut.z0;
        //        if(z<p.z-m.cut.z) p.z = p.z-m.cut.z; else p.z = z;

        qreal z = p.z-(step+1)*_last_cut.z0;
        qreal zz = p.z-h;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }
        g.append(p.GoToXYZ(mode)+' '+ij2);
    }
    g.append(LiftUp(p0.z));

    zInfo(msg);
    return g.join('\n');
}


/*BOX*/

auto GenerateGcode::GenerateBox(const QString &txt,QString*err) -> QString
{
    if(!txt.startsWith('b')) return QString();    
    Box m = ParseBox(txt);
    if(m.isValid()) {
        return GenerateBox(m,err);
    }
    zInfo(L("Box: ")+m.lasterr());
    return {};
}

auto GenerateGcode::GenerateBox(const Box &m,QString*err) -> QString
{
    //_lasterr.clear();
    auto msg = "G:"+m.ToString();
    zInfo(msg);

    /*BOXTYPE*/
    if(_lastBoxType==BoxType::Undefined && m.type==BoxType::Undefined){
        if(err)*err=L("no box type");
        return QString();
    }
    if(m.type!=BoxType::Undefined) _lastBoxType = m.type;
    if(_lastBoxType==BoxType::Undefined) {
        if(err)*err=L("undefined box type");
        return QString();
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
    if(m.feed.spindleSpeed!=-1) _selected_feed.spindleSpeed = m.feed.spindleSpeed;
    if(m.feed.f!=-1)_selected_feed.f=m.feed.f;
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
        jf.x+=tool_r;
        //
        ja.x=jf.x;
        ja.y=ba.y;
        bf.x=ba.x;
        bf.y=jf.y;
        break;
    default: break;
    }

    msg=L("->")+ ba.ToString()+' '+jf.ToString();
    msg+=' '+BoxType::ToString(_lastBoxType);
    msg+=' '+_last_cut.ToString();
    msg+=' '+_last_feed.ToString();

    if(_lastBoxType == BoxType::Corners){
        msg+=" d"+GCode::r(_last_hole_diameter);
        QVarLengthArray<Hole> holes = {
            {ba, _last_hole_diameter, _last_cut, _last_feed},
            {ja, _last_hole_diameter, _last_cut, _last_feed},
            {jf, _last_hole_diameter, _last_cut, _last_feed},
            {bf, _last_hole_diameter, _last_cut, _last_feed}
        };
        if(_verbose){
            for(int i=0;i<holes.length();i++){
                auto&l=holes[i];
                g.append('('+l.ToString()+')');
                zInfo('h'+QString::number(i)+':'+l.ToString());
            }
        }
        for(auto&h:holes){
            auto gl = GenerateHole(h,err);
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
        Cut cut_border{z2, _last_cut.z0};

        QVarLengthArray<Line> lines_border = {
            {ba,ja, cut_border, _last_feed},
            {ja,jf, cut_border, _last_feed},
            {jf,bf, cut_border, _last_feed},
            {bf,ba, cut_border, _last_feed}};
        QVarLengthArray<Line> lines_gap;
        if(hasGaps){
            msg+=' '+m.gap.ToString();
            //gap layer
            ba.z-=z2;
            bf.z-=z2;
            ja.z-=z2;
            jf.z-=z2;

            Cut cut_gap{m.gap.height, _last_cut.z0};

            lines_gap = {
                {ba,ja, cut_gap, _last_feed},
                {ja,jf, cut_gap, _last_feed},
                {jf,bf, cut_gap, _last_feed},
                {bf,ba, cut_gap, _last_feed}
            };
        }
        zInfo(L("(segments)"));
        QList<Line> segments;

        for(int i=0;i<4;i++){
            auto&l_border=lines_border[i];
            segments.append(l_border);
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
            g.append(GenerateLineHorizontal(bl,err));
            _lastLineP0 = px0; // azonnal vissza is állítjuk
            _lastLineP1 = px1;
        }

    }
    zInfo(msg);
    return g.join('\n');
}

auto GenerateGcode::SetTool(const QString &txt) -> QString
{
    //_lasterr.clear();
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
    auto const M3 = QStringLiteral("m3");
    if(_selected_feed.spindleSpeed<=0) return QString();
    auto sp = SetSpindleSpeed();
    return (sp.isEmpty()?M3:M3+' '+sp)+"(spindle start)";
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
    //_selected_feed.spindleSpeed=0;
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
    //_lasterr.clear();
    if(!txt.startsWith('f')) return QString();
    bool isok;
    auto f = txt.midRef(1).toDouble(&isok);
    if(isok && f>0) _selected_feed.f=f;
    return SetFeed();
    //return 'f'+rToGcode(f)+" (set feed rate)";
}

auto GenerateGcode::SetSpindleSpeed(const QString &txt) -> QString
{
    //_lasterr.clear();
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
    //_lasterr.clear();
    auto g = m.ToString();
    auto msg = QStringLiteral("G:")+g;
    zInfo(msg);
    return g;
}

