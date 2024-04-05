#include "../headers/particles.hpp"

Particles::Particles( uint64_t w_width, uint64_t w_height, uint64_t p_width, uint64_t p_height, uint64_t p_number, float friction ) {
    srand( static_cast<unsigned int>(time(0)) );
    this->particles.resize( p_number );
    this->w_height = w_height;
    this->w_width  = w_width;
    this->friction = friction;
    for( int i = 0; i < p_number; ++i ) {
        Particle new_particle;
        new_particle.shape.height = p_height;
        new_particle.shape.width  = p_width;
        new_particle.shape.x      = rand() % ( w_width - 20 ) + 10;
        new_particle.shape.y      = rand() % ( w_height - 20 ) + 10;
        new_particle.color        = BLACK;
        new_particle.velocity.x   = 0.0f;
        new_particle.velocity.y   = 0.0f;
        this->particles[i]        = new_particle; 
    }
}

void Particles::draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for( int i = 0; i <  this->particles.size() - 1; ++i ) {
        DrawRectangleRec( this->particles[i].shape, BLACK );
    }
    EndDrawing();
}

float Particles::get_dist( Particle particle, Vector2 other_post ) {
    const float dx = particle.shape.x - other_post.x;
    const float dy = particle.shape.y - other_post.y;
    return sqrt( ( dx*dx ) + ( dy*dy ) );
}

Vector2 Particles::get_normal( Particle particle, Vector2 otherPos ) {
    float dist = get_dist( particle, otherPos );
    if (dist == 0.0f) dist = 1;
    const float dx = particle.shape.x - otherPos.x;
    const float dy = particle.shape.y - otherPos.y;
    return ( Vector2 ){ dx*( 1/dist ), dy*( 1/dist ) };
}

void Particles::update_pos() {
    Vector2 mousePosition = GetMousePosition();

    for( int i = 0; i < this->particles.size(); ++i ) {
        float dist     = fmax( get_dist( this->particles[i], mousePosition), 0.5f );
        Vector2 normal = get_normal( this->particles[i], mousePosition );
        this->particles[i].velocity.x -= normal.x/dist;
        this->particles[i].velocity.y -= normal.y/dist;
        this->particles[i].velocity.x *= this->friction;
        this->particles[i].velocity.y *= this->friction;
        this->particles[i].shape.x    += this->particles[i].velocity.x;
        this->particles[i].shape.y    += this->particles[i].velocity.y;

        if ( this->particles[i].shape.x < 0 ) this->particles[i].shape.x += w_width;
        if ( this->particles[i].shape.x >= w_width ) this->particles[i].shape.x -= w_width;
        if ( this->particles[i].shape.y < 0 ) this->particles[i].shape.y += w_height;
        if ( this->particles[i].shape.y >= w_height ) this->particles[i].shape.y -= w_height;
    }
}