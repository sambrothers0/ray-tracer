#ifndef SCENE_HPP
#define SCENE_HPP

#include "Object.hpp"

//this is the definition for the scene struct
typedef struct {
    Object *objs;
    double start_x;
    double start_y;
    double pixel_size;

} SCENE_T;

#endif