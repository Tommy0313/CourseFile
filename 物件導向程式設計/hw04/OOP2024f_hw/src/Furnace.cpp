//
// Created by adven on 11/28/2024.
//

#include "Furnace.hpp"
#include "Config.hpp"

void Furnace::AddIronOre(std::shared_ptr<IronOre> ore) {
}

void Furnace::AddGoldOre(std::shared_ptr<GoldOre> ore) {

}

std::vector<Product> Furnace::PickupProduct() {
}

#if TESTING_TARGET2

void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
}

#endif
#if TESTING_TARGET3

void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
}
#endif
