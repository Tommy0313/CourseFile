//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOP_FURNACE_HPP
#define OOP_FURNACE_HPP

#include <memory>
#include <vector>

#include "SmeltableOre.hpp"
#include "CoalOre.hpp"
#include "DiamondOre.hpp"
#include "GoldOre.hpp"
#include "IronOre.hpp"
#include "List.hpp"
#include "Ore.hpp"


#include "Config.hpp"

class Furnace final {
private:
    List<Product> products;
    Product nowSmelt = Product::Iron;
public:
    void AddIronOre(std::shared_ptr<IronOre> ore);

    void AddGoldOre(std::shared_ptr<GoldOre> ore);

    List<Product> PickupProduct();

#if TESTING_TARGET2
    void AddOre(std::shared_ptr<SmeltableOre> ore);
#endif
#if TESTING_TARGET3
    void AddAnyOre(std::shared_ptr<Ore> ore);
#endif
};

#endif // OOP_FURNACE_HPP
