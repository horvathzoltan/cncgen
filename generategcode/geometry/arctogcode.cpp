#include "arctogcode.h"

#include "helpers/logger.h"
#include <QtMath>

#include <helpers/stringhelper.h>

#include <gcode/gcode.h>

#include <generategcode/cuts/circulararccut.h>
#include <generategcode/cuts/helicalcut.h>
#include <generategcode/cuts/linearcut.h>

#include <generategcode/compensation.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/tooltogcode.h>

bool ArcToGCode::ParseArc(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss)
{
    Arc m;
    auto s = Arc::Parse(str, tmm->_XYMode, &m, tmm->_MMode, tmm->_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed ) // ha Arc típusú sor
    {
        if(tmm->_isPlot){
            ToolToGCode::SetToolToPen({&m.p0, &m.p1, &m.o, &m.rp}, nullptr, &m.cut, &m.feed, tmm);
        }else{
            if(tmm->_safez>0){
                m.p0.z+=tmm->_safez;
                m.p1.z+=tmm->_safez;
                m.o.z+=tmm->_safez;
                // m.rp.z+=_safez;

                m.cut.z+=tmm->_safez;
            }
            if(tmm->_safeb>0){
                m.cut.z+=tmm->_safeb;
            }
            if(tmm->_overcut>0){
                m.cut.z+=tmm->_overcut;
            }

            if(!m.feed.Check(tmm->_fmin, tmm->_fmax)){
                if(tmm->_selected_feed3.Check(tmm->_fmin, tmm->_fmax,err)){
                    m.feed = tmm->_selected_feed3;
                }
            }
        }

        if(gcode)*gcode=ArcToGCode::CreateArc(m,err,tmm, tss);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

QString ArcToGCode::CreateArc(const Arc& m ,QString* err, ToGCodeModel* tmm,TotalStats *tss)
{
    QString msg = GCodeCommon::G1+m.ToString();
    StringHelper::Tabulate(&msg, GCodeCommon::G2);
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
    auto cutCheckResult = m.cut.Check(err);
    if(cutCheckResult == Cut::CheckR::invalid){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(tmm->_fmin, tmm->_fmax, err)){
        return{};
    }
    /*TOOL*/
    if(!tmm->ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = tmm->selectedTool();
    if(d01<t.d){
        if(err){*err=L("wrong length: ")+GCode::r(d01)+
                   " tool: "+t.ToString();
        }
    }

    /**/
    if(m.p0.isValid()){
        tmm->_lastGeom._lastArc.setP0(m.p0);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastArc.p0().isValid()){
            tmm->_lastGeom._lastArc.p0().Translate(m.rp);
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }

    if(m.p1.isValid()){
        tmm->_lastGeom._lastArc.setP1(m.p1);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastArc.p1().isValid()){
            tmm->_lastGeom._lastArc.p1().Translate(m.rp);
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(m.o.isValid()){
        tmm->_lastGeom._lastArc.setO(m.o);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastArc.o().isValid()){
            tmm->_lastGeom._lastArc.o().Translate(m.rp);
        } else {
            if(err){*err=L("o not valid");}
            return {};
        }
    }

    if(tmm->_lastGeom._lastArc.p0()==tmm->_lastGeom._lastArc.p1()){
        if(err){*err=L("start and end points are equal");}
        return{};
    }

    auto distance = tmm->_lastGeom._lastArc.Distance();
    if(distance<t.d) {
        if(err){
            *err=L("chord of arc too short: ")+QString::number(distance)+"mm";
        }
        return {};
    }

    msg=GCodeCommon::G2+ m.p0.ToString()+' '+m.p1.ToString()+' '+m.o.ToString();

    msg+= " h:"+GCode::r(m.cut.z);
    zInfo(msg);

    QString nameComment = m.GetComment();
    QStringList g(nameComment);

    auto g2 = CircularArcCut::CreateCut(m.feed, m.cut, true,tmm, tss);
    g.append(g2);

    g.append(tss->TotalTimeToGCode());
    return g.join('\n');
}

