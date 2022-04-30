#include <catch2/catch.hpp>
#include <container.h>
#include <dropping_ball_game.h>
#include <stair.h>
#include <glm/vec2.hpp>

using droppingball::Stair;
using droppingball::Ball;
using droppingball::Container;
using droppingball::ballGame;

TEST_CASE("test if the Move function is correct") {
    SECTION("Test the left position of the ball is correct after move") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.Move(5);
        REQUIRE(ball.GetPosition().x == 405);
    }
    SECTION("Test the right position of the ball is correct after move") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.Move(5);
        REQUIRE(ball.GetPosition().y == 400);
    }
}

TEST_CASE("test if the updateParticle function is correct") {
    SECTION("Test the left position of the ball is correct after UpdateParticle") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.UpdateParticle();
        REQUIRE(ball.GetPosition().x == 401);
    }
    SECTION("Test the right position of the ball is correct after move") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.UpdateParticle();
        REQUIRE(ball.GetPosition().y == 400);
    }
}

TEST_CASE("test if can reset the position and velocity") {
    SECTION("Test if can reset the position to the original position") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.UpdateParticle();
        ball.ResetPosition();
        REQUIRE(ball.GetPosition().x == 400);
    }
    SECTION("Test if can set the velocity to other values") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        ball.SetVelocity(glm::vec2(2,0));
        ball.UpdateParticle();
        REQUIRE(ball.GetPosition().x == 402);
    }
}