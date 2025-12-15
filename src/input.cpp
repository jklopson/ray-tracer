// input.cpp
#include "input.h"

void InputHandler::handleInput(sf::RenderWindow& window) {
    velocityX_ = 0.0f;
    velocityY_ = 0.0f;
    rotation_ = 0.0f;
    
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    
    // Continuous key checking
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocityX_ += std::cos(0);  // Forward relative to view
        velocityY_ += std::sin(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velocityX_ -= std::cos(0);
        velocityY_ -= std::sin(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocityX_ -= std::sin(0);
        velocityY_ += std::cos(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocityX_ += std::sin(0);
        velocityY_ -= std::cos(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rotation_ = 2.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rotation_ = -2.0f;
    }
}
