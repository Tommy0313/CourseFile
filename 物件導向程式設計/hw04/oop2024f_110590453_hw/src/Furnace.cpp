//
// Created by adven on 11/28/2024.
//

#include "Furnace.hpp"
#include "Config.hpp"

void Furnace::AddIronOre(std::shared_ptr<IronOre> ore) {
    if(products.GetLength() == 0 or (products.GetLength() < 64 and products.GetLength() > 0 and nowSmelt == Product::Iron) ) {
        products.AddElement(ore->GetProduct());
        nowSmelt = Product::Iron;
    }
    else throw std::invalid_argument("Furnace::AddIronOre: Products are full or smelting gold");
}

void Furnace::AddGoldOre(std::shared_ptr<GoldOre> ore) {
    if(products.GetLength() == 0 or (products.GetLength() < 64 and products.GetLength() > 0 and nowSmelt == Product::Gold) ) {
        products.AddElement(ore->GetProduct());
        nowSmelt = Product::Gold;
    }
    else throw std::invalid_argument("Furnace::AddIronOre: Products are full or smelting iron");
}

List<Product> Furnace::PickupProduct() {
    List<Product> temp_products;
    temp_products = products;
    products = List<Product>();
    return temp_products;
}

#if TESTING_TARGET2

void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
    if(products.GetLength() == 0 or (products.GetLength() < 64 and products.GetLength() > 0 and nowSmelt == ore->GetProduct()) ) {
        products.AddElement(ore->GetProduct());
        nowSmelt = ore->GetProduct();
    }
    else throw std::invalid_argument("Furnace::AddOre: Products are full or smelting wrong");
}

#endif
#if TESTING_TARGET3

void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
    if(products.GetLength() == 0 or (products.GetLength() < 64 and products.GetLength() > 0 and nowSmelt == ore->GetProduct()) ) {
        products.AddElement(ore->GetProduct());
        nowSmelt = ore->GetProduct();
    }
    else throw std::invalid_argument("Furnace::AddOre: Products are full or smelting wrong");
}
#endif
