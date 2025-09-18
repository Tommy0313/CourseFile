//
// Created by User on 2024/10/29.
//

#include "Drink.hpp"

Drink::Drink(Production id):Food(id) {
    this->id = id;
    MakeFood();
}

int Drink::GetMl() {
    return this->ml;
}

void Drink::MakeLarger() {
    this->ml = 750;
    switch(this->id) {
        case Production::Cola:
            this->money = 38;
            break;
        case Production::Spirit:
            this->money = 38;
            break;
        case Production::Latte:
            this->money = 55;
            break;
        }
}


void Drink::MakeFood() {
    this->ml = 550;
    switch (this->id) {
        case Production::Cola:
            this->money = 28;
            this->ingredient = {Ingredients::Cola};
            break;
        case Production::Spirit:
            this->money = 28;
            this->ingredient= {Ingredients::Spirit};
            break;
        case Production::CaramelMilktea:
            this->money = 44;
            this->ingredient= {Ingredients::Milktea, Ingredients::Caramel};
            break;
        case Production::Latte:
            this->money = 45;
            this->ingredient= {Ingredients::Coffee, Ingredients::Milk};
            break;
    }
}
