// raycaster.cpp
#include "raycaster.h"

Raycaster::Raycaster(const Map& map) : map_(map) {}

std::vector<float> Raycaster::castRays(const Player& player, int numRays, float fov) {
    std::vector<float> distances(numRays);
    
    float playerAngle = player.getAngle();
    float halfFov = fov / 2.0f;
    
    for (int i = 0; i < numRays; ++i) {
        // Calculate the angle for this ray
        float rayAngle = playerAngle - halfFov + (static_cast<float>(i) / numRays) * fov;
        
        // Cast the ray and store the distance
        distances[i] = castRay(player.getX(), player.getY(), rayAngle);
    }
    
    return distances;
}

float Raycaster::castRay(float startX, float startY, float angle) const {
    // Ray direction
    float dirX = std::cos(angle);
    float dirY = std::sin(angle);
    
    // Step size for marching along the ray
    float stepSize = 0.01f;
    float maxDistance = 50.0f;
    float currentDistance = 0.0f;
    
    // March the ray until we hit a wall
    while (currentDistance < maxDistance) {
        float x = startX + dirX * currentDistance;
        float y = startY + dirY * currentDistance;
        
        if (map_.isWall(x, y)) {
            return currentDistance;
        }
        
        currentDistance += stepSize;
    }
    
    return maxDistance;
}
