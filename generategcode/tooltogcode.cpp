#include "helpers/logger.h"
#include "gcodecommon.h"
#include "goto.h"
#include "spindle.h"
#include "tooltogcode.h"

#include <gcode/gcode.h>

#include <helpers/stringhelper.h>

bool ToolToGCode::ParseTool(const QString& str, QString *gcode, QString *err, ToGCodeModel* tmm,TotalStats *tss)
{
    Tool m;
    auto s = Tool::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    QString msg(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed )
    {
        if(gcode)*gcode=ToolToGCode::SetToGCode(m, err, tmm, tss);
    }
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

void ToolToGCode::SetToolToPen(QList<Point*> points, Gap *gap, Cut* cut, Feed* feed, ToGCodeModel *tmm){
    for(auto&a:points){
        if(a && a->z<0) a->z=0;
    }

    tmm->setSelectedToolD(0.5);

    if(gap){
        gap->height = 0.01;
    }

    if(cut){
        cut->z = 0.02;
        cut->z0 = 0.02;
    }

    if(feed){
        feed->setFeed(tmm->_fmax);
    }
}

QString ToolToGCode::ChangeToGCode(ToGCodeModel *tmm,TotalStats *tss)
{
    int six = tmm->seletcedToolIx();
    if(six==-1){
        zInfo(QStringLiteral("no tool selected"));
        return {};
    }
    if(!tmm->toolsContains(six)) {
        zInfo(QStringLiteral("tool not found: ")+QString::number(six));
        return {};
    }
    if(tmm->_last_tool_ix == six){
        zInfo(QStringLiteral("tool not changed"));
        return {};
    }

    Tool t = tmm->selectedTool();

    QStringList g;

    g.append(QStringLiteral("(change tool)"));
    g.append(Spindle::StopToGCode(tmm));//spindle stop
    g.append(GoTo::TravelXYToGCode(tmm->_selected_feed3.feed(),tmm->_safe_place, tmm,tss));
    //g.append(TravelXYToGCode({0,0,0}));//kiáll nullára
    auto maxZ = tmm->_maxZ;//GCode::_variables.maxZ();

    g.append(QStringLiteral("g0 z")+GCode::r(maxZ));
    g.append('t'+QString::number(t.ix)+" (tool select)");
    g.append(QStringLiteral("m6 (tool change)"));
    g.append(QStringLiteral("(msg, change tool to ")+Tool::TypeToString(t.type)+
             ", diameter="+GCode::r(t.d)+')');
    g.append(QStringLiteral("m0 (machine stop)"));
    g.append(QStringLiteral("g0 z")+GCode::r(maxZ));

    tmm->_last_tool_ix=six;

    return g.join('\n');
}

QString ToolToGCode::SetToGCode(Tool m, QString *err,ToGCodeModel* tmm,TotalStats *tss)
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

    if(tmm->toolsContains(m.ix)){ // ha van már ilyen tool
        if(m.type==Tool::None){ //selectelni akarjuk
            tmm->selectTool(m.ix);
            //g = 't'+QString::number(_selected_tool_ix)+"(change tool)";
            g=ChangeToGCode(tmm,tss);
        }
    }else{
        if(m.type!=Tool::None){ // beállítani akarjuk
            tmm->insertTool(m.ix, m); // ha nincs még ilyen tool
            //_selected_tool_ix = m.ix;
            g = "(set tool "+QString::number(m.ix)+" to "+m.ToString()+')';
            zInfo("tool "+QString::number(m.ix)+':'+m.ToString());
        }
    }
    return g;
}


