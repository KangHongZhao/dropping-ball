#include "container.h"
#include "dropping_ball_game.h"

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

namespace droppingball {

    using glm::vec2;

    Container::Container() {
        score_ = 0;
        highest_score_ = 0;
    }

    void Container::Display() {
        for (Stair num: stairs_) {
            num.DrawStair();
        }
        ball_.DrawBall();
        ci::gl::drawString(kMessage+ std::to_string(score_), kLocation,
                           kMessageColor, kFont);
        ci::gl::drawString(kHighestMessage+ std::to_string(highest_score_), kHighestLocation,
                           kMessageColor, kFont);
    }

    void Container::AdvanceOneFrame() {
        std::list<Stair>::iterator star;
        for (star = stairs_.begin(); star != stairs_.end(); star++) {
            star->Move();
        }
        kCountStairs = kCountStairs + 1;
        if (kCountStairs == kNumberStairs) {
            int random_y = 24 * ci::randInt(1, 41);
            int random_x = 24 * ci::randInt(1, 32);
            stairs_.push_back(Stair(vec2(random_x, random_y), vec2(random_x + 102, random_y), kBallVelocity));
            kCountStairs=0;
        }
        bool we = false;
        for (Stair sta: stairs_) {
            if (ball_.WhetherCollide(sta)) {
                we = true;
                score_++;
                ball_.SetVelocity(kBallVelocityWithStair);
            }
        }
        if (we == false) {
            ball_.SetVelocity(kBallVelocity);
        }
        ball_.UpdateParticle();
        if (ball_.GetPosition().y + ball_.GetRadius() > windowSize || ball_.GetPosition().y < 0) {
            if (score_ > highest_score_) {
                highest_score_ = score_;
            }
            Restart();
        }
    }

    void Container::MovePlayer(int distance) {
        ball_.move(distance);
    }

    void Container::Restart() {
        ball_.ResetPosition();
        ball_.SetVelocity(kBallVelocity);
        stairs_.clear();
        score_ = 0;
        ci::gl::clear(ci::Color("Orange"), true);
        ci::gl::clear(ci::Color("Green"), true);
    }

    Ball& Container::GetBall() {
        return ball_;
    }

}  // namespace droppingball