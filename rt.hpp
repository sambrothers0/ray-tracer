#ifndef RT_HPP
#define RT_HPP

#include "Vec.hpp"

// ray struct containing an origin and direction vector
typedef struct {
	Vec origin;
	Vec dir;
} RAY_T;

#endif