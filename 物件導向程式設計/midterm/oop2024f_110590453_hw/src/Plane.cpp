//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Plane.h"
#include <stdexcept>

Plane::Plane(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         currentAltitude,
    int         maxAltitude
): Vehicle(country, model, durability, type){
    if(currentAltitude < 0) {
        throw std::invalid_argument("");
    }
    if(maxAltitude < 0) {
        throw std::invalid_argument("");
    }
    if(maxAltitude > 40000) {
        throw std::invalid_argument("");
    }
    if(currentAltitude > maxAltitude) {
        throw std::invalid_argument("");
    }
    this->currentAltitude = currentAltitude;
    this->maxAltitude = maxAltitude;
}

FuelType Plane::GetFuelType() {
    return FuelType::Gasoline;
}
VehicleType Plane::GetVehicleType() {
    return VehicleType::PLANE;
}

void Plane::ConsumeDurability() {
    if (country == "USA"){
        durability -= 30;
    }
    else if (country == "Japan"){
        durability -= 2;
    }
    else{
        durability -= 10;
    }
    if(GetDurability() < 0) {
        throw std::runtime_error("");
    }
}

int Plane::GetMaxAltitude() const {
    return maxAltitude;
}
int Plane::GetCurrentAltitude() const {
    return currentAltitude;
}

void Plane::SetMaxAltitude(int value) {
    if(value > 40000) {
        throw std::invalid_argument("");
    }
    else {
        maxAltitude = value;
    }
}

void Plane::SetCurrentAltitude(int value) {
    if(value > maxAltitude) {
        throw std::invalid_argument("");
    }
    else {
        currentAltitude = value;
    }
}
