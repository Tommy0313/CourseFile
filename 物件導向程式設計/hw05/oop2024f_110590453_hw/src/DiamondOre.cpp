#include "DiamondOre.hpp"

bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
    if(pickaxe==Pickaxe::Iron) {
        return true;
    }
    if(pickaxe==Pickaxe::Diamond) {
        return true;
    }
    return false;
}
