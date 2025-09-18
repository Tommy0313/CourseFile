

#include <Order.hpp>


Order::Order(std::vector<Production> product, std::vector<Ingredients> addtional, std::vector<bool> larger) {
    this->addtional = addtional;
    this->product = product;
    this->larger = larger;
}

std::vector<Production> Order::GetProductInfo(){
    return product;
}
std::vector<Ingredients> Order::GetAddtionalInfo(){
    return addtional;
}
std::vector<bool> Order::GetLargerInfo(){
    return larger;
}