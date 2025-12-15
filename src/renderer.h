// renderer.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Renderer {
public:
    Renderer(int width, int height);
    
    void renderFrame(const std::vector<float>& distances);
    void display();
    bool isOpen() const;
    void close();
    
    sf::RenderWindow& getWindow() { return window_; }
    
private:
    sf::RenderWindow window_;
    int screenWidth_;
    int screenHeight_;
};
