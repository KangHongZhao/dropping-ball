#include <ball.h>
#include <stair.h>
#include <container.h>
#include "cinder/gl/gl.h"

using glm::vec2;
namespace droppingball {

    Ball::Ball(float radius, vec2 position, vec2 velocity) {
        initial_position_ = position;
        radius_ = radius;
        position_ = position;
        velocity_ = velocity;
    }

    void Ball::DrawBall() {
        ci::gl::color(ci::Color("Orange"));
        ci::gl::drawSolidCircle(position_, radius_);
    }

    void Ball::move(int distance) {
        position_.x = position_.x + distance;
    }

    vec2 Ball::GetPosition() {
        return position_;
    }

    float Ball::GetRadius() {
        return radius_;
    }

    void Ball::ResetPosition() {
        position_ = initial_position_;
    }

    void Ball::UpdateParticle() {
        position_ += velocity_;
    }
    bool Ball::WhetherCollide(Stair stair) {
        if ((((position_.y + radius_) == stair.GetLeftPosition().y)
             && (stair.GetLeftPosition().x <= position_.x && stair.GetRightPosition().x >= position_.x)
             && (stair.GetLeftPosition().y - position_.y == radius_))){
            return true;
        } else {
            return false;
        }
    }
    void Ball::SetPosition(const vec2& position) {
        position_ = position;
    }
}