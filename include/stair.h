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

        const vec2 GetLeftPosition();

        const vec2 GetRightPosition();

        void Stair::SetRightPosition(const vec2 right_position);

        void Stair::SetLeftPosition(const vec2 left_position);

        void Stair::Move();


    private:
        vec2 left_position_;
        vec2 right_position_;
        const size_t kSpeed = 10;
    };
}