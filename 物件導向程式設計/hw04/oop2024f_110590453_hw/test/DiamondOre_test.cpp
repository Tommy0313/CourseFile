//
// Created by 陳世昂 on 2024/11/24.
//

#include <gtest/gtest.h>
#include <memory>

#include "DiamondOre.hpp"

TEST(DIAMONDORE_SYSTEM_TEST, DiamondOre_IsCanBeBreak) {
    DiamondOre ore = DiamondOre();

    ASSERT_EQ(ore.Break(Pickaxe::Wooden), false);
    ASSERT_EQ(ore.Break(Pickaxe::Stone), false);
    ASSERT_EQ(ore.Break(Pickaxe::Iron), true);
    ASSERT_EQ(ore.Break(Pickaxe::Diamond), true);
    ASSERT_EQ(ore.Break(Pickaxe::Golden), true);
}

TEST(DIAMONDORE_SYSTEM_TEST, DiamondOre_GetExp) {
    DiamondOre ore = DiamondOre();

    ASSERT_EQ(ore.GetBreakExp(), 4.0f);
}

TEST(DIAMONDORE_SYSTEM_TEST, DiamondOre_Product) {
    DiamondOre ore = DiamondOre();

    ASSERT_EQ(ore.GetProduct(), Product::Diamond);
}