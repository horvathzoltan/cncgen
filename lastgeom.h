#ifndef LASTGEOM_H
#define LASTGEOM_H

#include <geometry/boxtype.h>
#include <geometry/geomath.h>
#include <geometry/point.h>


class LastGeom
{
public:
    LastGeom();

    struct LastLine{
    private:
        Point _p0;
        Point _p1;

        Point _stored_p0;
        Point _stored_p1;
    public:
        Point p0(){return _p0;}
        Point p1(){return _p1;}

        void setP0(const Point& v){_p0 = v;}
        void setP1(const Point& v){_p1 = v;}

        void set(const Point& a, const Point& b){
            _p0 = a;
            _p1 = b;
        }

        QString toString();
        qreal Distance(){ return GeoMath::Distance(_p0, _p1); }

        void Reset();
        void Store();
        void Retrieve();
    };


    struct LastBox{
    private:
        Point _p0;
        Point _p1;
        BoxType::Type _type;

        Point _stored_p0;
        Point _stored_p1;
    public:
        Point p0(){return _p0;}
        Point p1(){return _p1;}

        void setP0(const Point& v){_p0 = v;}
        void setP1(const Point& v){_p1 = v;}

        BoxType::Type type(){return _type;}
        void setType(BoxType::Type v){_type = v;}

        qreal Distance(){ return GeoMath::Distance(_p0, _p1); }

        void Reset();
        void Store();
        void Retrieve();

    };


    struct LastArc{
    private:
        Point _p0;
        Point _p1;
        Point _o;

        Point _stored_p0;
        Point _stored_p1;
        Point _stored_o;
    public:
        Point p0(){return _p0;}
        Point p1(){return _p1;}
        Point o(){return _o;}

        qreal i1(){return _o.x-_p0.x;}
        qreal j1(){return _o.y-_p0.y;}
        qreal i0(){return _o.x-_p1.x;}
        qreal j0(){return _o.y-_p1.y;}

        qreal maxZ(){return qMax(_p0.z, _p1.z);}
        QString toString();

        qreal ArcLength(){return GeoMath::ArcLength(_p0,_p1, _o);}
        qreal Distance(){return GeoMath::Distance(_p0,_p1);}

        void Reset();
        void Store();
        void Retrieve();

        void set(const Point& a, const Point& b, const Point& c){
            _p0 = a;
            _p1 = b;
            _o = c;
        }

        void setP0(const Point& v){_p0 = v;}
        void setP1(const Point& v){_p1 = v;}
        void setO(const Point& v){_o = v;}
    };

    Point _lastHoleP;

    struct LastPosition{
    private:
        Point _p;
    public:
        Point p(){return _p;}
        qreal z(){return _p.z;}

        void set(qreal a, qreal b, qreal c){_p.x = a; _p.y = b; _p.z = c;}
        void set(const Point& p1){_p = p1;}
        void setZ(qreal v){_p.z = v;}
        void setXY(qreal a, qreal b){_p.x = a; _p.y = b;}

        qreal Distance(const Point& p1){ return GeoMath::Distance(_p, p1); }

        qreal DistanceXY(const Point& p1){
            return GeoMath::Distance({_p.x, _p.y, 0}, {p1.x, p1.y, 0}); }

        void Reset();
    };



    LastPosition _last_position;
    LastLine _lastLine;
    LastBox _lastBox;
    LastArc _lastArc;
public:
    void Reset();

};

#endif // LASTGEOM_H
