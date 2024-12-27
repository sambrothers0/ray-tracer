#include <stdlib.h>
#include <iostream>
#include <cmath>

#include "Vec.hpp"
#include "Light.hpp"
#include "Color.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

Light::Light(Vec location) : loc(location) {}

// this function tests whether or not a particular point is inside the shadow of another object
bool Light::shadow_test(Vec intersection, SCENE_T scene, Object &object, Light light) {
    RAY_T ray;

    double t;

    Vec dmy_intersection;
    Vec dmy_normal;

    ray.origin = intersection;

    ray.dir = light.loc - intersection;

    ray.dir.normalize();

    Object *cur = scene.objs;
    for (cur = scene.objs; cur != NULL; cur = cur->next) {
        if ((cur != &object) && 
            (cur -> intersect(ray, t, dmy_intersection, dmy_normal))) { // MAY NEED ATTENTION
            return true;
        }   
    }
    return false;
}

// this function handles the light calculations for rays that get cast on the objects
// it includes ambient, diffuse, and specular light, as well as light attentuation
// at a distance.
Color Light::illuminate(RAY_T ray, Object &object, Vec intersection, Vec normal, SCENE_T scene, Light light) {
    Color color;

    Color object_color = object.color;

    if (object.checker && (intersection.sum_floor_components() & 1)) {
        object_color = object.color2;
    }
    // ambient lighting calculation
    double ambient = 0.1;
    color = object_color * ambient;

    // if a pixel is in shadow, do not calculate diffusal or specular lighting
    if (shadow_test(intersection, scene, object, light)) {
        return color;
    }

    Vec leg;
    leg = loc - intersection;

    double leg_length = leg.len();

    leg.normalize();

    // perform light attenuation calculations for use in diffuse and specular
    double atten = 1 / (0.002 * (leg_length * leg_length) + (0.02 * leg_length) + 0.2);

    double dp = leg.dot(normal);

    // diffuse lighting calculation
    if (dp > 0) {
        color = color + object_color * dp * atten;

        // specular lighting calculation
        Vec reflect;
        reflect = leg - (normal * 2.0 * dp);
        reflect.normalize();

        double reflect_dp = reflect.dot(ray.dir);
        if (reflect_dp > 0) {
            color = color + pow(reflect_dp, 200) * atten;
        }
    }

    // Cap color channels to 1
    color.cap();

    return color;
}