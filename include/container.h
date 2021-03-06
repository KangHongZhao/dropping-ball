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
         * function to move the ball at a given distance horizontally
         * @param distance the distance of the ball horizontally
         */
        void Container::MovePlayer(int distance);

        /***
        * restart the game when the ball dies or the player press restart button
        */
        void Container::Restart();

        /***
        * get the ball object for testing
        */
        Ball& Container::GetBall();

        /***
        * get the stair object for testing
        */
        Stair& Container::GetStair();

    private:
        Stair stair_ = Stair(vec2(500, 100), vec2(700, 100), vec2(0,10));
        Ball ball_ = Ball(21, vec2(600, 90), vec2(0, 3));
        const int windowSize = 1000;
        const int max_y = 41;
        const int max_x = 32;
        const int coefficient = 24;
        std::list<Stair> stairs_;
        const size_t dis = 6;
        const size_t kNumberStairs = 30;
        size_t kCountStairs = 0;
        const size_t kWindowMagin = 1000;
        const vec2 kBallVelocity = vec2(0,3);
        const vec2 kBallVelocityWithStair = vec2(0,-3);
        size_t score_;
        size_t highest_score_;
        std::string kMessage = "Score: ";
        std::string kHighestMessage = "highest Score: ";
        const std::string kSymbolChar = "Helvetica Neue";
        const float kSymbolSize = 50;
        const cinder::ColorT<float> kMessageColor = "white";
        const glm::vec2 kHighestLocation = glm::vec2(600, 50);
        const glm::vec2 kLocation = glm::vec2(700, 100);
    };

}  // namespace droppingball