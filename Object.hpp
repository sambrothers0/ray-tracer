#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Color.hpp"
#include "Vec.hpp"

// class definition for object which has color checker and next attributes
class Object {
public:
    Color color;
    bool checker;
    Color color2;
    Object *next;

    virtual bool intersect(RAY_T ray, double &t, Vec &intersection, Vec &normal) { 
        return false;
    }

};

#endif