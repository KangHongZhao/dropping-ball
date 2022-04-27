#pragma once

#include "cinder/gl/gl.h"
#include "stair.h"
#include "ball.h"

using glm::vec2;

namespace droppingball {

/**
 * The container in which all of stairs and balls contains
 */
    class Container {
    public:
        /***
         * container constructor
         */
        Container();

        /***
         * display the game container
         */
        void Display();

        /***
         * update
         */
        void AdvanceOneFrame();

        /***
         * function to move the ball at a given distance
         */
        void Container::MovePlayer(int distance);

        void Container::Restart();

        Ball& Container::GetBall();

        Stair& Container::GetStair();

    private:
        /**
         * stairs and ball variables
         */
        Stair stair_ = Stair(vec2(500, 100), vec2(700, 100));
        Stair stair_1 = Stair(vec2(200, 300), vec2(400, 300));
        Stair stair_2 = Stair(vec2(100, 600), vec2(300, 600));
        Stair stair_3 = Stair(vec2(400, 900), vec2(600, 900));
        Ball ball_ = Ball(18, vec2(600, 82), vec2(0, 10));
        const int windowSize = 1000;
        std::list<Stair> stairs_;
        const size_t dis = 7;
        const size_t kNumberStairs = 3;
        size_t kCountStairs = 0;
        const vec2 kBallVelocity = vec2(0,3);
    };

}  // namespace droppingball