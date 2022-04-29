#pragma once

#include <glm/vec2.hpp>
#include <stair.h>
#include "cinder/gl/gl.h"

using glm::vec2;

namespace droppingball  {

    class Ball {

    public:
        /***
        * ball constructor
        * @param radius the radius of the ball
        * @param position the position of the ball
        * @param velocity of basket initially
        */
        Ball(float radius, vec2 position, vec2 velocity);
        /***
        * functions to draw the ball
        */
        void DrawBall();
        /***
        * functions to get the position of the ball
        */
        vec2 GetPosition();
        /***
        * functions to get the radius of the ball
        */
        float GetRadius();
        /***
        * to move the ball horizontally on the stair
        * @param distance the distance of the ball moving on the stair
        */
        void Ball::move(int distance);
        /***
        * to move the ball when the ball is off the stair, update the ball with its velocity
        */
        void Ball::UpdateParticle();
        /***
        * to reset the ball to the starting position, when user press restart r
        */
        void Ball::ResetPosition();
        /***
        * determine whether the ball collides with the stairs
        * @param stair the stair object
        */
        bool Ball::WhetherCollide(Stair stair);
        /***
        * set a different velocity for the ball
        * @param velocity the new velocity of the ball
        */
        void Ball::SetVelocity(const vec2& velocity);

    private:
        float radius_;
        vec2 position_;
        vec2 velocity_;
        vec2 initial_position_;
    };
}