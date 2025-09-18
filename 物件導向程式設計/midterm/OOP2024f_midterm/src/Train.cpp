//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Train.h"

Train::Train(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         carriage,
    int         maxCarriage
)
    : Vehicle("null", "null", -1, type){}

FuelType Train::GetFuelType() {
    return FuelType::Null;
}
VehicleType Train::GetVehicleType() {
    return VehicleType::Null;
}

void Train::ConsumeDurability() {}

int Train::GetCarriage() const {
    return 0;
}
int Train::GetMaxCarriage() const {
    return 0;
}

void Train::SetMaxCarriage(int value) {
}

void Train::SetCarriage(int value) {
}
