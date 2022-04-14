#pragma once

#include "cinder/gl/gl.h"
#include "stair.h"
#include "ball.h"

using glm::vec2;

namespace droppingball {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
    class Container {
    public:
        /**
         * TODO: Add more parameters to this constructor, and add documentation.
         */
        Container();

        /**
         * Displays the container walls and the current positions of the particles.
         */
        void Display();

        /**
         * Updates the positions and velocities of all particles (based on the rules
         * described in the assignment documentation).
         */
        void AdvanceOneFrame();

        void Container::MovePlayer(int distance);

    private:
        /**
         * This variable is just for the purposes of demonstrating how to make a shape move
         * across a screen. Please remove it once you start working on your code.
         */
        Stair stair_ = Stair(vec2(500, 100), vec2(700, 100));
        Stair stair_1 = Stair(vec2(200, 300), vec2(400, 300));
        Stair stair_2 = Stair(vec2(100, 600), vec2(300, 600));
        Stair stair_3 = Stair(vec2(400, 900), vec2(600, 900));
        Ball ball_ = Ball(18, vec2(600, 82), vec2(3, -3));
    };

}  // namespace idealgas