#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace droppingball  {

    class Stair {

        /***
   * ball constructor
   * @param left_position the left_position of the stair
   * @param right_position the right_position of the stair
   */
    public:

        Stair(const vec2 left_position, const vec2 right_velocity);

        void DrawStair();

        vec2 GetLeftPosition();

        vec2 GetRightPosition();

    private:
        vec2 left_position_;
        vec2 right_position_;
    };
}