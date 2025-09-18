//
// Created by User on 2024/10/29.
//

#include "SideDish.hpp"

SideDish::SideDish(Production id):Food(id) {
    this->id = id;
    SideDish::MakeFood();
}

void SideDish::MakeLarger() {
    switch(this->id) {
        case Production::Frenchfries:
            this->type = SideDishType::BIG;
            this->money = 59;
            break;
        case Production::Nugget:
            this->type = SideDishType::BIG;
            this->money = 59;
            break;
        case Production::Salad:
            break;
    }
}

void SideDish::MakeFood() {
    switch(this->id) {
        case Production::Frenchfries:
            this->money = 44;
            this->ingredient = {Ingredients::FranchFries};
            break;
        case Production::Nugget:
            this->money = 44;
            this->ingredient= {Ingredients::ChickenNugget};
            break;
        case Production::Salad:
            this->money = 59;
            this->ingredient= {Ingredients::Salad};
            break;
    }
}

SideDishType SideDish::GetType() {
    return this->type;
}


