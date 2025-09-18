//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Train.h"
#include <stdexcept>

Train::Train(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         carriage,
    int         maxCarriage
): Vehicle(country, model, durability, type) {
    if(carriage < 0) {
        throw std::invalid_argument("");
    }
    if(maxCarriage < 0) {
        throw std::invalid_argument("");
    }
    if(maxCarriage > 12) {
        throw std::invalid_argument("");
    }
    if(carriage > maxCarriage) {
        throw std::invalid_argument("");
    }
    this->carriage = carriage;
    this->maxCarriage = maxCarriage;
}

FuelType Train::GetFuelType() {
    return FuelType::Electricity;
}
VehicleType Train::GetVehicleType() {
    return VehicleType::TRAIN;
}

void Train::ConsumeDurability() {
    if (country == "USA"){
        durability -= 4;
    }
    else if (country == "Japan"){
        durability -= 5;
    }
    else{
        durability -= 10;
    }
    if(GetDurability() < 0) {
        throw std::runtime_error("");
    }
}

int Train::GetCarriage() const {
    return carriage;
}
int Train::GetMaxCarriage() const {
    return maxCarriage;
}

void Train::SetMaxCarriage(int value) {
    if (value < 0) {
        throw std::invalid_argument("");
    }
    if(value > 12) {
        throw std::invalid_argument("");
    }
    else {
        maxCarriage = value;
    }
}

void Train::SetCarriage(int value) {
    if (value < 0) {
        throw std::invalid_argument("");
    }
    if(value > maxCarriage) {
        throw std::invalid_argument("");
    }
    else {
        carriage = value;
    }
}
