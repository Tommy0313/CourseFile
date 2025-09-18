#include "IronOre.hpp"

#include "IronIngot.hpp"

bool IronOre::BreakableBy(Pickaxe pickaxe) {
    if(pickaxe==Pickaxe::Stone) {
        return true;
    }
    if(pickaxe==Pickaxe::Iron) {
        return true;
    }
    if(pickaxe==Pickaxe::Diamond) {
        return true;
    }
    return false;
}

std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<IronIngot>();
}


