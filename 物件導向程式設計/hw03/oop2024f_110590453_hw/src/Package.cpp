//
// Created by User on 2024/10/29.
//

#include "Package.hpp"

 Package::Package() {

}


void Package::SetMainDish(MainDish maindish) {
    this->maindish = std::make_shared<MainDish>(maindish);
}

void Package::SetSideDish(SideDish sidedish) {
    this->sidedish = std::make_shared<SideDish>(sidedish);
}

void Package::SetDrink(Drink drink) {
    this->drink = std::make_shared<Drink>(drink);
}

void Package::CountMoney() {
    int count = 0;
    if (this->maindish != nullptr) {
        this->money = this->money + this->maindish->GetMoney();
        count++;
    }
    if (this->sidedish != nullptr) {
        this->money = this->money + this->sidedish->GetMoney();
        count++;
    }
    if (this->drink != nullptr) {
        this->money = this->money + this->drink->GetMoney();
        count++;
    }
    if(count == 3) {
        this->money -= 15;
    }
}

int Package::GetMoney() {
    return this->money;
}





