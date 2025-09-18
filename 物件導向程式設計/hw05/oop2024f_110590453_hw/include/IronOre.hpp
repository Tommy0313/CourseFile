#ifndef IRON_ORE_HPP
#define IRON_ORE_HPP

#include "ISmeltable.hpp"
#include "Ingot.hpp"
#include "Ore.hpp"

class IronOre : public Ore,public ISmeltable{
public:
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;
};

#endif
