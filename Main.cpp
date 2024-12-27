// created by Sam Brothers, 11/7/2024
// this and accompanying files contain the source code for a program
// in C++ which uses ray tracing to produce an image of spheres and a plane
// with various types of realistic lighting
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "rt.hpp"
#include "Color.hpp"
#include "Light.hpp"
#include "scene.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

#define HEIGHT 480
#define WIDTH 640

const Color BACKGROUND(0.3, 0.3, 0.5);

// this fuction reads in the scene.txt and stores the information in a linked list of type Object
void init(SCENE_T &scene, Light &light) {
    Object *node;

    scene.objs = NULL;

    std::ifstream file("scene1.txt");

    char character;
    while (file >> character) {
        if (character == 's') {
            double x, y, z;
            double radius;
            double R, G, B;

            file >> x >> y >> z;
            Vec center = Vec(x, y, z);
            
            file >> radius;

            file >> R >> G >> B;
            Color color = Color(R, G, B);

            node = new Sphere(center, radius, color, false, color);
            
            node->next = scene.objs;
            scene.objs = node;
            
        }
        else if (character == 'l') {
            double x, y, z;

            file >> x >> y >> z;
            Vec loc = Vec(x, y, z);
            light = Light(loc);
        }
        else if (character == 'p') {
            double x, y, z;
            double D;
            double R, G, B;

            file >> x >> y >> z;
            Vec normal = Vec(x, y, z);

            file >> D;
            file >> R >> G >> B;
            Color color = Color(R, G, B);

            file >> R >> G >> B;
            Color color2 = Color(R, G, B);

            node = new Plane(normal, D, color, true, color2);
            
            node->next = scene.objs;
            scene.objs = node;

        }
        
    }

    scene.pixel_size = 1.0/(double)HEIGHT;
    scene.start_y = 0.5;
    scene.start_x = -((double)WIDTH/(double)HEIGHT)/2;

    file.close();
}

// this function takes a ray and sees if it intersects any objects in the scene
// if it does, it calls the illumination function to figure out the correct color for the pixel
static Color trace(RAY_T ray, Light light, SCENE_T scene) {
    // declare return variable
    Color color; 

    double cur_t;
    double closest_t = 1000;

    Vec cur_intersection;
    Vec closest_intersection;

    Vec cur_normal;
    Vec closest_normal;

    Object *closest_obj = NULL;
    Object *cur_obj;

    for (cur_obj = scene.objs; cur_obj != NULL; cur_obj = cur_obj->next) {

        if (cur_obj -> intersect(ray, cur_t, cur_intersection, cur_normal)) {
            if (cur_t < closest_t) { 
                closest_obj = cur_obj;
                closest_t = cur_t;
                closest_intersection = cur_intersection;
                closest_normal = cur_normal;
            }
        }
    }
    if (closest_obj != NULL) {
        color = light.illuminate(ray, *closest_obj, closest_intersection, closest_normal, scene, light);
    } else { 
        color = BACKGROUND;
    }
    return color;
}


// this is the main which iterates through each pixel and
// calls trace to figure out its color
int main() {
    //declare scene object with spheres, plane, and light
    SCENE_T scene;

    Light light = Light(Vec());

    // camera origin
    Vec origin;

    RAY_T ray; // declare ray
    ray.origin = origin;

    Color color; // declare color for tracing

    std::ofstream img_file("img.ppm");

    init(scene, light);

    img_file << "P6 ";
    img_file << WIDTH << " " << HEIGHT << " ";
    img_file << "255 ";

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            ray.dir.set((scene.start_x + (j * scene.pixel_size)), 
                        (scene.start_y - (i * scene.pixel_size)),
                        1.0);
                        
            ray.dir.normalize();

            color = trace(ray, light, scene);   

            img_file << (unsigned char) (color.getR() * 255) <<
                        (unsigned char) (color.getG() * 255) <<
                        (unsigned char) (color.getB() * 255);

        }
    }      
    img_file.close();
    return 0;
}