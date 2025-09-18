//
// Created by 陳世昂 on 2024/11/24.
//

#include "Ore.hpp"
#include "IronOre.hpp"

#include <gtest/gtest.h>
#include <memory>

TEST(IRONORE_SYSTEM_TEST, IronOre_IscanBeBreak) {
    IronOre ore = IronOre();

    ASSERT_EQ(ore.Break(Pickaxe::Wooden), false);
    ASSERT_EQ(ore.Break(Pickaxe::Stone), true);
    ASSERT_EQ(ore.Break(Pickaxe::Iron), true);
    ASSERT_EQ(ore.Break(Pickaxe::Diamond), true);
    ASSERT_EQ(ore.Break(Pickaxe::Golden), true);
}

TEST(IRONORE_SYSTEM_TEST, IronOre_GetExp) {
    IronOre ore = IronOre();

    ASSERT_EQ(ore.GetBreakExp(), 0.0f);
    ASSERT_EQ(ore.GetSmeltExp(), 0.7f);
}

TEST(IRONORE_SYSTEM_TEST, IronOre_Product) {
    IronOre ore = IronOre();

    ASSERT_EQ(ore.GetProduct(), Product::Iron);
}