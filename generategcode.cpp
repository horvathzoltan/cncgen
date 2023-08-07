#include "helpers/logger.h"
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
#include "helpers/textfilehelper.h"
#include <QDir>

const QString GenerateGcode::G1 = L("G:");
const QString GenerateGcode::G2 = L("    ->");
const QString GenerateGcode::T1 = L("T:");
const QString GenerateGcode::T_ERR = L("E:");
const QString GenerateGcode::T_W = L("W:");
const QString GenerateGcode::safeKey = L("safe");
const QString GenerateGcode::offsetKey = L("offset");
const QString GenerateGcode::safezKey = L("safetop");
const QString GenerateGcode::safebKey = L("safebottom");
const QString GenerateGcode::overcutKey = L("overcut");
const QString GenerateGcode::ratioKey = L("ratio");
const QString GenerateGcode::preMillStepsKey = L("pre_mill_steps");
const QString GenerateGcode::movzKey = L("movz");
const QString GenerateGcode::maxzKey = L("maxz");

const QString GenerateGcode::emaxKey = L("emax");
const QString GenerateGcode::fmaxKey = L("fmax");
const QString GenerateGcode::fminKey = L("fmin");
const QString GenerateGcode::fratioKey = L("fratio");
const QString GenerateGcode::pdwellKey = L("pdwell");


const QString GenerateGcode::nameKey = L("_");

//GenerateGcode::Compensation GenerateGcode::GetCompensation(qreal l, qreal z)
//{
//    qreal e0 = z/l;
//    qreal f = _last_feed.feed();
//    qreal fr = _fmax/f;
//    qreal e = e0/fr;
//    //qreal r = _emax/e;//ratio
//    //qreal f2 = f*r;// mekkora sebességgel lehet vágni?
//    if(e<=_emax) return GenerateGcode::Compensation::none;
//    //if(f2>=_fmin) return GenerateGcode::Compensation::speed;
//    return GenerateGcode::Compensation::depth;
//}

//qreal GenerateGcode::CompensateSpeed(qreal l, qreal z)
//{
//    qreal e = z/l;
//    qreal r = _emax/e;
//    qreal f = _last_feed.feed();
//    qreal f2 = f*r;

//    zInfo("compensate speed: "+QString::number(f)+"->"+QString::number(f2));
//    bool compOk = f2<=f;
//    if(compOk){
//        return f2;
//    }
//    zInfo("speed compensation error");
//    return f;
//}

bool GenerateGcode::Compensate(qreal l, qreal z, qreal *z_out, qreal *f_out, qreal f_in)
{
    //qreal r = l/100;
    qreal e = z/l; // aktuális fogás
    qreal f = f_in;
    qreal rf = _fmax/f;
    qreal emax = _emax*rf; // max fogás az akt sebességnél: ennyi lehetne

    if(emax>=e){
        //ok, megeszi
        return false;
    }

    qreal r = e/emax;

    qreal f2 = f/r;
    if(f2>=_fmin){
        *z_out=z;
        *f_out=f2;
        return true;
    }
    // túl lassú lenne le kell csökkenteni a fogást

    //if(_fratio<=0.5) _fratio=0.5;
    qreal rf2 = rf*_fratio;
    *z_out=(z/r)/rf2;
    *f_out=f_in*rf2;
    return true;
}



void GenerateGcode::Init(){
    gcodes.clear();

    _XYMode=XYMode::XY;
    _MMode = {};
    _tools.clear();

    _selected_tool_ix = -1;
    _selected_feed3 ={};
    _selected_cut ={};

    _last_tool_ix=-1;
    _last_feed3 ={};
    _last_cut3 = {};
    _lastHoleP={};
    _last_hole_diameter =-1;
    _lastLine={};
    _safez = 0;
    _safeb = 0;
    _overcut = 0;
    _preMillSteps = 3;
    _movZ=2;
    _maxZ=4;
    _fmax=500;
    _fmin=200;
    _emax=0.005;
    _fratio=0.7;

    _lastBox={{},{},BoxType::Undefined};
    //    _lastBoxP1={};
    //    _lastBoxType=BoxType::Undefined;
    _last_position = {};
    _last_gmode=GMode::Undefined;

    _total_minutes=0;
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

//        if(Box::Parse(l).state()!=ParseState::NoData){
//            if(ParseBoxToGcode(l, &gcode, &err)){
//                AppendGCode(&gcodes, gcode, err);
//            }
//            continue;
//        }

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

        if(l.startsWith(safezKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, safezKey, &r);
            if(isok) _safez = r;
            continue;
        }

        if(l.startsWith(safebKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, safebKey, &r);
            if(isok) _safeb = r;
            continue;
        }

        if(l.startsWith(overcutKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, overcutKey, &r);
            if(isok) _overcut = r;
            continue;
        }

        if(l.startsWith(movzKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, movzKey, &r);
            if(isok) _movZ = r;
            continue;
        }

        if(l.startsWith(maxzKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, maxzKey, &r);
            if(isok) _maxZ = r;
            continue;
        }

        if(l.startsWith(ratioKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, ratioKey, &r);
            if(isok) _ratio = r;
            continue;
        }        

        if(l.startsWith(preMillStepsKey)){
            int r;
            bool isok = GCode::ParseValue(l, preMillStepsKey, &r);
            if(isok) _preMillSteps = r;
            continue;
        }

        if(l.startsWith(emaxKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, emaxKey, &r);
            if(isok) _emax = r;
            continue;
        }

        if(l.startsWith(fmaxKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fmaxKey, &r);
            if(isok) _fmax = r;
            continue;
        }

        if(l.startsWith(fminKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fminKey, &r);
            if(isok) _fmin = r;
            continue;
        }

        if(l.startsWith(fratioKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fratioKey, &r);
            if(isok) _fratio = r;
            continue;
        }

        if(l.startsWith(pdwellKey)){
            int r;
            bool isok = GCode::ParseValue(l, pdwellKey, &r);
            if(isok) _pdwell = r;
            continue;
        }


        if(l.startsWith(L("include"))){
            QString fn;
            bool isok = GCode::ParseValue(l, L("include"), &fn);
            if(isok){
                _includeFn = fn;

                auto d = QDir(_workingFolder);

                auto inf = d.filePath(fn);

                auto geomLines = TextFileHelper::loadLines(inf);

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

        /*BOX*/
        case Box::keyUniCode:
             if(ParseBoxToGcode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
             }
             break;
        /*HOLE*/
        case Hole::keyUniCode:
            if(ParseHoleToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        /*LINE*/
        case Line::keyUniCode:
            if(ParseLineToGCode(l, &gcode, &err)){
                AppendGCode(&gcodes, gcode, err);
                continue;
            }
            break;
        /*ARC*/
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

        }
    }

    _last_position.z=0;
    auto gc2=TravelXYToGCode(_selected_feed3.feed(), _safe_place);
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
    if(s.state() == ParseState::Parsed ) // ha Arc típusú sor
    {
        if(_isPlot){
            if(m.p0.z<0) m.p0.z=0;
            if(m.p1.z<0) m.p1.z=0;
            if(m.o.z<0) m.o.z=0;
            if(m.rp.z<0) m.rp.z=0;

            m.cut.z = 0.02;
            m.cut.z0 = 0.02;

            _tools[_selected_tool_ix].d=0.5;
            //m.gap.height = 0.01;
            m.feed.setFeed(_fmax);
        }else{
            if(_safez>0){
                m.p0.z+=_safez;
                m.p1.z+=_safez;
                m.o.z+=_safez;
               // m.rp.z+=_safez;

                m.cut.z+=_safez;                
            }
            if(_safeb>0){
                m.cut.z+=_safeb;
            }
            if(_overcut>0){
                m.cut.z+=_overcut;
            }

            if(!m.feed.Check(_fmin, _fmax)){
                if(_selected_feed3.Check(_fmin, _fmax,err)){
                    m.feed = _selected_feed3;
                }
            }
        }

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
    if(s.state() == ParseState::Parsed ) // ha Arc típusú sor
    {
        if(_isPlot){
            if(m.p0.z<0) m.p0.z=0;
            if(m.p1.z<0) m.p1.z=0;
            if(m.rp.z<0) m.rp.z=0;

            m.cut.z = 0.02;
            m.cut.z0 = 0.02;
            m.gap.height = 0.01;

            _tools[_selected_tool_ix].d=0.5;

            m.feed.setFeed(_fmax);
        } else{
            if(_safez>0){
                m.p0.z+=_safez;
                m.p1.z+=_safez;
              //  m.rp.z+=_safez;
                m.cut.z += _safez;
            }
            if(_safeb>0){
                m.cut.z+=_safeb;
                if(m.gap.isValid()){
                    m.gap.height+=_safeb;
                }
            }
            if(_overcut>0){
                m.cut.z+=_overcut;
                if(m.gap.isValid()){
                    m.gap.height+=_overcut;
                }
            }
            if(!m.feed.Check(_fmin, _fmax)){
                if(_selected_feed3.Check(_fmin, _fmax, err)){
                    m.feed = _selected_feed3;
                }
            }
        }

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
    if(s.state() == ParseState::Parsed ) // ha Box típusú sor
    {
        if(_isPlot){
            if(m.p.z<0) m.p.z=0;
            if(m.rp.z<0) m.rp.z=0;

            m.cut.z = 0.02;
            m.cut.z0 = 0.02;
            m.gap.height = 0.01;

            _tools[_selected_tool_ix].d=0.5;

            m.feed.setFeed(_fmax);
        } else{
            if(_safez>0){
                m.p.z+=_safez;
              //  m.rp.z+=_safez;

                m.cut.z+=_safez;
            }
            if(_safeb>0){
                m.cut.z+=_safeb;
                if(m.gap.isValid()){
                    m.gap.height+=_safeb;
                }
            }
            if(_overcut>0){
                m.cut.z+=_overcut;
                if(m.gap.isValid()){
                    m.gap.height+=_overcut;
                }
            }

            if(!m.feed.Check(_fmin, _fmax)){
                if(_selected_feed3.Check(_fmin, _fmax, err)){
                    m.feed = _selected_feed3;
                }
            }

        }

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
    if(s.state() == ParseState::Parsed ) // ha Box típusú sor
    {
        if(_isPlot){
            if(m.p0.z<0) m.p0.z=0;
            if(m.p1.z<0) m.p1.z=0;
            if(m.rp.z<0) m.rp.z=0;

            m.cut.z = 0.02;
            m.cut.z0 = 0.02;
            m.gap.height = 0.01;

            _tools[_selected_tool_ix].d=0.5;

            m.feed.setFeed(_fmax);
        } else{
            if(_safez>0){
                m.p0.z+=_safez;
                m.p1.z+=_safez;
            //    m.rp.z+=_safez;

                m.cut.z+=_safez;
            }
            if(_safeb>0){
                m.cut.z+=_safeb;
                if(m.gap.isValid()){
                    m.gap.height+=_safeb;
                }
            }
            if(_overcut>0){
                m.cut.z+=_overcut;
                if(m.gap.isValid()){
                    m.gap.height+=_overcut;
                }
            }
            if(!m.feed.Check(_fmin, _fmax)){
                if(_selected_feed3.Check(_fmin, _fmax,err)){
                    m.feed = _selected_feed3;
                }
            }
        }

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
    auto s = Feed::Parse(str, &_selected_feed3);
    if(s.state()==ParseState::NoData) return false;
    zInfo(T1+str);

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

// todo 11 circle: c - mint a hole, csak nincs belül kimarva - a gaps eset -> ventillátor kivágás
// todo 12 o: forgatás minden elemre - o középpont, és szög

auto GenerateGcode::AppendGCode(QStringList* gs, const QString &g, const QString& err, const QString& comment) -> bool
{
    if(!gs) return false;
    if(!g.isEmpty()){
        if(comment.isEmpty()){gs->append(g);}
        else{gs->append(g+" ("+comment+')');}
    }
    if(!err.isEmpty()){
        zInfo(err);
        gs->append("(error: "+err+")");
        return false;
    }
    return true;
}

auto GenerateGcode::LiftUpToGCode(qreal feed, const QVariant& z=QVariant()) -> QString
{
    QStringList g;
    QString err;
    auto movZ = _movZ;// GCode::_variables.movZ();
    if(_last_position.z >=movZ){ return {};}
    if(!z.isNull()){
        auto z0 = z.value<double>();
        qreal l = z0-_last_position.z;
        auto gcode = GoToZ(GMode::Linear,{0,0,z0}, l, feed);//+ " (pull)";
        AppendGCode(&g, gcode, err, QStringLiteral("pull"));
    }
    qreal l = movZ-_last_position.z;
    auto gcode = GoToZ(GMode::Rapid,{0,0,movZ}, l, feed);// + "(lift up)";
    AppendGCode(&g, gcode, err, "lift up");
    return g.join('\n');
}

auto GenerateGcode::LiftDownToGCode(qreal feed, qreal z)-> QString
{
    QStringList g;
    QString err;

    qreal safez = _safez+1;//(_safez!=0)?_safez:1;
    if(_last_position.z==z){ return {};}
    auto z2 = z+safez; // z2-ig gyorsan megyünk
    qreal l = _last_position.z-z2;
    auto gcode = GoToZ(GMode::Rapid,{0,0,z2},l, feed);//+ " (lift down)";
    AppendGCode(&g, gcode, err, L("lift down"));
    l = _last_position.z-z;
    gcode = GoToZ(GMode::Linear,{0,0,z}, l,feed);//+ " (push)";
    AppendGCode(&g, gcode, err, L("push"));

    return g.join('\n');
}

auto GenerateGcode::TravelXYToGCode(qreal feed, const Point& p) -> QString
{
    QStringList g;
    QString err;

    auto g1 = LiftUpToGCode(feed);
    AppendGCode(&g, g1, "", "");
    //g.append(g1);
    qreal l = GeoMath::Distance(_last_position, p);
    auto gcode = GoToXY(GMode::Rapid, p, l, feed);
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

//void GenerateGcode::SetSelectedFeed(Feed feed){
//    if(feed.spindleSpeed()!=-1) _selected_feed.setSpindleSpeed(feed.spindleSpeed());
//    if(feed.feed()!=-1)_selected_feed.setFeed(feed.feed());
//}

/*LINE*/
auto GenerateGcode::LineToGCode(const Line& m,QString *err) -> QString
{
    //_lasterr.clear();/*LINE*/
    QString msg = G1+m.ToString();
    StringHelper::Tabulate(&msg, G2);    
    zInfo(msg);

    /*CUT*/
    if(!m.cut.Check(err)){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(_fmin, _fmax, err)){
        return{};
    }
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

    qreal distance = GeoMath::Distance(_lastLine.p0, _lastLine.p1);
    if(distance<t.d) {
        if(err){*err=L("line too short: ")+QString::number(distance)+"mm";}
        return {};
    }

    Gap mgap; // megvalósítandó gap
    if(m.gap.isValid()){//gapeket akar
        //if(mgap.height<_last_cut.z0){if(err)*err=L("gap he"); return{};}
        int gapn = qFloor(distance/(t.d+m.gap.length)); // hány gap fér ki
        if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
         if(m.gap.n>gapn) { gapn=m.gap.n;} // ha több is kifér, annyit kap amennyit kér
         mgap = {(m.gap.n>gapn)?gapn:m.gap.n,// ha többet kért, mint ami kifér
                 m.gap.length,m.gap.height};
    }

    QString nameComment = m.GetComment();
    QStringList g(nameComment);

    g.append(TotalTimeToGCode());
    msg=G2+ _lastLine.p0.ToString()+' '+_lastLine.p1.ToString();
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    if(mgap.isValid()) msg+= " gaps:"+QString::number(mgap.n);
    zInfo(msg);
    /*CUT*/
    qreal z2 = mgap.isValid()?m.cut.z-mgap.height:m.cut.z;
    if(z2>0){
         Cut cut2 = m.cut;
         cut2.z=z2;
         auto g0 = LinearCut(m.feed, cut2);
         g.append(g0);
    }
    if(mgap.isValid()){
        Point ba1=GeoMath::Translation(_lastLine.p0, 0, 0, -z2);
        Point ja1=GeoMath::Translation(_lastLine.p1, 0, 0, -z2);
        Cut cut_gap{mgap.height, m.cut.z0};
        Line l_gap={ba1,ja1, cut_gap, m.feed,{}, {}, m.name+" gap"};
        auto segments = l_gap.Divide(m.gap, t.d);
        for(auto&segment:segments){
            auto px0 = _lastLine.p0;
            auto px1 = _lastLine.p1;
            _lastLine.p0=segment.p0;
            _lastLine.p1=segment.p1;
            Cut cut3 = m.cut;
            cut3.z=segment.cut.z;
            auto g01 = LinearCut(m.feed, cut3);
            g.append(g01);
            _lastLine.p0 = px0; // azonnal vissza is állítjuk
            _lastLine.p1 = px1;
        }

    }


    g.append(TotalTimeToGCode());
    return g.join('\n');
}

auto GenerateGcode::TotalTimeToGCode() -> QString
{
    return "(time[min]: "+QString::number(_total_minutes)+")";
}



void GenerateGcode::GoToCutposition(QStringList *g, const Point& p, const Feed& feed){
    AppendGCode(g, TravelXYToGCode(feed.feed(), p));
    AppendGCode(g, SpindleStartToGCode(feed.spindleSpeed()));

    QString g0;
    bool ok = SetFeedToGCode(feed.feed(), &g0);
    if(ok && !g0.isEmpty()){
        g0+= L(" (set feed)");
        AppendGCode(g, g0);
    }

    AppendGCode(g, LiftDownToGCode(feed.feed(), p.z));
}

qreal GenerateGcode::MinToMilliSec(qreal a){
    return a*60000;
}

qreal GenerateGcode::MilliSecToMin(qreal a){
    return a/60000;
}

// koordináták minden paraméter be van állítva
auto GenerateGcode::LinearCut(const Feed& o_feed, const Cut& o_cut) -> QStringList{
    QStringList g(QStringLiteral("(linear cut)"));
    QString msg;

    qreal l = GeoMath::Distance(_lastLine.p0, _lastLine.p1);


    CompensateModel c = Compensate2(l,  o_cut, o_feed);
    Feed feed = o_feed;
    Cut cut = o_cut;
    if(c.isCompensated){
        feed.setFeed(c.c_f);
        cut.z0=c.c_z;

        c.ToGCode(&g, o_cut, o_feed);
    }

    Point p = _lastLine.p0;
    //if(safety){
   //     p.z+=_safez;
   //     total_depth+=_safez;
    //}



//    if(_last_feed.feed()==513 && c_f==486){
//        zInfo("hutty");
//    }

    Tool t = _tools[_selected_tool_ix];
    qreal peck_z = qMax(p.z, _lastLine.p1.z);
    //qreal zz = peck_z-cut.z;

    bool isPeck = false;//l<=t.d*5;
    bool isDwell = false;//l<=t.d*10;
    bool isDwell2 = false;//l<=t.d*10;

    if(l<=t.d*15){
        isPeck = true;
    } else if(l<=t.d*30){
        isDwell = true;
    }


    if(isPeck){
        g.append("(peck)");
    }


    if(isPeck){
        if(l<=t.d*5){
            feed.setFeed(feed.feed()/1.5);
            isDwell2 = true;
        } else if(l<=t.d*10){
            isDwell2 = true;
        }
    }

    qreal safez = _safez+1;//(_safez!=0)?_safez:1;

    GoToCutposition(&g, p, feed);

    int steps_0 = cut.steps();

    msg+= "cut:"+_lastLine.p0.ToString()+"->"+_lastLine.p1.ToString();
    msg+= " total_depth:"+QString::number(cut.z);
    msg+= " steps:"+QString::number(steps_0);

    qreal dt = 0;
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

        qreal z = p.z-(i+1)*cut.z0;
        qreal zz = p.z-cut.z;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }
        //if(safety){
        //    p.z+=_safez;
       // }

        qreal d = GeoMath::Distance(pd,p);
        dt+=d;
        auto g0 = GoToXYZ(GMode::Linear, p, d, feed.feed());
        AppendGCode(&g, g0);

        qreal peck_l = qAbs(peck_z-p.z);
        qreal t0_ms = MinToMilliSec(peck_l/1500);
        qreal t1_ms = MinToMilliSec(peck_l/feed.feed());
        qreal t2_ms = t0_ms+t1_ms;

        int maxdwellmillis = _pdwell;
        if(isPeck){
            g0 = GoToZ(GMode::Rapid,{0,0,peck_z+safez}, peck_l, feed.feed());
            AppendGCode(&g, g0);
            if(isDwell2){
                int tdwell_ms = (t2_ms<maxdwellmillis)?maxdwellmillis-t2_ms:0;
                if(tdwell_ms>100){
                    g0 = "G4 P"+QString::number(tdwell_ms);
                    AppendGCode(&g, g0);
                    _total_minutes+=MilliSecToMin(tdwell_ms);
                }
            }
            g0 = GoToZ(GMode::Linear,{0,0,p.z}, peck_l, feed.feed());
            AppendGCode(&g, g0);
        }
        if(isDwell){
            int tdwell_ms = maxdwellmillis;
            g0 = "G4 P"+QString::number(tdwell_ms);
            AppendGCode(&g, g0);
            _total_minutes+=MilliSecToMin(tdwell_ms);
        }
        //if(d<=10) AppendGCode(&g, Dwell(100));//250
    }

//    if(isc){
//        DeCompensate2(c_z, c_f);
//    }

    msg+=" distance: "+QString::number(dt);

    AppendGCode(&g, LiftUpToGCode(feed.feed(), p.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
}

GenerateGcode::CompensateModel GenerateGcode::Compensate2(qreal l, const Cut& cut, const Feed& feed){
    CompensateModel c;

    c.isCompensated = Compensate(l, cut.z0, &c.c_z, &c.c_f, feed.feed());

    return c;
}

void GenerateGcode::CompensateModel::ToGCode(QStringList* g, const Cut& o_cut, const Feed& o_feed){
    if(isCompensated){
        if(c_z!=o_cut.z0){
            QString gc1 = L("compensate cut: %1 -> %2").arg(o_cut.z0).arg(c_z);
            g->append("("+gc1+")");
        }
        if(c_f!=o_feed.feed()){
            QString gc0 = L("compensate feed: %1 -> %2").arg(o_feed.feed()).arg(c_f);
            g->append("("+gc0+")");
        }
    }
}

//void GenerateGcode::DeCompensate2(qreal c_z, qreal c_f){
//    if(c_f!=-1){
//        _selected_feed.setFeed(c_f);
//    }
//    if(c_z!=-1){
//        _last_cut.z0 = c_z;
//    }
//}
//auto GenerateGcode::PeckingDrill(qreal path_r, const Feed& o_feed,const Cut& o_cut) -> QStringList{


//}

auto GenerateGcode::HelicalCut(qreal path_r, const Feed& o_feed,const Cut& o_cut) -> QStringList{
    QStringList g(QStringLiteral("(helical cut)"));
    QString msg;

    qreal l = path_r*2*M_PI; //fogás hossz
    CompensateModel c = Compensate2(l, o_cut, o_feed);
    Feed feed = o_feed;
    Cut cut = o_cut;
    if(c.isCompensated){
        feed.setFeed(c.c_f);
        cut.z0=c.c_z;

        c.ToGCode(&g, o_cut, o_feed);
    }

    Point p = GeoMath::Translation(_lastHoleP, -path_r, 0, 0);

    GoToCutposition(&g, p, feed);

    int steps_0 = cut.steps();

    msg+= "cut:"+_lastHoleP.ToString()+"r="+GCode::r(path_r);
    msg+= " total_depth:"+QString::number(cut.z);//total_depth
    msg+= " steps:"+QString::number(steps_0);

    for(int i=0;i<steps_0;i++){
        Point pp=p;
        qreal z = _lastHoleP.z-(i+1)*cut.z0;//kiszámol
        qreal zz = _lastHoleP.z-cut.z;//total_depth//_last_cut.z;
        if(z<=zz){    //beállítjuk a p-t
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal lz = pp.z-p.z;
        qreal l1 = qSqrt(l*l+lz*lz); // út hossz



        QString g0;
        if(i%2==0){
            g0 = GoToZ(GMode::Circular, p, l1, feed.feed()) + " i" + GCode::r(path_r);
        } else{
            g0 = GoToZ(GMode::Circular_ccw, p, l1, feed.feed()) + " i" + GCode::r(path_r);
        }

        g.append(g0);
    }


//    if(isc){
//        DeCompensate2(c_z, c_f);
//    }

    AppendGCode(&g, LiftUpToGCode(feed.feed(), _lastHoleP.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
}

auto GenerateGcode::CircularArcCut(const Feed& o_feed,const Cut& o_cut) -> QStringList{
    QStringList g(QStringLiteral("(circular_arc cut)"));
    QString msg;

    qreal l=GeoMath::ArcLength(_lastArc.p0,_lastArc.p1, _lastArc.o);
    CompensateModel c = Compensate2(l,  o_cut, o_feed);
    Feed feed = o_feed;
    Cut cut = o_cut;
    if(c.isCompensated){
        feed.setFeed(c.c_f);
        cut.z0=c.c_z;
        c.ToGCode(&g, o_cut, o_feed);
    }
    GoToCutposition(&g, _lastArc.p0, feed);

    GMode::Mode mode;
    QString ij;
    qreal i,j,i1,j1,i0,j0;
    i1=_lastArc.o.x-_lastArc.p0.x;
    j1=_lastArc.o.y-_lastArc.p0.y;

    i0=_lastArc.o.x-_lastArc.p1.x;
    j0=_lastArc.o.y-_lastArc.p1.y;


    int steps = cut.steps();

    msg+= "cut:"+_lastArc.p0.ToString()+"->"+_lastArc.p1.ToString()+"o="+_lastArc.o.ToString();
    msg+= " total_depth:"+QString::number(cut.z);
    msg+= " steps:"+QString::number(steps);

    Tool t = _tools[_selected_tool_ix];
    qreal peck_z = qMax(_lastArc.p0.z, _lastArc.p1.z);
    bool isPeck = false;//l<=t.d*5;
    bool isDwell = false;//l<=t.d*10;
    bool isDwell2 = false;

    if(l<=t.d*15){
        isPeck = true;
    } else if(l<=t.d*30){
        isDwell = true;
    }


    if(isPeck){
        g.append("(peck)");
    }


    if(isPeck){
        if(l<=t.d*5){
            feed.setFeed(feed.feed()/1.5);
            isDwell2 = true;
        } else if(l<=t.d*10){
            isDwell2 = true;
        }
    }


    qreal safez = _safez+1;


    Point p = _lastArc.p0;
    qreal dt=0;
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
        qreal z = p.z-(step+1)*cut.z0;
        qreal zz = p.z-cut.z;
        if(z<zz){
            p.z = zz;
        } else {
            p.z = z;
        }

        qreal d=GeoMath::ArcLength(pp,p, _lastArc.o);

        dt+=d;
        auto g0 = GoToXYZ(mode, p, d, feed.feed());
        g.append(g0+' '+ij2);

        qreal peck_l = qAbs(peck_z-p.z);
        qreal t0_ms = MinToMilliSec(peck_l/1500);
        qreal t1_ms = MinToMilliSec(peck_l/feed.feed());
        qreal t2_ms = t0_ms+t1_ms;
        int maxdwellmillis = _pdwell;

        if(isPeck){
            g0 = GoToZ(GMode::Rapid,{0,0,peck_z+safez}, peck_l, feed.feed());
            AppendGCode(&g, g0);
            if(isDwell2){
                int tdwell_ms = (t2_ms<maxdwellmillis)?maxdwellmillis-t2_ms:0;
                if(tdwell_ms>100){
                    g0 = "G4 P"+QString::number(tdwell_ms);
                    AppendGCode(&g, g0);
                    _total_minutes+=MilliSecToMin(tdwell_ms);
                }
            }

            g0 = GoToZ(GMode::Linear,{0,0,p.z}, peck_l, feed.feed());
            AppendGCode(&g, g0);
        }
        if(isDwell){
            int tdwell_ms = maxdwellmillis;
            g0 = "G4 P"+QString::number(tdwell_ms);
            AppendGCode(&g, g0);
            _total_minutes+=MilliSecToMin(tdwell_ms);
        }
    }

//    if(isc){
//        DeCompensate2(c_z, c_f);
//    }

    msg+= " arc_distance:"+QString::number(dt);


    g.append(LiftUpToGCode(feed.feed(), _lastArc.p0.z));

    QString h=StringHelper::Tabulate2(G2);
    zInfo(h+msg);
    return g;
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
    if(!m.cut.Check(err)){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(_fmin, _fmax, err)){
        return{};
    }

    //SetSelectedFeed(m.feed);
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


    double path_r = (holeDiameter-t.d)/2; // a furat belső szélét érintő pályapont
    Gap mgap = m.gap.isValid()?m.gap:Gap{2, .5, 0.5};
    if(_isPlot){
        mgap.height = 0.01;
    }

    // ha csak fúrás, az egy predrill premill nélkül
    bool pre_drill, pre_mill,hasGaps, drillOnly=holeDiameter==t.d;
    if(m.ng)
    {
        hasGaps = false;
        pre_drill = true;
        pre_mill = true;
    }
    else{
        if(m.np){
            pre_drill = false;
            pre_mill =false;

            if(m.gap.n>0){
                hasGaps = true; //
                int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // hány gap fér ki
                if(gapn<1) {if(err)*err=L("cannot create gaps"); return{};}
                if(mgap.n>gapn){mgap.n=gapn;}// ha többet kért, mint ami kifér
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

                    int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // hány gap fér ki
                    if(gapn<1) {if(err)*err=L("cannot create gaps"); return{};}
                    if(mgap.n>gapn){mgap.n=gapn;}// ha többet kért, mint ami kifér

                } else {
                    //pre_drill = holeDiameter>=2*t.d; //d=0
                    pre_drill = holeDiameter>=t.d; //d=2*t.d
                    pre_mill = holeDiameter>t.d;
                }
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

    QString nameComment = m.GetComment();
    QStringList g(nameComment);
    g.append(QStringLiteral("(helical interpolation)"));
    g.append(TotalTimeToGCode());

    Point p = _lastHoleP; // _lastHoleP középpont , p a szerszámpálya kezdőpontja lesz

    msg=G2+ p.ToString();
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    msg+=" d"+GCode::r(holeDiameter);
    if(pre_drill) msg+=L(" predrill");
    if(pre_mill) msg+=L(" premill");
    if(hasGaps) msg+=L(" gap");
    int steps = qCeil(m.cut.z/m.cut.z0)+1;
    msg+= " steps:"+QString::number(steps);
    zInfo(msg);

    qreal safez = _safez+1;//(_safez!=0)?_safez:1;

    if(pre_drill){

        qreal d_l = (t.d*M_PI)/2; // a belső átmérőn is vág, kevesebbet
        CompensateModel d_c = Compensate2(d_l,  m.cut, m.feed);
        Feed d_feed = m.feed;
        Cut d_cut = m.cut;
        if(d_c.isCompensated){
            d_feed.setFeed(d_c.c_f);
            d_cut.z0=d_c.c_z;

            d_c.ToGCode(&g, m.cut, m.feed);
        }

        qreal zz = _lastHoleP.z-m.cut.z; // zz: mélység
        qreal r = p.z+safez; // r: visszahúzás z-je
        qreal q = d_cut.z0;  // q: mélység inkrement per peck

        g.append(L("(predrill)"));
        GoToCutposition(&g, p, d_feed);
        g.append(L("G98 G83")+" z"+GCode::r(zz)+" r"+GCode::r(r)+" q"+GCode::r(q));

        auto menet = zz/m.cut.z0;

        if(m.feed.feed()>0){
            qreal l0 = m.cut.z0*menet;
            qreal l1 = (p.z+safez+zz*menet*2)-l0;

            qreal t0_mins = l0/m.feed.feed()+l1/1500;
            _total_minutes+=t0_mins;
        }

       _last_position.z = p.z;
    }

    if(!drillOnly){
       if(pre_mill){
           g.append(L("(premill)"));
           //int s0_max = _pre_mill_steps;
           qreal tdr = t.d/6;
           qreal td0 = 0;
           qreal tds = t.d/_preMillSteps; // a maró átmérőjének ennyied része oldalra a fogás
           int steps = (path_r)/tds;
           for(int step=0;step<steps;step++){
                td0+=tds;

                // előmarás a kért átmérőig
                if(path_r-td0>tdr){
                    //SetSelectedFeed(m.feed);
                    auto g1=HelicalCut(td0, m.feed, m.cut);//m.cut.z
                    g.append(g1);
                }
           }
        }

  //      SetSelectedFeed(m.feed);
        p.x -= path_r; //szerszámpálya kezdő pontja - furat belső szélének érintése
        // ha van gap, csak a gapig megyünk egyébként teljesen
        qreal z2 = hasGaps?m.cut.z-mgap.height:m.cut.z;
        // marás a kért átmérőre
        if(z2>0){
            //SetSelectedFeed(m.feed);
           Cut cut2 = m.cut;
           cut2.z = z2;
           auto g1=HelicalCut(path_r, m.feed, cut2);
           g.append(g1);
        }

        if(hasGaps){
            Point p = GeoMath::Translation(_lastHoleP, -100, 0, -z2);//_lastHoleP
            //p.x=0;
            //p.z= _lastHoleP.z-z2;
            qreal b = (mgap.length+t.d)/(path_r);//ennyi szögig tart a gap
            qreal ab = (2*M_PI)/mgap.n;//ennyi szögenként van a gap

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

                Cut cut_gap = m.cut;
                cut_gap.z = mgap.height;
                auto g0 = CircularArcCut(m.feed, cut_gap);
                g.append(g0);

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
    if(!m.cut.Check(err)){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(_fmin, _fmax, err)){
        return{};
    }
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
        if(err){
            *err=L("chord of arc too short: ")+QString::number(distance)+"mm";
        }
        return {};
    }

    msg=G2+ m.p0.ToString()+' '+m.p1.ToString()+' '+m.o.ToString();

    msg+= " h:"+GCode::r(m.cut.z);
    zInfo(msg);

    QString nameComment = m.GetComment();
    QStringList g(nameComment);

    auto g2 = CircularArcCut(m.feed, m.cut);
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
    msg = "(time[min]: "+QString::number(_total_minutes)+")";
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
    if(!m.cut.Check(err)){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(_fmin, _fmax, err)){
        return{};
    }
    //SetSelectedFeed(m.feed);
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
        if(m.size.isValid()){ // ha van méret megadva az az elsődleges
            _lastBox.p1=GeoMath::Translation(_lastBox.p0,m.size.width(), m.size.height());
        } else if(m.rp.isValid() && _lastBox.p1.isValid()){
            _lastBox.p1=GeoMath::Translation(_lastBox.p1,m.rp);
        }
    }


    qreal distance = GeoMath::Distance(_lastBox.p0, _lastBox.p1);
    if(distance<(t.d/1.4)) {
        if(err){
            *err=L("box diagonal too short: ")+QString::number(distance)+"mm";
        }
        return {};
    }



    /*rectangle normalizálás*/
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

    QString nameComment = m.GetComment();
    QStringList g(nameComment);

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

    /*szerszámpálya*/
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

    bool isRounding = _lastBox.type!=BoxType::Corners && m.rounding>0;

    bool isR0 = m.nl[0]!=0&&m.nl[1]!=0;//0
    bool isR1 = m.nl[1]!=0&&m.nl[2]!=0;//1
    bool isR2 = m.nl[2]!=0&&m.nl[3]!=0;//2
    bool isR3 = m.nl[3]!=0&&m.nl[0]!=0;//3

    bool isR0m = false;
    bool isR1m = false;
    bool isR2m = false;
    bool isR3m = false;

//    for(int k=0;k<4;k++){
//        if(m.nr[k]==false){
//            zInfo("hutty");
//        }
//    }
    if(isRounding){
        qreal rounding_r = m.rounding-tool_r;        
        //0
        if(isR0){
            ja1.x-=rounding_r;
            ja2.y+=rounding_r;
        } else{
            if(m.nr[0]){
                if(m.rjoin==1 ){
                    if(m.nl[0]==1||m.nl[1]==1){
                    ja1.x-=rounding_r;
                    ja2.y+=rounding_r;
                    isR0=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[0]==0 && m.nl[1]==1){
                            ja1.x+=rounding_r;
                            ja1.y-=t.d;
                            ja2.y+=rounding_r-t.d;
                            isR0m=true;
                        } else if(m.nl[0]==1 && m.nl[1]==0){
                            ja1.x-=rounding_r-t.d;
                            ja2.x+=t.d;
                            ja2.y-=rounding_r;
                            isR0m=true;
                        }
                        isR0=true;
                    } else {
                        if(m.nl[0]==0 && m.nl[1]==1){
                            ja1.x+=rounding_r+t.d;
                            ja2.y+=rounding_r;
                            isR0m=true;
                        } else if(m.nl[0]==1 && m.nl[1]==0){
                            ja1.x-=rounding_r;
                            ja2.y-=rounding_r+t.d;
                            isR0m=true;
                        }
                        isR0=true;
                    }
                }
            }
        }
        //1
        if(isR1){
            jf2.y-=rounding_r;
            jf3.x-=rounding_r;
        }else{
            if(m.nr[1]){
                if(m.rjoin==1 /*|| !m.nr[1]*/){
                    if(m.nl[1]==1||m.nl[2]==1){
                        jf2.y-=rounding_r;
                        jf3.x-=rounding_r;
                        isR1=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[1]==0&&m.nl[2]==1){
                            jf2.y+=rounding_r;
                            jf2.x+=t.d;
                            jf3.x-=rounding_r-t.d;
                            isR1m=true;
                        }
                        else if (m.nl[1]==1 &&m.nl[2]==0){
                            jf2.y-=rounding_r-t.d;
                            jf3.y+=t.d;
                            jf3.x+=rounding_r;
                            isR1m=true;
                        }
                    isR1=true;
                    } else{
                        if(m.nl[1]==0 && m.nl[2]==1){ //ez
                            jf3.x-=rounding_r;
                            jf2.y+=rounding_r+t.d;
                            isR1m=true;
                        } else if(m.nl[1]==1 && m.nl[2]==0){
                            jf2.y-=rounding_r;
                            jf3.x+=rounding_r+t.d;
                            isR1m=true;
                        }
                        isR1=true;
                    }
                }
            }
        }
        //2
        if(isR2){
            bf3.x+=rounding_r;
            bf4.y-=rounding_r;
        }else{
            if(m.nr[2]){
                if(m.rjoin==1){
                    if(m.nl[2]==1||m.nl[3]==1){
                        bf3.x+=rounding_r;
                        bf4.y-=rounding_r;
                        isR2=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[2]==0&&m.nl[3]==1){
                            bf3.x-=rounding_r;
                            bf3.y+=t.d;
                            bf4.y-=rounding_r-t.d;//+
                            isR2m=true;
                        }
                        else if(m.nl[2]==1&&m.nl[3]==0){
                            bf3.x+=rounding_r-t.d;
                            bf4.x-=t.d;
                            bf4.y+=rounding_r;
                            isR2m=true;
                        }
                        isR2=true;
                    } else{
                        if(m.nl[2]==0 && m.nl[3]==1){
                            bf3.x-=rounding_r+t.d;
                            bf4.y-=rounding_r;
                            isR2m=true;
                        } else if(m.nl[2]==1 && m.nl[3]==0){
                            bf3.x+=rounding_r;
                            bf4.y+=rounding_r+t.d;
                            isR2m=true;
                        }
                        isR2=true;
                    }
                }
            }
        }
        //3
        if(isR3){
            ba1.x+=rounding_r;
            ba4.y+=rounding_r;
        }else{
            if(m.nr[3]){
                if(m.rjoin==1){
                    if(m.nl[3]==1||m.nl[0]==1)
                    {
                        ba1.x+=rounding_r;
                        ba4.y+=rounding_r;
                        isR3=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[3]==0&&m.nl[0]==1){
                            ba1.x+=rounding_r-t.d;
                            ba4.x-=t.d;
                            ba4.y-=rounding_r;
                            isR3m=true;
                        }
                        else if(m.nl[3]==1&&m.nl[0]==0){
                            ba1.x-=rounding_r;
                            ba1.y-=t.d;
                            ba4.y+=rounding_r-t.d;
                            isR3m=true;
                        }

                        isR3=true;
                    } else{
                        if(m.nl[3]==0 && m.nl[0]==1){
                            ba1.x+=rounding_r;
                            ba4.y-=rounding_r+t.d;
                            isR3m=true;
                        } else if(m.nl[3]==1 && m.nl[0]==0){//ez
                            ba4.y+=rounding_r;
                            ba1.x-=rounding_r+t.d;
                            isR3m=true;
                        }
                        isR3=true;
                    }
                }
            }
        }
    }

    msg=G2+ ba.ToString()+' '+jf.ToString();
    msg+=' '+BoxType::ToString(_lastBox.type);
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    msg+=" d"+GCode::r(_last_hole_diameter);
    msg+=' '+m.gap.ToString();

    zInfo(msg);

    if(_lastBox.type == BoxType::Corners){

        QVarLengthArray<Hole> holes = {
            {ba, _last_hole_diameter, m.cut, m.feed, {}, m.jointGap, {}, false,false, m.name+":1_ba"},
            {ja, _last_hole_diameter, m.cut, m.feed, {}, m.jointGap, {}, false,false, m.name+":2_ja"},
            {jf, _last_hole_diameter, m.cut, m.feed, {}, m.jointGap, {}, false,false, m.name+":3_jf"},
            {bf, _last_hole_diameter, m.cut, m.feed, {}, m.jointGap, {}, false,false, m.name+":4_bf"}
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
        qreal z2 = hasGaps?m.cut.z-m.gap.height:m.cut.z;
        QVarLengthArray<Line> lines_border;
        QVarLengthArray<Arc> arcs;
        Cut cut_border;//{z2, _last_cut.z0};
        if(z2>0){
            cut_border = {z2, m.cut.z0};

            if(m.vcorner_x>0){
                //1
                ba1.x+=m.vcorner_x;
                ja1.x-=m.vcorner_x;

                //4
                bf3.x+=m.vcorner_x;
                jf3.x-=m.vcorner_x;
            }
            if(m.vcorner_y>0){
                //2
                ja2.y+=m.vcorner_y;
                jf2.y-=m.vcorner_y;

                //3
                ba4.y+=m.vcorner_y;
                bf4.y-=m.vcorner_y;
            }

            lines_border= {
                {ba1,ja1, cut_border, m.feed,{}, {}, m.name+" border 1 ba1,ja1"},
                {ja2,jf2, cut_border, m.feed,{}, {}, m.name+" border 2 ja2,jf2"},
                {jf3,bf3, cut_border, m.feed,{}, {}, m.name+" border 3 jf3,bf3"},
                {bf4,ba4, cut_border, m.feed,{}, {}, m.name+" border 4 bf4,ba4"}};
            }

        if(isRounding){
            Cut cut = {m.cut.z,m.cut.z0};
            if(isR0){
                if(isR0m)
                    arcs.append({ja1, ja2, {ja1.x, ja2.y,ja2.z}, cut, m.feed, {0,0,0}, m.name+" rounding 1 ja1,ja2"});
                else
                    arcs.append({ja2, ja1, {ja1.x, ja2.y,ja2.z}, cut, m.feed, {0,0,0}, m.name+" rounding 1 ja2,ja1"});
            }
            if(isR1){
                if(isR1m)
                    arcs.append({jf2, jf3, {jf3.x, jf2.y,jf2.z}, cut, m.feed, {0,0,0},  m.name+" rounding 2 jf2,jf3"});
                else
                    arcs.append({jf3, jf2, {jf3.x, jf2.y,jf2.z}, cut, m.feed, {0,0,0},  m.name+" rounding 2 jf3,jf2"});
            }
            if(isR2){
                if(isR2m)
                    arcs.append({bf3, bf4, {bf3.x, bf4.y,bf4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 3 bf3,bf4"});
                else
                    arcs.append({bf4, bf3, {bf3.x, bf4.y,bf4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 3 bf4,bf3"});
            }
            if(isR3){
                if(isR3m)
                    arcs.append({ba4, ba1, {ba1.x, ba4.y,ba4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 4 ba4,ba1"});
                else
                    arcs.append({ba1, ba4, {ba1.x, ba4.y,ba4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 4 ba1,ba4"});
            }
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

            auto cz0 = m.gap.height<m.cut.z0?m.gap.height:m.cut.z0;
            Cut cut_gap{m.gap.height,  cz0};

            lines_gap = {
                {ba1,ja1, cut_gap, m.feed,{},{}, m.name+" gap 1 ba1,ja1"},
                {ja2,jf2, cut_gap, m.feed,{},{}, m.name+" gap 2 ja2,jf2"},
                {jf3,bf3, cut_gap, m.feed,{},{}, m.name+" gap 3 jf3,bf3"},
                {bf4,ba4, cut_gap, m.feed,{},{}, m.name+" gap 4 bf4,ba4"}
            };
        }
        zInfo(L("(segments)"));
        QList<Line> segments;

        qreal l0 = 0;
        qreal l1 = 0;
        if(lines_border.length()>=4){
            l0 = lines_border[0].Length();
            l1 = lines_border[1].Length();


            qreal l_min = l0<l1?l0:l1;
            qreal l_max = l0>l1?l0:l1;
            //qreal m_min = (l0<l1?l0:l1)/m.gap.n+1;
            qreal gap_max_l = l_max/m.gap.n+1;

            for(int i=0;i<4;i++){
                if(m.nl[i]==0) continue;
                auto&l_border=lines_border[i];
                if(lines_border.length()>i){

                    //l_border.length();
                    //if(cut_border.z>0){ segments.append(l_border);}
                    segments.append(l_border);
                }
                if(hasGaps){
                    qreal l = l_border.Length();
                    auto gap2 = m.gap;
                    if(l<gap_max_l){
                        gap2.n = 1;
                    } else{
                        gap2.n = m.gap.n;
                    }
                    auto&l_gap=lines_gap[i];
                    auto s = l_gap.Divide(gap2, t.d);
                    if(s.isEmpty()){
                        zInfo(QStringLiteral("cannot divide line"));
                        segments.append(l_gap);
                    }else{
                        segments.append(s);
                    }
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
            QString e0;
            auto px0 = _lastLine.p0;
            auto px1 = _lastLine.p1;
            auto g0 = LineToGCode(bl,&e0);
            if(!g0.isEmpty()){
                g.append(g0);
            } else{
                if(err){
                    if(!err->isEmpty()) *err+=",";
                    *err+=bl.name+": "+e0;
                }
                zInfo("segment gcode error");
            }
            _lastLine.p0 = px0; // azonnal vissza is állítjuk
            _lastLine.p1 = px1;
        }
        if(isRounding){
            for(auto&al:arcs){
                QString e0;
                auto px0 = _lastArc.p0;
                auto px1 = _lastArc.p1;
                auto pxo = _lastArc.o;
                auto g0 = ArcToGCode(al,&e0);
                if(!g0.isEmpty()){
                    g.append(g0);
                } else{
                    if(err){
                        if(!err->isEmpty()) *err+=",";
                        *err+=al.name+": "+e0;
                    }
                    zInfo("rounding gcode error");
                }
                _lastArc.p0 = px0; // azonnal vissza is állítjuk
                _lastArc.p1 = px1;
                _lastArc.o = pxo;
            }
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


bool GenerateGcode::SetFeedToGCode(qreal feed, QString *g, QString* err)
{
    bool ok = Feed::Check(feed, _fmin, _fmax, err);
    if(!ok) {
        if(feed>_fmax){
            zInfo("feed is too high:"+QString::number(feed));
            feed=_fmax;
        } else {
            zInfo("feed is too low:"+QString::number(feed));
            //feed=_fmax;
        }
    }
    if(_last_feed3.feed() != feed)
    {
        _last_feed3.setFeed(feed);
        if(g) *g = Feed::ToStringFeed(feed);
    }
    return true;
}

bool GenerateGcode::SetSpindleSpeedToGCode(qreal spindle_speed, QString *g, QString* err)
{
    if(spindle_speed<=0){
        if(err) *err = L("no spindle speed available");
        return false;
    }
    if(_last_feed3.spindleSpeed() != spindle_speed){
        if(g) *g= Feed::ToStringSpindleSpeed(spindle_speed);
    }
    return true;
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
    g.append(TravelXYToGCode(_selected_feed3.feed(),_safe_place));
    //g.append(TravelXYToGCode({0,0,0}));//kiáll nullára
    auto maxZ = _maxZ;//GCode::_variables.maxZ();

    g.append(QStringLiteral("g0 z")+GCode::r(maxZ));
    g.append('t'+QString::number(t.ix)+" (tool select)");
    g.append(QStringLiteral("m6 (tool change)"));
    g.append(QStringLiteral("(msg, change tool to ")+Tool::TypeToString(t.type)+
             ", diameter="+GCode::r(t.d)+')');
    g.append(QStringLiteral("m0 (machine stop)"));
    g.append(QStringLiteral("g0 z")+GCode::r(maxZ));

    _last_tool_ix=_selected_tool_ix;

    return g.join('\n');
}

auto GenerateGcode::SpindleStartToGCode(qreal spindle_speed) ->QString
{
    auto const M3 = QStringLiteral("m3");

    if(spindle_speed<=0) return {};


    QString sp;
    bool set_ok = SetSpindleSpeedToGCode(spindle_speed, &sp);

    if(set_ok){
        QString g = M3;
        QString comment;

        if(!sp.isEmpty()){ // kellett speedet állítani
            _last_feed3.setSpindleSpeed(spindle_speed);

            g+=+' '+sp;
            if(!comment.isEmpty()) comment+=", ";
            comment +="set spindle speed";

        } else{
            if(_last_feed3.started()){
                return {};
            }

        }
        _last_feed3.setStarted(true);

        if(!comment.isEmpty()) comment+=", ";
        comment += "spindle start";
        g+=" ("+comment+")";
        return g;
    }

    return {};
}

auto GenerateGcode::SpindleStopToGCode() ->QString
{
    _last_feed3.setStarted(false);
    return QStringLiteral("m5 (spindle stop)");    
}

/*Move*/
auto GenerateGcode::GoToZ(GMode::Mode i, const Point& p, qreal length, qreal feed) -> QString
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
        if(feed<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = feed;
            _total_cut+=length;
        }
//        if(feed.spindleSpeed()<=0){
//            zInfo(Messages::zero_spindleSpeed);
//            // return {};
//        }
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
            qreal t0_mins = length/v;
            _total_minutes+=t0_mins;
        }
    } else {
        zInfo(Messages::zero_spindleSpeed)
    }

    return GMode::ToGCcode(i)+' '+p.ToStringZ();
}

auto GenerateGcode::GoToXY(GMode::Mode i, const Point& p, qreal length, qreal feed) -> QString
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
        if(feed<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = feed;
            if(i==GMode::Mode::Linear)
            {
                _total_cut+=length;
            }
        }
//        if(feed.spindleSpeed()<=0){
//            zInfo(Messages::zero_spindleSpeed);
//           // return {};
//        }
    }
    else if(i==GMode::Rapid){
        v=1500;
    }

    _last_position.x = p.x;
    _last_position.y = p.y;
    _last_gmode=i;


    if(length>0){
        if(i==GMode::Mode::Linear){
            _total_length+=length;
            if(v<=0){
                zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
            } else{
                qreal t0_mins = length/v;
                _total_minutes+=t0_mins;
            }
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
    qreal t0_mins = p/1500;
    _total_minutes+=t0_mins;
    auto str =  "G04 P"+QString::number(p);
    //QString str;
    return str;
}

auto GenerateGcode::GoToXYZ(GMode::Mode i, const Point& p, qreal length, qreal feed) -> QString
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

        if(feed<=0){
            zInfo(Messages::zero_feed);
        } else{            
            v = feed;
        }
//        if(feed<=0){
//            zInfo(Messages::zero_spindleSpeed);
//        }
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
            if(i!=GMode::Rapid){
                _total_cut+=length;
                qreal t0_mins = length/v;
                _total_minutes+=t0_mins;
            }
        }
    } else {
        zInfo(Messages::no_calc_length)
    }

    QString a = (_ratio>0&&_ratio!=1)?p.ToStringXYZ(_ratio):p.ToStringXYZ();

    return GMode::ToGCcode(i)+' '+a;
}
