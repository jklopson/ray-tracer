// input.cpp
#include "input.h"

void InputHandler::handleInput(sf::RenderWindow& window) {
    velocityX_ = 0.0f;
    velocityY_ = 0.0f;
    rotation_ = 0.0f;

    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }

    // Continuous key checking - output movement intent (forward/strafe)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocityY_ += 1.0f;  // Forward
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocityY_ -= 1.0f;  // Backward
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocityX_ -= 1.0f;  // Strafe left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocityX_ += 1.0f;  // Strafe right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        rotation_ = 2.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        rotation_ = -2.0f;
    }
}
