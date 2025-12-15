// main.cpp
#include "map.h"
#include "player.h"
#include "raycaster.h"
#include "renderer.h"
#include "input.h"
#include <SFML/Graphics.hpp>

int main() {
    // Initialize components
    Map map(20, 15);
    map.loadTestMap();
    
    Player player(10.0f, 7.5f, 0.0f);
    Raycaster raycaster(map);
    Renderer renderer(800, 600);
    InputHandler input;
    
    sf::Clock clock;
    
    // Main loop
    while (renderer.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        
        // Input
        input.handleInput(renderer.getWindow());
        player.setVelocity(input.getVelocityX(), input.getVelocityY());
        player.rotate(input.getRotation() * deltaTime);
        
        // Update
        player.update(deltaTime);
        
        // Render
        std::vector<float> distances = raycaster.castRays(player, 800, 0.66f);
        renderer.renderFrame(distances);
        renderer.display();
    }
    
    return 0;
}
