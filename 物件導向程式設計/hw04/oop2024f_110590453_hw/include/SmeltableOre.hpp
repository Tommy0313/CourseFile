//
// Created by 陳世昂 on 2024/12/2.
//

#ifndef OOP_SMELTABLEORE_HPP
#define OOP_SMELTABLEORE_HPP

#include "Ore.hpp"

class SmeltableOre : public Ore {
public:
    explicit SmeltableOre(Product pro);
    virtual ~SmeltableOre() = default;

    virtual float GetSmeltExp() = 0;
};

#endif // OOP_SMELTABLEORE_HPP
