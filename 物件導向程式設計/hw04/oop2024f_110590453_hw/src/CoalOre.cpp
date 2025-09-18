//
// Created by adven on 11/28/2024.
//

#include "CoalOre.hpp"

CoalOre::CoalOre():Ore(Product::Coal)  {

}

bool CoalOre::Break(Pickaxe tool) {
    return true;
}


float CoalOre::GetBreakExp() {
    return breakExp;
}
