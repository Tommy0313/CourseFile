//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_GOLDORE_HPP
#define OOP_GOLDORE_HPP

#include "SmeltableOre.hpp"

class GoldOre:public SmeltableOre{
protected:
    const float breakExp = 0;
    const float smeltExp = 1.0;
public:
    explicit GoldOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
    float GetSmeltExp() override;
};

#endif //OOP_GOLDORE_HPP
