#ifndef PLANE_HPP
#define PLANE_HPP

#include "rt.hpp"
#include "Object.hpp"

class Plane : public Object {
private:
    Vec normal;
    double D;
    
public:

    Plane(Vec normal, double D, Color color, bool checker, Color color2);
    // this funciton extends the intersect function from the object parent class
    virtual bool intersect(RAY_T ray, double &t, Vec &intersection, Vec &normal) override;
};

#endif