#ifndef GMODE_H
#define GMODE_H

#include <QString>

class GMode{
public:
    enum Mode:int{Undefined=-1,Rapid=0,Linear=1,Circular=2,Circular_ccw=3};

    static QString ToGCcode(Mode i);
};



#endif // GMODE_H
