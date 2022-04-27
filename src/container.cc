#include "container.h"
#include "dropping_ball_game.h"

#include "cinder/Rand.h"

namespace droppingball {

    using glm::vec2;

    Container::Container() {

    }

    void Container::Display() {
        stairs_.push_back(stair_3);
        stairs_.push_back(stair_2);
        stairs_.push_back(stair_1);
        stairs_.push_back(stair_);
        kCountStairs = kCountStairs + 1;
        if (kCountStairs <= kNumberStairs) {
            int random_y = 10 * ci::randInt(2,98);
            int random_x = 10 * ci::randInt(2,78);
            stairs_.push_back(Stair(vec2(random_x,random_y),vec2(random_x+200, random_y)));
        }
        for (Stair num: stairs_) {
            num.DrawStair();
        }
        ball_.DrawBall();
    }

    void Container::AdvanceOneFrame() {
        if (ball_.GetPosition().y + ball_.GetRadius() > windowSize) {
            Restart();
        }
        bool we = false;
        for (Stair sta: stairs_) {
            if (ball_.WhetherCollide(sta)) {
                we = true;
            }
        }
        if (we == false) {
            ball_.UpdateParticle();
        }

    }

    void Container::MovePlayer(int distance) {
        ball_.move(distance);
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