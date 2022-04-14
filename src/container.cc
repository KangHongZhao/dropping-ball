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
        if((ball_.GetPosition().y + ball_.GetRadius() == stair_.GetLeftPosition().y)
        && (stair_.GetLeftPosition().x <= ball_.GetPosition().x && stair_.GetRightPosition().x >= ball_.GetPosition().x)) {
            ball_.move(distance);
        } else if((ball_.GetPosition().y + ball_.GetRadius() == stair_3.GetLeftPosition().y)
                  && (stair_3.GetLeftPosition().x <= ball_.GetPosition().x && stair_3.GetRightPosition().x >= ball_.GetPosition().x)) {
            ball_.move(distance);
        } else {
                ball_.UpdateParticle();
        }
    }

    Ball& Container::GetBall() {
        return ball_;
    }

    Stair& Container::GetStair() {
        return stair_;
    }

}  // namespace droppingball