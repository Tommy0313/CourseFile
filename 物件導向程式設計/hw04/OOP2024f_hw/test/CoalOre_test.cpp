//
// Created by 陳世昂 on 2024/11/24.
//

#include "Ore.hpp"
#include "CoalOre.hpp"

#include <gtest/gtest.h>
#include <memory>

TEST(COALORE_SYSTEM_TEST, CoalOre_IscanBeBreak) {
    CoalOre ore = CoalOre();

    ASSERT_EQ(ore.Break(Pickaxe::Wooden), true);
    ASSERT_EQ(ore.Break(Pickaxe::Stone), true);
    ASSERT_EQ(ore.Break(Pickaxe::Iron), true);
    ASSERT_EQ(ore.Break(Pickaxe::Diamond), true);
    ASSERT_EQ(ore.Break(Pickaxe::Golden), true);
}

TEST(COALORE_SYSTEM_TEST, CoalOre_GetExp) {
    CoalOre ore = CoalOre();

    ASSERT_EQ(ore.GetBreakExp(), 2.0f);
}

TEST(COALORE_SYSTEM_TEST, CoalOre_Product) {
    CoalOre ore = CoalOre();

    ASSERT_EQ(ore.GetProduct(), Product::Coal);
}
