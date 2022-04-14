#include <dropping_ball_game.h>

namespace droppingball {

    ballGame::ballGame() {
        ci::app::setWindowSize(kWindowSize, kMargin);
    }

    void ballGame::draw() {
        ci::Color background_color("Black");
        ci::gl::clear(background_color);
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
    }
}