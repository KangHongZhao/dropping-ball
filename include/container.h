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

        Container();

        void Display();

        void AdvanceOneFrame();

        void Container::MovePlayer(int distance);

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
    };

}  // namespace droppingball