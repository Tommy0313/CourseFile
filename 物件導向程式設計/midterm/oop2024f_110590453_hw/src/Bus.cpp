//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Bus.h"

Bus::Bus(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         wheel,
    int         maxSpeed
)
    : Vehicle(country, model, durability, type) {
    if(wheel < 0) {
        throw std::invalid_argument("");
    }
    if(maxSpeed < 0) {
        throw std::invalid_argument("");
    }
    if(wheel > 12) {
        throw std::invalid_argument("");
    }
    if(maxSpeed > 80) {
        throw std::invalid_argument("");
    }
    this->wheel = wheel;
    this->maxSpeed = maxSpeed;
}

FuelType Bus::GetFuelType() {
    return FuelType::Gasoline;
}
VehicleType Bus::GetVehicleType() {
    return VehicleType::BUS;
}

void Bus::ConsumeDurability() {
    if (country == "USA"){
        durability -= 5;
    }
    else if (country == "Japan"){
        durability -= 1;
    }
    else{
        durability -= 10;
    }
    if(GetDurability() < 0) {
        throw std::runtime_error("");
    }
}

int Bus::GetWheel() const {
    return wheel;
}
int Bus::GetMaxSpeed() const {
    return maxSpeed;
}

void Bus::SetMaxSpeed(int value) {
    if(value > 80) {
        throw std::invalid_argument("");
    }
    else {
        maxSpeed = value;
    }
}

void Bus::SetWheel(int value) {
    if(value > 12) {
        throw std::invalid_argument("");
    }
    else {
        wheel = value;
    }
}
