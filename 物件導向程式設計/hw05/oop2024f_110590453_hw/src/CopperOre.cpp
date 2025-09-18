#include "CopperOre.hpp"

#include "CopperIngot.hpp"


bool CopperOre::BreakableBy(Pickaxe pickaxe) {
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

std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<CopperIngot>();
}



