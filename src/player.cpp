// player.cpp
#include "player.h"

Player::Player(float x, float y, float angle) : x_(x), y_(y), angle_(angle), velocityX_(0), velocityY_(0) {}

void Player::update(float deltaTime) {
    x_ += velocityX_ * moveSpeed_ * deltaTime;
    y_ += velocityY_ * moveSpeed_ * deltaTime;

    //normalize angle to [0, 2pi]
    while (angle_ < 0) angle_ += 2 * M_PI;
    while (angle_ >= 2 * M_PI) angle_ -= 2 * M_PI;
}
