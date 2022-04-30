#include <stair.h>
#include "cinder/gl/gl.h"

using glm::vec2;
namespace droppingball {

    Stair::Stair(const vec2 left_position, const vec2 right_position, vec2 velocity) {
        left_position_ = left_position;
        right_position_ = right_position;
        velocity_ = velocity;
    }

    void Stair::DrawStair() {
        ci::gl::color(ci::Color("Green"));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2(left_position_.x, left_position_.y),
                          glm::vec2(right_position_.x, right_position_.y - stair_width_)));
    }

    void Stair::Move() {
        left_position_ -= velocity_;
        right_position_ -= velocity_;
    }

    void Stair::SetLeftPosition(const vec2 left_position) {
        left_position_ = left_position;
    }

    void Stair::SetRightPosition(const vec2 right_position) {
        right_position_ = right_position;
    }

    const vec2 Stair::GetLeftPosition() {
        return left_position_;
    }

    const vec2 Stair::GetRightPosition() {
        return right_position_;
    }
}
