#include <catch2/catch.hpp>
#include <container.h>
#include <dropping_ball_game.h>
#include <stair.h>
#include <glm/vec2.hpp>

using droppingball::Stair;
using droppingball::Ball;
using droppingball::Container;
using droppingball::ballGame;

TEST_CASE("test if stair can move") {
    SECTION("Test the left position of the stair is correct after move") {
        Stair stair(glm::vec2(200,200), glm::vec2(400,400), glm::vec2(0,1));
        stair.Move();
        REQUIRE(stair.GetLeftPosition().y == 199);
    }
    SECTION("Test the right position of the stair is correct after move") {
        Stair stair(glm::vec2(200,200), glm::vec2(400,400), glm::vec2(0,1));
        stair.Move();
        REQUIRE(stair.GetRightPosition().y == 399);
    }
    SECTION("Test if the x axis of the stair is the same after move") {
        Stair stair(glm::vec2(200,200), glm::vec2(400,400), glm::vec2(0,1));
        stair.Move();
        REQUIRE(stair.GetLeftPosition().x == 200);
    }
}

TEST_CASE("test if can set the stair's positions") {
    Stair stair(glm::vec2(200,200), glm::vec2(400,400), glm::vec2(0,1));
    SECTION("Test if can set the left position of the stair") {
        stair.SetLeftPosition(glm::vec2(300,300));
        REQUIRE(stair.GetLeftPosition().y == 300);
    }
    SECTION("Test if can set the right position of the stair") {
        stair.SetRightPosition(glm::vec2(500,500));
        REQUIRE(stair.GetRightPosition().y == 500);
    }
}