#include <iostream>
#include <cmath>

#include "Sphere.hpp"

// this is the constructor for sphere, which takes five values as a parameter 
Sphere::Sphere(Vec center, double radius, Color color, bool checker, Color color2) 
    : center(center), radius(radius) {
        this->color = color;
        this->checker = checker;
        this->color2 = color2;
    }

// this function determines whether a given ray intersects the sphere object
bool Sphere::intersect(RAY_T ray, double &t, Vec &intersection, Vec &normal) {
    double A = 1;
    double B = 2 * (ray.dir * (ray.origin - this->center)).sum_components();
    double C = ((ray.origin - this->center) * (ray.origin - this->center)).sum_components() -
               (this->radius * this->radius);
    
    double discrim = (B * B) - 4 *(A * C);

    if (discrim <= 0) {
    	return false;
    }

    double t_a = (-B + std::sqrt(B * B - 4 *(A * C))) / (2 * A);
    double t_b = (-B - std::sqrt(B * B - 4 *(A * C))) / (2 * A);

    if (t_a < 0 && t_b < 0) {
        return false;
    }
    if (t_a <= t_b) {
        t = t_a;
    } else {
        t = t_b;
    }

    intersection = (ray.origin + Vec(t, t, t)) * ray.dir;

    normal = intersection - this->center;

    normal.normalize();

    return true;
 
}