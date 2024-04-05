#include <raylib.h>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "./headers/particles.hpp"

using namespace std;

int main( ) {
    ifstream file("./settings.json");
    Json::Reader reader;
    Json::Value complete_json;

    reader.parse(file, complete_json);

    const int screen_width         = complete_json["screen"]["width"].asInt();
    const int screen_height        = complete_json["screen"]["height"].asInt();
    const uint64_t particle_width  = complete_json["particle"]["width"].asUInt64();
    const uint64_t particle_height = complete_json["particle"]["height"].asUInt64();
    const uint64_t particle_number = complete_json["particle"]["number"].asUInt64();
    const float friction           = complete_json["friction"].asFloat();

    Particles particles( screen_width, screen_height, particle_width, particle_height, particle_number, friction );

    InitWindow(screen_width, screen_height, "raylib Starter Code");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        particles.update_pos();
        particles.draw();
    }

    CloseWindow();
}