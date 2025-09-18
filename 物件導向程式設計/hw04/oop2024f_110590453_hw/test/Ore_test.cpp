//
// Created by 陳世昂 on 2024/11/25.
//

#include <gtest/gtest.h>

#include "Ore.hpp"
#include "SmeltableOre.hpp"

class inher : public Ore {
public:
    inher(Product pro)
        : Ore(pro){};

    virtual bool Break(Pickaxe tool) override {return false;}
    float GetBreakExp() { return 0.1f;}
};

TEST(ORE_SYSTEM_TEST, ore_default) {
    auto ore = inher(Product::Iron);

    ASSERT_EQ(ore.GetBreakExp(), 0.1f);
    ASSERT_EQ(ore.GetProduct(), Product::Iron);
}

class inher02 : public SmeltableOre {
public:
    inher02(Product pro) : SmeltableOre(pro) {};

    virtual bool Break(Pickaxe tool) override {return true;}
    float GetBreakExp() { return 0.2;}
    float GetSmeltExp() { return 0.3;}
};


TEST(ORE_SYSTEM_TEST, ore_inher) {
    auto ore = inher02(Product::Diamond);
    ASSERT_EQ(ore.GetSmeltExp(), 0.3f);
    ASSERT_EQ(ore.GetProduct(), Product::Diamond);
}