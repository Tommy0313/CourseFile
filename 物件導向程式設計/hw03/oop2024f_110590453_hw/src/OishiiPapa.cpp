#include "OishiiPapa.hpp"

OishiiPapa::OishiiPapa() {

}

void OishiiPapa::SendOrder(Order order) {
    this->pipeline.push(order);
}

void OishiiPapa::MakeDish() {
    if (this->pipeline.empty()) {
        throw std::out_of_range("OishiiPapa::MakeDish: pipeline is empty");
    }
    else {
        if(this->chest.size()<15) {
            Order order = this->pipeline.front();
            this->pipeline.pop();
            Package package;
            if(order.GetProductInfo()[0] != Production::_NULL) {
                MainDish mainDish(order.GetProductInfo()[0]);
                mainDish.AddIngredients(order.GetAddtionalInfo());
                package.SetMainDish(mainDish);
            }
            if(order.GetProductInfo()[1] != Production::_NULL) {
                SideDish sideDish(order.GetProductInfo()[1]);
                if(order.GetLargerInfo()[0]) {
                    sideDish.MakeLarger();
                }
                package.SetSideDish(sideDish);
            }
            if(order.GetProductInfo()[2] != Production::_NULL) {
                Drink drink(order.GetProductInfo()[2]);
                if(order.GetLargerInfo()[1]) {
                    drink.MakeLarger();
                }
                package.SetDrink(drink);
            }
            package.CountMoney();
            chest.push(package);
        }
    }
}

Package OishiiPapa::Pickup() {
    MakeDish();
    if(chest.empty()) {
        throw std::out_of_range("OishiiPapa::Pickup: chest is empty");
    }
    else {
        Package package = chest.front();
        chest.pop();
        money += package.GetMoney();

        return package;
    }
}


int OishiiPapa::GetMoney() {
    return this->money;
}

Order OishiiPapa::GetOrderInfo() {
    return this->pipeline.front();
}





