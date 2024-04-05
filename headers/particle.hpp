#ifndef PARTICLE_H
#define PARTICLE_H

#include <raylib.h> 

struct Particle
{
    Rectangle shape;
    Vector2 velocity;
    Color color;
};

#endif