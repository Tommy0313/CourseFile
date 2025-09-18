#include <gtest/gtest.h>

#include "hello.hpp"

TEST(HW0, test_hello_world) {
    EXPECT_EQ(hello_world(), "Hello World!");
}
