#ifndef GOLD_INGOT_HPP
#define GOLD_INGOT_HPP

#include "ICraftable.hpp"
#include "Ingot.hpp"

class GoldIngot:public Ingot,public ICraftable{
public:
    Armor CraftArmor() override;
};

#endif
