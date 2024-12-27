#include <cmath>

#include "Vec.hpp"

// implementations for non inline functions
Vec::Vec(double x, 
         double y, 
         double z) : x(x), y(y), z(z) {}

void Vec::set(double newX, double newY, double newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

void Vec::normalize() {
    double length = len();
    if (length > 0) {
        *this = *this / length;
    }
}

Vec Vec::add(const Vec &v) {
    return Vec(x + v.x, 
               y + v.y, 
               z + v.z);
}

Vec Vec::operator+(const Vec &v) {
    return Vec(x + v.x, 
               y + v.y, 
               z + v.z);
}

Vec Vec::sub(const Vec &v) {
    return Vec(x - v.x, 
               y - v.y, 
               z - v.z);
}

Vec Vec::operator-(const Vec &v) {
    return Vec(x - v.x, 
               y - v.y, 
               z - v.z);
}

Vec Vec::mult(const Vec &v) {
    return Vec(x * v.x, 
               y * v.y, 
               z * v.z);
}

Vec Vec::operator*(const Vec &v) {
    return Vec(x * v.x, 
               y * v.y, 
               z * v.z);
}

Vec Vec::scalar_mult(double scalar) {
    return Vec(x * scalar, 
               y * scalar, 
               z * scalar);
}

Vec Vec::operator*(double scalar) {
    return Vec(x * scalar, 
               y * scalar, 
               z * scalar);
}

Vec Vec::scalar_divide(double scalar) {
    return Vec(x / scalar, 
               y / scalar, 
               z / scalar);
}

Vec Vec::operator/(double scalar) {
    return Vec(x / scalar, 
               y / scalar, 
               z / scalar);
}

int Vec::sum_floor_components() {
    return std::floor(x) +
           std::floor(y) + 
           std::floor(z);
}