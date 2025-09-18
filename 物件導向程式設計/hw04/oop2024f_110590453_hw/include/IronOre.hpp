//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_IRONORE_HPP
#define OOP_IRONORE_HPP

#include "SmeltableOre.hpp"

class IronOre:public SmeltableOre{
protected:
    const float breakExp = 0;
    const float smeltExp = 0.7;
public:
    explicit IronOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
    float GetSmeltExp() override;
};

#endif //OOP_IRONORE_HPP
