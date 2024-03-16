// #ifndef COMPENSATE_H
// #define COMPENSATE_H

// #include "gcode/cut.h"
// #include "gcode/feed.h"
// #include "generategcode.h"
// #include "qglobal.h"

// #include <QStringList>
// class Compensation
// {
// public:
//     enum Type:int{
//         none=0, speed=1, depth=2
//     };

//     enum LengthMode:int{XYZ,XY,Z
//     };

//     //    Compensation GetCompensation(qreal l, qreal z);
//     //    qreal CompensateSpeed(qreal l, qreal z);
//     bool Compensate(qreal l, qreal z, qreal *s3, qreal *f3, qreal f_in,GenerateGcode::ToGCodeModel* mm);

//     struct CompensateModel{
//         qreal c_f = -1;
//         qreal c_z = -1;
//         bool isCompensated;

//         void ToGCode(QStringList* g, const Cut& o_cut, const Feed& o_feed);
//     };

//     CompensateModel Compensate2(qreal l, const Cut& cut, const Feed& feed);

// };

// #endif // COMPENSATE_H
