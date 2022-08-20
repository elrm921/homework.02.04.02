#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <iostream>
#include "list.h"

TEST_CASE( "List tests", "[list]" ) {
    List TestList;
    SECTION("PushBack and PopBack") {
        CHECK_THROWS_AS( TestList.PopBack(), std::runtime_error );
        TestList.PushBack(0);
        TestList.PushBack(1);
        TestList.PushBack(2);
        CHECK( TestList.Size() == 3 );
        CHECK( TestList.PopBack() == 2 );
        CHECK( TestList.PopBack() == 1 );
        CHECK( TestList.PopBack() == 0 );
        CHECK( TestList.Size() == 0 );
    };
    SECTION("PushFront and PopFront") {
        CHECK_THROWS_AS( TestList.PopFront(), std::runtime_error );
        TestList.PushFront(0);
        TestList.PushFront(1);
        TestList.PushFront(2);
        CHECK( TestList.Size() == 3 );
        CHECK( TestList.PopFront() == 2 );
        CHECK( TestList.PopFront() == 1 );
        CHECK( TestList.PopFront() == 0 );
        CHECK( TestList.Size() == 0 );
    };
    SECTION("Complex scenario") {
        TestList.PushBack(0);
        TestList.PushBack(1);
        TestList.PushBack(2);
        TestList.PushFront(2);
        TestList.PushFront(1);
        TestList.PushFront(0);
        CHECK( TestList.Size() == 6 );
        CHECK( TestList.PopFront() == 0 );
        CHECK( TestList.PopFront() == 1 );
        CHECK( TestList.PopBack() == 2 );
        CHECK( TestList.PopBack() == 1 );
        CHECK( TestList.Size() == 2 );
    }
}

int main() {
    std::cout << "Testing List class" << std::endl;
    return Catch::Session().run();
}