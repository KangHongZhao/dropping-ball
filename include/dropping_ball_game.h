#pragma once

#include "cinder/app/App.h"
#include "cinder/audio/Voice.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <container.h>
#include <ball.h>
#include <stair.h>

namespace droppingball {

    class ballGame: public ci::app::App {
    public:
        /**
        * the ballgame constructor
        */
        ballGame();
        /**
        * draw function to draw all the objects
        */
        void draw();
        /**
        * update the board
        */
        void update();
        /**
        * keyboard controls
        * @param event the keyboard event
        */
        void ballGame::keyDown(ci::app::KeyEvent event);

    private:
        const int kWindowSize = 1000;
        const int kMargin = 1000;
        Container container_ = Container();
        const int kMovePixel = 12;
    };
}