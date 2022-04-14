
#include "container.h"

namespace droppingball {

    using glm::vec2;

    Container::Container() {

    }

    void Container::Display() {
        stair_.DrawStair();
        stair_1.DrawStair();
        stair_2.DrawStair();
        stair_3.DrawStair();
        ball_.DrawBall();
    }

    void Container::AdvanceOneFrame() {
    }

    void Container::MovePlayer(int distance) {
        ball_.move(distance);
    }

}  // namespace droppingball