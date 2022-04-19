
#include <stair.h>
#include "cinder/gl/gl.h"

using glm::vec2;
namespace droppingball {

    Stair::Stair(const vec2 left_position, const vec2 right_position) {
        left_position_ = left_position;
        right_position_ = right_position;
    }

    void Stair::DrawStair() {
        ci::gl::color(ci::Color("Green"));
        ci::gl::drawLine(left_position_, right_position_);
    }

    vec2 Stair::GetLeftPosition() {
        return left_position_;
    }

    vec2 Stair::GetRightPosition() {
        return right_position_;
    }

    void Stair::move(int distance) {
        left_position_.y = left_position_.y + distance;
        right_position_.y = right_position_.y + distance;
    }
}

