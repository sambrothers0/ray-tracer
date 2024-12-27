#include <iostream>

#include "Plane.hpp"

// this is constructor for plane objects which takes five arguments
Plane::Plane(Vec normal, double D, Color color, bool checker, Color color2) 
    : normal(normal), D(D) {
        this->color = color;
        this->checker = checker;
        this->color2 = color2;
    }

// this function performs the intersection test for plane objects to see if a particular
// ray intersects the plane
bool Plane::intersect(RAY_T ray, double &t, Vec &intersection, Vec &normal) {
    double dp = this->normal.dot(ray.dir);
    if (!dp) {
        return false;
    }

    t = -(this->normal.dot(ray.origin) + this->D) / dp;

    if (t < 0) {
        return false;
    }

    intersection = (ray.origin + Vec(t, t, t)) * ray.dir;

    normal = this->normal;

    return true;
}