#include "ball.h"

using dropping_ball::dropping_ball_app;

void prepareSettings(BasketballGame::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(BasketballGame, ci::app::RendererGl, prepareSettings);