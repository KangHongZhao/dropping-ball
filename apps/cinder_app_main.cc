#include "dropping_ball_game.h"

using droppingball::ballGame;

void prepareSettings(ballGame::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(ballGame, ci::app::RendererGl, prepareSettings);