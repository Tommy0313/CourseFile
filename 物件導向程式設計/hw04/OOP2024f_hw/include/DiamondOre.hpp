//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_DIAMONDORE_HPP
#define OOP_DIAMONDORE_HPP

#include "Ore.hpp"

class DiamondOre {
protected:
public:
    explicit DiamondOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
};

#endif // OOP_DIAMONDORE_HPP
