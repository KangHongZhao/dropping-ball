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
}

