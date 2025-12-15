// renderer.cpp
#include "renderer.h"
#include <algorithm>

Renderer::Renderer(int width, int height)
    : window_(sf::VideoMode(width, height), "Wolfenstein 3D Raycaster"),
      screenWidth_(width), screenHeight_(height) {
    window_.setFramerateLimit(60);
}

void Renderer::renderFrame(const std::vector<float>& distances) {
    window_.clear(sf::Color::Black);
    
    // Draw ceiling (top half)
    sf::RectangleShape ceiling(sf::Vector2f(screenWidth_, screenHeight_ / 2.0f));
    ceiling.setFillColor(sf::Color(80, 80, 80));
    window_.draw(ceiling);
    
    // Draw floor (bottom half)
    sf::RectangleShape floor(sf::Vector2f(screenWidth_, screenHeight_ / 2.0f));
    floor.setPosition(0, screenHeight_ / 2.0f);
    floor.setFillColor(sf::Color(40, 40, 40));
    window_.draw(floor);
    
    // Draw walls based on ray distances
    int numRays = distances.size();
    float columnWidth = static_cast<float>(screenWidth_) / numRays;
    
    for (int i = 0; i < numRays; ++i) {
        float distance = distances[i];
        
        // Prevent division by zero and clamp distance
        distance = std::max(distance, 0.1f);
        
        // Calculate wall height (inverse relationship with distance)
        float wallHeight = (screenHeight_ / distance) * 0.5f;
        wallHeight = std::min(wallHeight, static_cast<float>(screenHeight_));
        
        // Draw vertical line
        float x = i * columnWidth;
        float y = (screenHeight_ - wallHeight) / 2.0f;
        
        sf::RectangleShape wall(sf::Vector2f(columnWidth + 1, wallHeight));
        wall.setPosition(x, y);
        
        // Shade based on distance (farther = darker)
        int brightness = static_cast<int>(200.0f / (1.0f + distance * 0.1f));
        brightness = std::max(0, std::min(255, brightness));
        wall.setFillColor(sf::Color(brightness, brightness, brightness));
        
        window_.draw(wall);
    }
}

void Renderer::display() {
    window_.display();
}

bool Renderer::isOpen() const {
    return window_.isOpen();
}

void Renderer::close() {
    window_.close();
}
