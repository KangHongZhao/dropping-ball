#pragma once

#include <glm/vec2.hpp>
#include <stair.h>
#include "cinder/gl/gl.h"

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

        Ball(float radius, vec2 position, vec2 velocity);

        void DrawBall();

        vec2 GetPosition();

        float GetRadius();

        void Ball::move(int distance);

        void Ball::UpdateParticle();

        void Ball::ResetPosition();

        bool Ball::WhetherCollide(Stair stair);

        void Ball::SetVelocity(const vec2& velocity);

    private:
        float radius_;
        vec2 position_;
        vec2 velocity_;
        vec2 initial_position_;
    };
}