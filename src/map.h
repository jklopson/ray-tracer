// map.h
#pragma once
#include <vector>
#include <cstdint>

class Map {
public:
    Map(int width, int height);

    // Initialize with simple test map
    void loadTestMap();

    // Query the map
    bool isWall(float x, float y) const;
    bool isWallAt(int gridX, int gridY) const;

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

private:
    int width_;
    int height_;
    std::vector<uint8_t> grid_;
};
