#include "mylist.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("Check Empty", "[List][Empty]") {
    List list;
    REQUIRE(list.Empty() == true);

    list.PushFront(10);
    REQUIRE(list.Empty() == false); 
}

TEST_CASE("Check Size", "[List][Size]") {
    List list;
    REQUIRE(list.Size() == 0);

    list.PushFront(1);
    REQUIRE(list.Size() == 1);

    list.PushBack(2);
    REQUIRE(list.Size() == 2);

    list.PopFront();
    REQUIRE(list.Size() == 1);

    list.PopBack();
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Check Clear", "[List][Clear]") {
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.Empty() == false);

    list.Clear();

    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);
}