#include <ball.h>
#include "cinder/gl/gl.h"

using glm::vec2;
namespace droppingball {

    Ball::Ball() {
        ci::app::setWindowSize(1000, 1000);
    }

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

    void Ball::MoveBall() {
        position_ += velocity_;
    }

    void Ball::ResetPosition() {
        position_ = initial_position_;
    }

    void Ball::SetVelocity(vec2 velocity) {
        velocity_ = velocity;
    }

    vec2 Ball::GetVelocity() {
        return velocity_;
    }

    vec2 Ball::GetPosition() {
        return position_;
    }

    float Ball::GetRadius() {
        return radius_;
    }
}

