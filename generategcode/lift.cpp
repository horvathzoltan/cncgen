#include "gcodemanager.h"
#include "goto.h"
#include "lift.h"

#include <QStringLiteral>

QString Lift::Down(qreal feed, qreal z,ToGCodeModel *tmm,TotalStats *tss)
{
    GCodeManager g;
    QString err;

    qreal safez = tmm->_safez+1;//(_safez!=0)?_safez:1;
    if(tmm->_lastGeom._last_position.z()==z){ return {};}
    auto z2 = z+safez; // z2-ig gyorsan megyünk
    //qreal l = _last_position.z-z2;AppendGCode
    auto gcode = GoTo::GoToZ(GMode::Rapid,{0,0,z2}, feed, tmm,tss);//+ " (lift down)";
    g.Append(gcode, err, QStringLiteral("lift down"));
    //l = _last_position.z-z;
    gcode = GoTo::GoToZ(GMode::Linear,{0,0,z}, feed, tmm,tss);//+ " (push)";
    g.Append(gcode, err, QStringLiteral("push"));

    return g.toString();
}

QString Lift::Up(qreal feed, const QVariant& z, ToGCodeModel *tmm,TotalStats *tss)
{
    GCodeManager g;
    QString err;
    auto movZ = tmm->_movZ;// GCode::_variables.movZ();
    if(tmm->_lastGeom._last_position.z() >=movZ){ return {};}
    if(!z.isNull()){
        auto z0 = z.value<double>();
        //qreal l = z0-_last_position.z;
        auto gcode = GoTo::GoToZ(GMode::Linear,{0,0,z0}, feed, tmm,tss);//+ " (pull)";
        g.Append(gcode, err, QStringLiteral("pull"));
    }
    //qreal l = movZ-_last_position.z;
    auto gcode = GoTo::GoToZ(GMode::Rapid,{0,0,movZ}, feed, tmm,tss);// + "(lift up)";
    g.Append(gcode, err, "lift up");
    return g.toString();
}
