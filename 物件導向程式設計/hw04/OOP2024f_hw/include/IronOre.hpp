//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_IRONORE_HPP
#define OOP_IRONORE_HPP

#include "SmeltableOre.hpp"

class IronOre final {
protected:

public:
    explicit IronOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
    float GetSmeltExp() override;
};

#endif //OOP_IRONORE_HPP
