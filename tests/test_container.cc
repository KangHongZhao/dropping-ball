#include <catch2/catch.hpp>
#include <container.h>
#include <stair.h>
#include <glm/vec2.hpp>
#include <dropping_ball_game.h>

using droppingball::Stair;
using droppingball::Ball;
using droppingball::Container;
using droppingball::ballGame;

TEST_CASE("test if the container can detect the collision") {
    Ball ball(50, glm::vec2(200,300), glm::vec2(1,0));
    SECTION("Test if the stair collide with the ball") {
        Ball ball(20, glm::vec2(400,400), glm::vec2(1,0));
        Stair stair(glm::vec2(300,420), glm::vec2(500,420), glm::vec2(0,1));
        REQUIRE(ball.WhetherCollide(stair) == true);
    }
    SECTION("Another test if the stair collide with the ball") {
        Ball ball(50, glm::vec2(200,300), glm::vec2(1,0));
        Stair stair(glm::vec2(270,420), glm::vec2(270,420), glm::vec2(0,1));
        REQUIRE(ball.WhetherCollide(stair) == false);
    }
}