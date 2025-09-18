#ifndef DIAMOND_ORE_HPP
#define DIAMOND_ORE_HPP

#include "Ore.hpp"

class DiamondOre:public Ore{
public:
    bool BreakableBy(Pickaxe pickaxe) override;
};

#endif
