#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <container.h>
#include <ball.h>
#include <stair.h>

namespace droppingball {

/**
 * The game engine of the dropping ball
 */
    class ballGame: public ci::app::App {
    public:
        ballGame();

        void draw() override;

        void update() override;

        const int kWindowSize = 1000;
        const int kMargin = 1000;
        void ballGame::keyDown(ci::app::KeyEvent event);

    private:
        Container container_ = Container();
        const int kMovePixel = 8;
    };
}