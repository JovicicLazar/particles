#ifndef PARTICLES_H
#define PARTICLES_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <raylib.h>
#include <ctime>
#include <math.h>

#include "particle.hpp"

using namespace std;

class Particles {
    public:
        Particles( uint64_t w_width, uint64_t w_height, uint64_t p_width, uint64_t p_height, uint64_t p_number, float friction );
        
        float get_dist( Particle particle, Vector2 other_pos );
        Vector2 get_normal( Particle particle, Vector2 otherPos );
        void update_pos();
        void draw();

    private:
        uint64_t         w_width;
        uint64_t         w_height;
        float            friction;
        vector<Particle> particles;
};

#endif