#ifndef GOLD_ORE_HPP
#define GOLD_ORE_HPP

#include "ISmeltable.hpp"
#include "Ingot.hpp"
#include "Ore.hpp"

class GoldOre : public Ore,public ISmeltable{
public:
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;
};

#endif
