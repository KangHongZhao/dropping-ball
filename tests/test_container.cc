#include <catch2/catch.hpp>
#include <container.h>
#include <stair.h>
#include <glm/vec2.hpp>
#include <dropping_ball_game.h>

using droppingball::Stair;
using droppingball::Ball;
using droppingball::Container;
using droppingball::ballGame;

TEST_CASE("test basic getter functions") {
    SECTION("Test if can get the position of the ball") {
        droppingball::Container container;
        container.AdvanceOneFrame();
        container.GetBall();
        REQUIRE(container.GetBall().GetPosition().x == 600);
    }
    SECTION("Test if can get the position of the stair") {
        droppingball::Container container;
        container.AdvanceOneFrame();
        container.GetStair();
        REQUIRE(container.GetStair().GetRightPosition().y == 100);
    }
}

TEST_CASE("test if the ball can move properly") {
    SECTION("Test if the ball can move right") {
        droppingball::Container container;
        container.MovePlayer(6);
        REQUIRE(container.GetBall().GetPosition().x == 606);
    }
    SECTION("Test if the ball can move left") {
        droppingball::Container container;
        container.MovePlayer(-6);
        REQUIRE(container.GetBall().GetPosition().y == 90);
        REQUIRE(container.GetBall().GetPosition().x == 594);
    }
}

TEST_CASE("test if the ball will drop") {
    SECTION("Test if the ball will drop from the stair") {
        droppingball::Container container;
        container.MovePlayer(-120);
        REQUIRE(container.GetBall().GetPosition().x == 480);
    }
    SECTION("Test if the ball will collide with the next stair") {
        droppingball::Container container;
        container.MovePlayer(-105);
        REQUIRE(container.GetBall().GetPosition().y == 90);
    }
}

TEST_CASE("test if the container can detect the collision") {
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

TEST_CASE("test if the container can detect restart") {
    SECTION("Test if the ball will restart position when out of window y axis") {
        droppingball::Container container;
        Ball ball(5, glm::vec2(990,300), glm::vec2(20,0));
        container.AdvanceOneFrame();
        REQUIRE(ball.GetPosition().x == 990);
    }
    SECTION("Test if the ball will restart position when out of window x axis") {
        droppingball::Container container;
        Ball ball(5, glm::vec2(300,990), glm::vec2(0,20));
        container.AdvanceOneFrame();
        REQUIRE(ball.GetPosition().x == 300);
    }
}