//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Plane.h"

Plane::Plane(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         currentAltitude,
    int         maxAltitude
): Vehicle("null", "null", -1, type){
}

FuelType Plane::GetFuelType() {
    return FuelType::Null;
}
VehicleType Plane::GetVehicleType() {
    return VehicleType::Null;
}

void Plane::ConsumeDurability() {
}

int Plane::GetMaxAltitude() const {
    return -1;
}
int Plane::GetCurrentAltitude() const {
    return -1;
}

void Plane::SetMaxAltitude(int value) {
}

void Plane::SetCurrentAltitude(int value) {
}
