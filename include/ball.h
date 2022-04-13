#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace droppingball  {

    class Ball {

        /***
   * ball constructor
   * @param radius the radius of the ball
   * @param position the position of the ball
   * @param velocity of basket initially
   */
    public:

        Ball( float radius,  vec2 position,  vec2 velocity);

        void MoveBall();

        void DrawBall();

        void ResetPosition();

        void SetVelocity(vec2 velocity);

        vec2 GetVelocity();

        vec2 GetPosition();

        float GetRadius();


    private:
        float radius_;
        vec2 position_;
        vec2 velocity_;
        vec2 initial_position_;
    };
}