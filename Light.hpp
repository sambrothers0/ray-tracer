#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "rt.hpp"
#include "scene.hpp"

// class definition for light class which provides definitions for illuminate and shadow test functions
class Light {
private:
    Vec loc;

    static bool shadow_test(Vec intersection, SCENE_T scene, Object &object, Light light);

public:
    Light(Vec location);

    Color illuminate(RAY_T ray, Object &object, Vec intersection, Vec normal, SCENE_T scene, Light light);
};

#endif