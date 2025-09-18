//
// Created by User on 2024/10/29.
//

#ifndef OOP_MAINDISH_HPP
#define OOP_MAINDISH_HPP

#include "Food.hpp"
#include <vector>
#include <stdexcept>
#include "Ingredients.hpp"

class MainDish : public Food {
private:
    std::vector<Ingredients> addtional;
public:
    MainDish(Production id);
    virtual void MakeFood() override;
    void AddIngredients(std::vector<Ingredients> addtional);
};

#endif // OOP_MAINDISH_HPP
