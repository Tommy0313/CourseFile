//
// Created by adven on 11/28/2024.
//

#include "Ore.hpp"

Ore::Ore(Product pro) {
    this->product = pro;
}

Product Ore::GetProduct() const {
    return product;
}