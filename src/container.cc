#include "container.h"
#include "dropping_ball_game.h"

#include "cinder/Rand.h"

namespace droppingball {

    using glm::vec2;

    Container::Container() {
    }

    void Container::Display() {
        for (Stair num: stairs_) {
            num.DrawStair();
        }
        ball_.DrawBall();
    }

    void Container::AdvanceOneFrame() {
        if (ball_.GetPosition().y + ball_.GetRadius() > windowSize || ball_.GetPosition().y < 0) {
            Restart();
        }
        kCountStairs = kCountStairs + 1;
        if (kCountStairs == kNumberStairs) {
            int random_y = 20 * ci::randInt(2, 49);
            int random_x = 20 * ci::randInt(2, 39);
            stairs_.push_back(Stair(vec2(random_x, random_y), vec2(random_x + 100, random_y), kBallVelocity));
            kCountStairs=0;
        }
        std::list<Stair>::iterator star;
        for (star = stairs_.begin(); star != stairs_.end(); star++) {
            star->Move();
        }
        bool we = false;
        for (Stair sta: stairs_) {
            if (ball_.WhetherCollide(sta)) {
                we = true;
                ball_.SetVelocity(kBallVelocityWithStair);
            }
        }
        if (we == false) {
            ball_.SetVelocity(kBallVelocity);
           }
        ball_.UpdateParticle();
    }

    void Container::MovePlayer(int distance) {
        ball_.move(distance);
    }

    void Container::Restart() {
        ball_.ResetPosition();
        stairs_.clear();
    }

    Ball& Container::GetBall() {
        return ball_;
    }

}  // namespace droppingball