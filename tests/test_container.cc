#include "catch.hpp"
#include <container.h>
#include <stair.h>
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
        REQUIRE(container.GetBall().GetPosition().y == 82);
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
        REQUIRE(container.GetBall().GetPosition().y == 82);
    }
}