// raycaster.h
#pragma once
#include "map.h"
#include "player.h"
#include <vector>
#include <cmath>

class Raycaster {
public:
    Raycaster(const Map& map);
    
    //cast rays and return distance to wall for each column
    std::vector<float> castRays(const Player& player, int numRays, float fov);
    
private:
    const Map& map_;
    
    //help cast a single ray and return distance
    float castRay(float startX, float startY, float angle) const;
};
