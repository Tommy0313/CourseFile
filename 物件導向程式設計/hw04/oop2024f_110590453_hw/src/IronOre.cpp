//
// Created by adven on 11/28/2024.
//

#include "IronOre.hpp"

IronOre::IronOre():SmeltableOre(Product::Iron){}

bool IronOre::Break(Pickaxe tool) {
    if(tool == Pickaxe::Wooden) return false;
    return true;
}

float IronOre::GetBreakExp() {
    return breakExp;
}

float IronOre::GetSmeltExp() {
    return smeltExp;
}