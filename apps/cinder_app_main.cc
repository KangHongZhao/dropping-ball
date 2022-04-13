#include "ball.h"

using droppingball::Ball;

void prepareSettings(Ball::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(Ball, ci::app::RendererGl, prepareSettings);