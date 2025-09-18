//
// Created by User on 2024/10/29.
//

#ifndef OOP_FOOD_HPP
#define OOP_FOOD_HPP

#include <string>
#include <vector>
#include "Ingredients.hpp"

class Food {
protected:
    Production id;
    std::vector<Ingredients> ingredient;
    int money;
public:
    Food(Production id);
    Production getId() const;
    std::vector<Ingredients> GetIngredient();
    virtual void MakeFood() = 0;
    int GetMoney();
};

#endif // OOP_FOOD_HPP
