//
// Created by User on 2024/10/29.
//

#include "MainDish.hpp"


MainDish::MainDish(Production id):Food(id) {
    this->id = id;
    MainDish::MakeFood();
}

void MainDish::AddIngredients(std::vector<Ingredients> addtional) {
    for (auto ingredient : addtional) {
        this->ingredient.push_back(ingredient);
        switch (ingredient) {
        case Ingredients::PorkSteak:
            this->money += 20;
            break;
        case Ingredients::BeefSteak:
            this->money += 20;
            break;
        case Ingredients::FishSteak:
            this->money += 20;
            break;
        case Ingredients::Lattuce:
            this->money += 10;
            break;
        case Ingredients::Cheese:
            this->money += 10;
            break;
        default:
            throw std::invalid_argument("Invalid ingredient");
        }
    }
}

void MainDish::MakeFood() {
    switch (this->id) {
    case Production::PorkBurger:
        this->money = 59;
        this->ingredient = {Ingredients::PorkSteak, Ingredients::Lattuce,Ingredients::BurgerBread,Ingredients::Cheese};
        break;
    case Production::BeefBurger:
        this->money = 69;
        this->ingredient = {Ingredients::BeefSteak, Ingredients::Lattuce,Ingredients::BurgerBread,Ingredients::Cheese};
        break;
    case Production::FishBurger:
        this->money = 79;
        this->ingredient = {Ingredients::FishSteak, Ingredients::Lattuce,Ingredients::BurgerBread,Ingredients::Cheese};
        break;
    }
}




