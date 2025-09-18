//
// Created by 陳世昂 on 2024/11/25.
//

#include <gtest/gtest.h>

#include "Furnace.hpp"
#include "IronOre.hpp"
#include "DiamondOre.hpp"
#include "GoldOre.hpp"
#include "CoalOre.hpp"
#include "Config.hpp"

TEST(FURNACE_SYSTEM_TEST, Furnace_IronOre) {
    auto furnace = Furnace();
    auto ironore = std::make_shared<IronOre>();

    furnace.AddIronOre(ironore);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front(), Product::Iron);
}

TEST(FURNACE_SYSTEM_TEST, Furnace_GoldOre) {
    auto furnace = Furnace();
    auto goldore = std::make_shared<GoldOre>();

    furnace.AddGoldOre(goldore);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front(), Product::Gold);
}

TEST(FURNACE_SYSTEM_TEST, Furnace_mix) {
    auto furnace = Furnace();
    auto goldore = std::make_shared<GoldOre>();
    auto ironore = std::make_shared<IronOre>();

    furnace.AddIronOre(ironore);
    ASSERT_THROW(furnace.AddGoldOre(goldore), std::invalid_argument);
}


TEST(FURNACE_SYSTEM_TEST, Furnace_mix_02) {
    auto furnace = Furnace();

    for(int i = 0 ;i<64; i++) {
        furnace.AddIronOre(std::make_shared<IronOre>());
    }
    ASSERT_THROW(furnace.AddIronOre(std::make_shared<IronOre>()), std::invalid_argument);
    auto product = furnace.PickupProduct();
    for (const auto elem: product) {
        ASSERT_EQ(elem, Product::Iron);
    }

    for(int i = 0 ;i<64; i++) {
        furnace.AddGoldOre(std::make_shared<GoldOre>());
    }
    ASSERT_THROW(furnace.AddGoldOre(std::make_shared<GoldOre>()), std::invalid_argument);

    auto product_gold = furnace.PickupProduct();
    for (const auto elem: product_gold) {
        ASSERT_EQ(elem, Product::Gold);
    }
}

#if TESTING_TARGET2

TEST(FURNACE_SYSTEM_TEST, Furnace_addore_Iron) {
    auto furnace = Furnace();

    furnace.AddOre(std::make_shared<IronOre>());

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front(), Product::Iron);
}

TEST(FURNACE_SYSTEM_TEST, Furnace_addore_Gold) {
    auto furnace = Furnace();

    furnace.AddOre(std::make_shared<GoldOre>());

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front(), Product::Gold);
}

#endif
#if TESTING_TARGET3
TEST(FURNACE_SYSTEM_TEST, Furnace_AddOre_all) {
    auto furnace = Furnace();

    furnace.AddOre(std::make_shared<IronOre>());
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<GoldOre>()), std::invalid_argument);
    furnace.AddOre(std::make_shared<IronOre>());

    furnace.PickupProduct();

    furnace.AddOre(std::make_shared<GoldOre>());
    furnace.AddOre(std::make_shared<GoldOre>());
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<DiamondOre>()), std::invalid_argument);
}
#endif