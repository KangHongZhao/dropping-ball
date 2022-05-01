#include <dropping_ball_game.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace droppingball {

    ballGame::ballGame() {
        ci::app::setWindowSize(kWindowSize, kMargin);
    }

    void ballGame::draw() {
        ci::Color background_color("Black");
        ci::gl::clear(background_color);
        //load the image
        cinder::gl::Texture2dRef image;
        image = cinder::gl::Texture2d::create(loadImage(cinder::app::loadAsset("background.gif")));
        cinder::Rectf drawRect(0.0f, 0.0f, 1000.0f, 1000.0f);
        cinder::gl::draw(image, drawRect);
        container_.Display();
    }

    void ballGame::update() {
        container_.AdvanceOneFrame();
    }

    void ballGame::keyDown(cinder::app::KeyEvent event) {
        if(event.getCode() == ci::app::KeyEvent::KEY_LEFT) {
            container_.MovePlayer(-kMovePixel);
        }
        if(event.getCode() == ci::app::KeyEvent::KEY_RIGHT) {
            container_.MovePlayer(kMovePixel);
        }
        if(event.getCode() == ci::app::KeyEvent::KEY_r) {
            container_.Restart();
        }
    }

}