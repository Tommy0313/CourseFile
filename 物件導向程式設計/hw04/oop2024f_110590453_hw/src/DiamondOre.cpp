//
// Created by adven on 11/28/2024.
//

#include "DiamondOre.hpp"

DiamondOre::DiamondOre():Ore(Product::Diamond){}

bool DiamondOre::Break(Pickaxe tool) {
    if(tool == Pickaxe::Wooden or tool == Pickaxe::Stone)return false;
    return true;
}

float DiamondOre::GetBreakExp() {
    return breakExp;
}
