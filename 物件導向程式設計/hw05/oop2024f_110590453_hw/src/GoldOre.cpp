#include "GoldOre.hpp"

#include <memory>

#include "GoldIngot.hpp"

bool GoldOre::BreakableBy(Pickaxe pickaxe) {
    if(pickaxe==Pickaxe::Iron) {
        return true;
    }
    if(pickaxe==Pickaxe::Diamond) {
        return true;
    }
    return false;
}

std::shared_ptr<Ingot> GoldOre::Smelt() {
    return std::make_shared<GoldIngot>();
}
