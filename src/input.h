// input.h
#pragma once
#include <SFML/Graphics.hpp>

class InputHandler {
public:
    void handleInput(sf::RenderWindow& window);
    
    float getVelocityX() const { return velocityX_; }
    float getVelocityY() const { return velocityY_; }
    float getRotation() const { return rotation_; }
    
private:
    float velocityX_ = 0.0f;
    float velocityY_ = 0.0f;
    float rotation_ = 0.0f;
};
