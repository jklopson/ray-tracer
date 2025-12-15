// player.cpp
#include "player.h"

Player::Player(float x, float y, float angle) : x_(x), y_(y), angle_(angle), velocityX_(0), velocityY_(0), moveSpeed_(3.0f) {}

void Player::update(float deltaTime) {
    // velocityX_ = strafe (positive = right), velocityY_ = forward (positive = forward)
    // Convert to world coordinates using player's angle
    float forward = velocityY_;
    float strafe = velocityX_;

    float worldVelX = forward * std::cos(angle_) - strafe * std::sin(angle_);
    float worldVelY = forward * std::sin(angle_) + strafe * std::cos(angle_);

    x_ += worldVelX * moveSpeed_ * deltaTime;
    y_ += worldVelY * moveSpeed_ * deltaTime;

    //normalize angle to [0, 2pi]
    while (angle_ < 0) angle_ += 2 * M_PI;
    while (angle_ >= 2 * M_PI) angle_ -= 2 * M_PI;
}
