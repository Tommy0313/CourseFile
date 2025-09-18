//
// Created by 陳世昂 on 2024/11/24.
//

#ifndef OOPHW_HW4_ORE_HPP
#define OOPHW_HW4_ORE_HPP

#include <iostream>

#include "Pickaxe.hpp"
#include "Product.hpp"

class Ore {
protected:
    Product product;
public:
    explicit Ore( Product pro);
    virtual ~Ore() = default;

    Product GetProduct() const;

    virtual bool Break(Pickaxe tool) = 0;
    virtual float GetBreakExp() = 0;
};

#endif // OOPHW_HW4_ORE_HPP
