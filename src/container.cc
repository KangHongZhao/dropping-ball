#include "container.h"
#include "dropping_ball_game.h"

namespace droppingball {

    using glm::vec2;

    Container::Container() {

    }

    void Container::Display() {
        stairs_.push_back(stair_3);
        stairs_.push_back(stair_2);
        stairs_.push_back(stair_1);
        stairs_.push_back(stair_);
        for (Stair num: stairs_) {
            num.DrawStair();
        }
        ball_.DrawBall();
    }

    void Container::AdvanceOneFrame() {
        if (ball_.GetPosition().y + ball_.GetRadius() > windowSize) {
            Restart();
        }
    }

    void Container::MovePlayer(int distance) {
        bool we = false;
        for (Stair sta: stairs_) {
            if (ball_.WhetherCollide(sta)) {
                we = true;
            }
        }
        if (we == true) {
            ball_.move(distance);
        } else {
            ball_.UpdateParticle();
        }
    }

    void Container::Restart() {
        ball_.ResetPosition();
    }

    Ball& Container::GetBall() {
        return ball_;
    }

    Stair& Container::GetStair() {
        return stair_;
    }

}  // namespace droppingball