#pragma once
#include <cmath>

class Player {
public:
    Player(float x = 5.0f, float y = 5.0f, float angle = 0.0f);

    void update(float deltaTime);
    void setVelocity(float vx, float vy) { velocityX_ = vx; velocityY_ = vy; }
    void rotate(float deltaAngle) { angle_ += deltaAngle; }

    float getX() const { return x_; }
    float getY() const { return y_; }
    float getAngle() const { return angle_; }

    void setPosition(float x, float y) { x_ = x; y_ = y; }

private:
    float x_, y_;           // World position
    float angle_;           // Viewing angle in radians
    float velocityX_, velocityY_;
    float moveSpeed_;  // Units per second
};

