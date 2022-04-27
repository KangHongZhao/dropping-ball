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
        Ball ball_ = Ball(21, vec2(600, 90), vec2(0, 3));
        const int windowSize = 1000;
        std::list<Stair> stairs_;
        const size_t dis = 6;
        const size_t kNumberStairs = 30;
        size_t kCountStairs = 0;
        const vec2 kBallVelocity = vec2(0,3);
        const vec2 kBallVelocityWithStair = vec2(0,-3);
        size_t score_;
        size_t highest_score_;
        std::string kMessage = "Score: ";
        std::string kHighestMessage = "highest Score: ";
        const cinder::ColorT<float> kMessageColor = "white";
        const glm::vec2 kHighestLocation = glm::vec2(600, 50);
        const glm::vec2 kLocation = glm::vec2(700, 100);
        ci::Font kFont = ci::Font("Helvetica Neue", 55);
    };

}  // namespace droppingball