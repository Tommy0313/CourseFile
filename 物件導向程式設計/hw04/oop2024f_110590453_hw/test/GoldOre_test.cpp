//
// Created by 陳世昂 on 2024/11/24.
//

#include "Ore.hpp"
#include "GoldOre.hpp"

#include <gtest/gtest.h>
#include <memory>

TEST(GOLDORE_SYSTEM_TEST, GoldOre_IscanBeBreak) {
    GoldOre ore = GoldOre();

    ASSERT_EQ(ore.Break(Pickaxe::Wooden), false);
    ASSERT_EQ(ore.Break(Pickaxe::Stone), false);
    ASSERT_EQ(ore.Break(Pickaxe::Iron), true);
    ASSERT_EQ(ore.Break(Pickaxe::Diamond), true);
    ASSERT_EQ(ore.Break(Pickaxe::Golden), true);
}

TEST(GOLDORE_SYSTEM_TEST, GoldOre_GetExp) {
    GoldOre ore = GoldOre();

    ASSERT_EQ(ore.GetBreakExp(), 0.0f);
    ASSERT_EQ(ore.GetSmeltExp(), 1.0f);
}

TEST(GOLDORE_SYSTEM_TEST, GoldOre_Product) {
    GoldOre ore = GoldOre();

    ASSERT_EQ(ore.GetProduct(), Product::Gold);
}