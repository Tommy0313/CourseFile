#ifndef OISHII_PAPA_HPP
#define OISHII_PAPA_HPP

#include "Drink.hpp"
#include "MainDish.hpp"
#include "SideDish.hpp"
#include "Package.hpp"
#include "Order.hpp"
#include <queue>
class OishiiPapa{
private:
    std::queue<Order> pipeline;
    std::queue<Package> chest;
    int money = 0;
public:
    OishiiPapa();
    void MakeDish();
    void SendOrder(Order order);
    Package Pickup();
    int GetMoney();
    Order GetOrderInfo();
};

#endif