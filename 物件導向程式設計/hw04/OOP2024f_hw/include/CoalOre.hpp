//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_COALORE_HPP
#define OOP_COALORE_HPP

#include "Ore.hpp"

class CoalOre final{
protected:

public:
    explicit CoalOre();

    bool Break(Pickaxe tool) override;
    float GetBreakExp() override;
};

#endif //OOP_COALORE_HPP
