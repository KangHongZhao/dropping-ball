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
        //draw stair, ball, and scoring information
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
        //iterator to modify the stair position to go up
        std::list<Stair>::iterator star;
        for (star = stairs_.begin(); star != stairs_.end(); star++) {
            star->Move();
        }
        //push back randomly generated stairs
        kCountStairs = kCountStairs + 1;
        if (kCountStairs == kNumberStairs) {
            int random_y = 24 * ci::randInt(1, 41);
            int random_x = 24 * ci::randInt(1, 32);
            stairs_.push_back(Stair(vec2(random_x, random_y), vec2(random_x + 102, random_y), kBallVelocity));
            kCountStairs=0;
        }
        // detect if the ball collides with the stair, if so, set the ball to new velocity and the score goes up if collides
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
        // update the ball after detection
        ball_.UpdateParticle();
        // restart if the ball is not in the window range and store the score
        if (ball_.GetPosition().y + ball_.GetRadius() > windowSize || ball_.GetPosition().y < 0 || ball_.GetPosition().x < 0 || ball_.GetPosition().x > kWindowMagin) {
            if (score_ > highest_score_) {
                highest_score_ = score_;
            }
            Restart();
        }
    }

    void Container::MovePlayer(int distance) {
        ball_.Move(distance);
    }

    void Container::Restart() {
        //change everything to the origin if restarted
        ball_.ResetPosition();
        ball_.SetVelocity(kBallVelocity);
        stairs_.clear();
        score_ = 0;
        kCountStairs = 0;
        ci::gl::clear(ci::Color("Orange"), true);
        ci::gl::clear(ci::Color("Green"), true);
    }

    Ball& Container::GetBall() {
        return ball_;
    }

}  // namespace droppingball