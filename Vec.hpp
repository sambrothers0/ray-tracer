#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>

// vec class 
class Vec {
private: 
	double x;
	double y;
	double z;

// class definition for color, containing arithmetic operations, cap function, and getter functions for color channels
public:
    Vec(double x, double y, double z);

	inline Vec() : x(0.0), y(0.0), z(0.0) {}

    void set(double newX, double newY, double newZ);

    void normalize();

	inline double dot(const Vec &v) { return x * v.x + y * v.y + z * v.z; }

	inline double len() { return std::sqrt(x * x + y * y + z * z); }

	Vec add(const Vec &v);

    Vec operator+(const Vec &v);

	Vec sub(const Vec &v);

	Vec operator-(const Vec &v);

	Vec mult(const Vec &v);

    Vec operator*(const Vec &v);

	Vec scalar_mult(double scalar);

    Vec operator*(double scalar);

	Vec scalar_divide(double scalar);

    Vec operator/(double scalar);

	inline double sum_components() { return x + y + z; }

	int sum_floor_components();
};

#endif