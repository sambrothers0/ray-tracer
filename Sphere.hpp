#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "rt.hpp"
#include "Object.hpp"

class Sphere : public Object {
private:
    Vec center;
    double radius;
    
public:

    Sphere(Vec center, double radius, Color color, bool checker, Color color2);
    // this funciton extends the intersect function from the object parent class
    virtual bool intersect(RAY_T ray, double &t, Vec &intersection, Vec &normal) override;
};

#endif