#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include "Ingredients.hpp"

class Order{
private:
    std::vector<Production> product;
    std::vector<Ingredients> addtional;
    std::vector<bool> larger;
public:
    Order(std::vector<Production> product, std::vector<Ingredients> addtional ,std::vector<bool> larger);
    std::vector<Production> GetProductInfo();
    std::vector<Ingredients> GetAddtionalInfo();
    std::vector<bool> GetLargerInfo();
};

#endif