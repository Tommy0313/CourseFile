//
// Created by 陳世昂 on 2024/11/12.
//

#include "Object/Vehicle.h"
#include <stdexcept>

Vehicle::Vehicle(str c, str m, int d, VehicleType type) {
    country = c;
    model = m;
    if(d < 0) {
        throw std::invalid_argument("");
    }
    else if(d > 100) {
        throw std::invalid_argument("");
    }
    else {
        durability = d;
    }
    this->type = type;
}

int Vehicle::GetDurability() {
    return durability;
}
int Vehicle::GetEnergy() {
    return energy;
}
std::string Vehicle::GetCountry() {
    return country;
}
std::string Vehicle::GetModel() {
    return model;
}

void Vehicle::AddDurability(int value) {
    if (durability+value > 100 || value < 0) {
        throw std::invalid_argument("");
    }
    else {
        durability += value;
    }
}

void Vehicle::AddEnergy(int value) {
    if (energy+value > 1000 || value < 0) {
        throw std::invalid_argument("");
    }
    else {
        energy += value;
    }
}

bool Vehicle::IsDurabilityZero() {
    if(durability <=0 ) {
        return true;
    }
    return false;
}
