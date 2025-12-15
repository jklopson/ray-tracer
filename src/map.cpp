// map.cpp
#include "map.h"

Map::Map(int width, int height) : width_(width), height_(height), grid_(width * height, 0) {}

void Map::loadTestMap() {
    //exterior walls
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            if (x == 0 || x == width_ - 1 || y == 0 || y == height_ - 1) {
                grid_[y * width_ + x] = 1; //Wall
            }
        }
    }
    //pseudorandom interior walls
    for (int x = 3; x < 8; ++x) {
        grid_[5 * width_ + x] = 1;
    }
}

bool Map::isWallAt(int gridX, int gridY) const {
    if (gridX < 0 || gridX >= width_ || gridY < 0 || gridY >= height_) {
        return true; //out of bounds is a Wall
    }
    return grid_[gridY * width_ + gridX] == 1;
}

bool Map::isWall(float x, float y) const {
    int gridX = static_cast<int>(x);
    int gridY = static_cast<int>(y);
    return isWallAt(gridX, gridY);
}
