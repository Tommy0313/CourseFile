//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Boat.h"

Boat::Boat(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         maxSpeed
)
    : Vehicle("null", "null", -1, type) {
}

FuelType Boat::GetFuelType() {
    return FuelType::Null;
}
VehicleType Boat::GetVehicleType() {
    return VehicleType::Null;
}

void Boat::ConsumeDurability() {}

int Boat::GetSailing() const {
    return -1;
}
int Boat::GetMaxSpeed() const {
    return -1;
}

void Boat::SetMaxSpeed(int value) {
}

void Boat::SetSailing(bool status) {
}
