#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace droppingball  {

    class Stair {
    public:
        /***
        * stair constructor
        * @param left_position the left_position of the stair
        * @param right_position the right_position of the stair
        * @param velocity the velocity of the stair
        */
        Stair(const vec2 left_position, const vec2 right_velocity, vec2 velocity);
        /***
        * to draw the stairs in solid rectangle
        */
        void DrawStair();
        /***
        * to get the left point of the stair
        */
        const vec2 GetLeftPosition();
        /***
        * to get the right point of the stair
        */
        const vec2 GetRightPosition();
        /***
        * to set the new right point of the stair
        * @param right_position right point of the stair
        */
        void Stair::SetRightPosition(const vec2 right_position);
        /***
        * to get the left point of the stair
        * @param left_position the left point of the stair
        */
        void Stair::SetLeftPosition(const vec2 left_position);
        /***
        * to move the stair vertically
        */
        void Stair::Move();

    private:
        vec2 left_position_;
        vec2 right_position_;
        vec2 velocity_;
        const size_t stair_width_ = 5;
    };
}