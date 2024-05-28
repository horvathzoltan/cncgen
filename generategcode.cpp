#include "generategcode/geometry/linetogcode.h"
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
//#include "geometry/geomath.h"
#include "gcode/feed.h"
#include "helpers/stringhelper.h"
#include "helpers/textfilehelper.h"
#include <QDir>
#include <generategcode/feedtogcode.h>
#include <generategcode/tooltogcode.h>
#include <generategcode/goto.h>
#include <generategcode/lift.h>
#include <generategcode/spindle.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/compensation.h>
#include <generategcode/stringtogcode.h>
#include <generategcode/commenttogcode.h>
#include <generategcode/mmodetogcode.h>
#include <generategcode/xymodetogcode.h>
#include <generategcode/geometry/arctogcode.h>
#include <generategcode/geometry/boxtogcode.h>
#include <generategcode/geometry/holetogcode.h>


const QString GenerateGcode::safeKey = L("safe");
const QString GenerateGcode::offsetKey = L("offset");
const QString GenerateGcode::safezKey = L("safetop");
const QString GenerateGcode::safebKey = L("safebottom");
const QString GenerateGcode::overcutKey = L("overcut");
const QString GenerateGcode::ratioKey = L("ratio");
const QString GenerateGcode::preMillStepsKey = L("pre_mill_steps");
const QString GenerateGcode::movzKey = L("movz");
const QString GenerateGcode::peckzKey = L("peckz");
const QString GenerateGcode::maxzKey = L("maxz");

const QString GenerateGcode::emaxKey = L("emax");
const QString GenerateGcode::fmaxKey = L("fmax");
const QString GenerateGcode::fminKey = L("fmin");
const QString GenerateGcode::fratioKey = L("fratio");
const QString GenerateGcode::pdwellKey = L("pdwell");

const QString GenerateGcode::peckslow = L("peckslow");
const QString GenerateGcode::peckfast = L("peckfast");
const QString GenerateGcode::simi = L("simi");
const QString GenerateGcode::pecktime = L("pecktime");

const QString GenerateGcode::nameKey = L("_");


//double GenerateGcode::dPeck_2 = 10;

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




void GenerateGcode::Init(){
    _gcodeManager.clear();
    _selected_cut ={};
    _toGCodeModel.Reset();
    _last_cut3 = {};
    _totalStats.Reset();
    GCode::_variables.Clear();
}

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{

    //static const QString G1;

    for(auto l:g){
        QString err;
        QString gcode;

        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        if(l.startsWith('#')) continue;
        if(l.startsWith('/')) continue;

        /*VARIABLE*/
        if(GCode::_variables.Parse(l)){
            zInfo(GCodeCommon::T1+l)
            continue;
        }

        /*PRINT*/
        if(l.startsWith(String::key)){
            if(StringToGcode::ParseString(l, &gcode, &err, true)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
        }

        /*CODE*/
        if(l.startsWith(String::key_code)){
            if(StringToGcode::ParseString(l, &gcode, &err, false)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
        }

        if(XYMode::ValidateLineType(l)){
            if(XYModeToGCode::ParseXYMode(l, &gcode, &err, &_toGCodeModel)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
        }

        if(MMode::ValidateLineType(l)){
            if(MModeToGCode::ParseMMode(l, &gcode, &err, &_toGCodeModel)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
        }

        if(Point::Parse(l, safeKey).state()!=ParseState::NoData){
            Point ps;
            auto s1 = Point::Parse(l,  _toGCodeModel._XYMode, _toGCodeModel._MMode, safeKey, &ps);
            if(s1.state()==ParseState::Parsed){
                _toGCodeModel._safe_place = ps;
            }
            continue;
        }

        if(Point::Parse(l, offsetKey).state()!=ParseState::NoData){
            Point ps;
            auto s1 = Point::Parse(l, _toGCodeModel._XYMode, _toGCodeModel._MMode, offsetKey, &ps);
            if(s1.state()==ParseState::Parsed){
                _toGCodeModel._offset_xyz = ps;
                QString msg = QStringLiteral("(offset:%1,%2,%3)").arg(ps.x).arg(ps.y).arg(ps.z);
                _gcodeManager.Append(msg, "");
            }
            continue;
        }

        if(l.startsWith(safezKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, safezKey, &r);
            if(isok) _toGCodeModel._safez = r;
            continue;
        }

        if(l.startsWith(safebKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, safebKey, &r);
            if(isok) _toGCodeModel._safeb = r;
            continue;
        }

        if(l.startsWith(overcutKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, overcutKey, &r);
            if(isok) _toGCodeModel._overcut = r;
            continue;
        }

        if(l.startsWith(movzKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, movzKey, &r);
            if(isok) _toGCodeModel._movZ = r;
            continue;
        }

        if(l.startsWith(peckzKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, peckzKey, &r);
            if(isok) _toGCodeModel._peckZ = r;
            continue;
        }

        //
        if(l.startsWith(peckslow)){
            int r;
            bool isok = GCode::ParseValue(l, peckslow, &r);
            if(isok) _toGCodeModel._peckslow = r;
            continue;
        }

        if(l.startsWith(peckfast)){
            int r;
            bool isok = GCode::ParseValue(l, peckfast, &r);
            if(isok) _toGCodeModel._peckfast = r;
            continue;
        }

        if(l.startsWith(simi)){
            int r;
            bool isok = GCode::ParseValue(l, simi, &r);
            if(isok) _toGCodeModel._simi = r;
            continue;
        }

        if(l.startsWith(pecktime)){
            int r;
            bool isok = GCode::ParseValue(l, pecktime, &r);
            if(isok) _toGCodeModel._pecktime = r;
            continue;
        }
        //
        if(l.startsWith(maxzKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, maxzKey, &r);
            if(isok) _toGCodeModel._maxZ = r;
            continue;
        }

        if(l.startsWith(ratioKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, ratioKey, &r);
            if(isok) _toGCodeModel._ratio = r;
            continue;
        }        

        if(l.startsWith(preMillStepsKey)){
            int r;
            bool isok = GCode::ParseValue(l, preMillStepsKey, &r);
            if(isok) _toGCodeModel._preMillSteps = r;
            continue;
        }

        if(l.startsWith(emaxKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, emaxKey, &r);
            if(isok) _toGCodeModel._emax = r;
            continue;
        }

        if(l.startsWith(fmaxKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fmaxKey, &r);
            if(isok) _toGCodeModel._fmax = r;
            continue;
        }

        if(l.startsWith(fminKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fminKey, &r);
            if(isok) _toGCodeModel._fmin = r;
            continue;
        }

        if(l.startsWith(fratioKey)){
            qreal r;
            bool isok = GCode::ParseValue(l, fratioKey, &r);
            if(isok) _toGCodeModel._fratio = r;
            continue;
        }

        if(l.startsWith(pdwellKey)){
            int r;
            bool isok = GCode::ParseValue(l, pdwellKey, &r);
            if(isok) _toGCodeModel._pdwell = r;
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
                    _gcodeManager.Append(gcodes3, err);
                } else{
                    zInfo("include: empty file: "+fn )
                }
            } else{
                zInfo("include is not ok")
            }
            continue;
        }

        /*FEED*/
        if(Feed::Parse(l).state()!=ParseState::NoData){
            FeedToGCode::ParseFeed(l, &_toGCodeModel);
            // if(, &gcode, &err)){
            //     AppendGCode(&gcodes, gcode, err);
            // }
            continue;
        }

        /*COMMENT*/
        switch(l[0].unicode()){
        case Comment::keyUniCode:
            if(CommentToGCode::ParseComment(l, &gcode, &err)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
            break;

        /*BOX*/
        case Box::keyUniCode:
            if(BoxToGCode::ParseBox(l, &gcode, &err, &_toGCodeModel, &_totalStats)){
                _gcodeManager.Append( gcode, err);
                continue;
             }
             break;
        /*HOLE*/
        case Hole::keyUniCode:
            if(HoleToGCode::ParseHole(l, &gcode, &err,&_toGCodeModel, &_totalStats)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
            break;
        /*LINE*/
        case Line::keyUniCode:
            if(LineToGCode::ParseLine(l, &gcode, &err,&_toGCodeModel, &_totalStats)){
                _gcodeManager.Append( gcode, err);
                continue;
            }
            break;
        /*ARC*/
        case Arc::keyUniCode:
            if(ArcToGCode::ParseArc(l, &gcode, &err,&_toGCodeModel, &_totalStats)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
            break;
        /*TOOL*/
        case Tool::keyUniCode:
            if(ToolToGCode::ParseTool(l, &gcode, &err, &_toGCodeModel, &_totalStats)){
                _gcodeManager.Append(gcode, err);
                continue;
            }
            break;
        }
    }

    _toGCodeModel._lastGeom._last_position.setZ(0);
    auto gc2=GoTo::TravelXYToGCode(_toGCodeModel._selected_feed3.feed(), _toGCodeModel._safe_place, &_toGCodeModel, &_totalStats);
    if(gc2.isEmpty()){
        zInfo("no safe place")
    } else {
        _gcodeManager.insert(0, gc2);
        _gcodeManager.insert(1, '('+Messages::travelSafe+')');
        _gcodeManager.append(gc2);
        _gcodeManager.append('('+Messages::travelSafe+')');
    }

    return _gcodeManager.gcodes();
}


// todo 11 circle: c - mint a hole, csak nincs belül kimarva - a gaps eset -> ventillátor kivágás
// todo 12 o: forgatás minden elemre - o középpont, és szög



// a true => csigába lemegy, false: oda-vissza megy le


/*Move*/





