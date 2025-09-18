//
// Created by adven on 11/28/2024.
//

#include <gtest/gtest.h>

#include "List.hpp"

#if TESTING_TARGET2
TEST(LIST_SYSTEM_TEST, List_GetLength) {
    List<int> list;
    ASSERT_EQ(list.GetLength(), 0);
}

TEST(LIST_SYSTEM_TEST, List_Generation_operation) {

    List<int> list;
    list.AddElement(1);

    ASSERT_EQ(list.GetLength(), 1);
    ASSERT_EQ(list.PopElement(), 1);
    ASSERT_EQ(list.GetLength(), 0);
}
#endif
