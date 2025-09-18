#ifndef COPPER_ORE_HPP
#define COPPER_ORE_HPP

#include "ISmeltable.hpp"
#include "Ingot.hpp"
#include "Ore.hpp"
#include "CopperIngot.hpp"

class CopperOre : public Ore, public ISmeltable{
public:
    bool BreakableBy(Pickaxe pickaxe) override;

    std::shared_ptr<Ingot> Smelt() override;
};

#endif
