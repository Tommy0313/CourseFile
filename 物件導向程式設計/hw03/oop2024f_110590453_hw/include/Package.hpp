//
// Created by User on 2024/10/29.
//

#ifndef OOP_PACKAGE_HPP
#define OOP_PACKAGE_HPP

#include "MainDish.hpp"
#include "SideDish.hpp"
#include "Drink.hpp"
#include <stdexcept>
#include <memory>

class Package {
private:
    std::shared_ptr<MainDish> maindish = nullptr;
    std::shared_ptr<SideDish> sidedish = nullptr;
    std::shared_ptr<Drink> drink = nullptr;
    int money = 0;
public:
    Package();
    void CountMoney();
    void SetMainDish(MainDish maindish);
    void SetSideDish(SideDish sidedish);
    void SetDrink(Drink drink);
    int GetMoney();
};

#endif // OOP_PACKAGE_HPP
