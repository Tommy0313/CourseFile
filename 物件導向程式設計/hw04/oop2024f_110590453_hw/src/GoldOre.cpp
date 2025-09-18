//
// Created by adven on 11/28/2024.
//

#include "GoldOre.hpp"

GoldOre::GoldOre():SmeltableOre(Product::Gold) {}

bool GoldOre::Break(Pickaxe tool) {
    if(tool == Pickaxe::Wooden or tool == Pickaxe::Stone)return false;
    return true;
}

float GoldOre::GetBreakExp() {
    return breakExp;
}

float GoldOre::GetSmeltExp() {
    return smeltExp;
}