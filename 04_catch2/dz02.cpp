#include "mylist.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("Check PushBack PopBack", "[List][PushBack][PopBack][Back]") {
    List list;

    list.PushBack(11);
    REQUIRE(list.Size() == 1);
    REQUIRE_FALSE(list.Empty());

    int value = list.PopBack();
    REQUIRE(value == 11);
    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty());
}

TEST_CASE("Check PushFront PopFront", "[List][PushFront][PopFront][Front]") {
    List list;

    list.PushFront(100);
    REQUIRE(list.Size() == 1);

    int value = list.PopFront();
    REQUIRE(value == 100);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Check PopFront exception)", "[List][PopFront][Exception]") {
    List list;
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Check PopBack exception", "[List][PopBack][Exception]") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("Push/Pop", "[List][Scenario]") {
    List list;

    list.PushFront(10);
    list.PushBack(-10);
    list.PushFront(20);
    
    REQUIRE(list.Size() == 3);

    REQUIRE(list.PopBack() == -10);
    REQUIRE(list.Size() == 2);

    list.PushBack(-20);

    REQUIRE(list.PopFront() == 20);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopFront() == 10);

    REQUIRE(list.PopBack() == -20);
    
    REQUIRE(list.Empty());
}
