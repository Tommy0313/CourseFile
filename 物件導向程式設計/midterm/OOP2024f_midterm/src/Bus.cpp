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
    : Vehicle("null", "null", -1, type){}

FuelType Bus::GetFuelType() {
    return FuelType::Null;
}
VehicleType Bus::GetVehicleType() {
    return VehicleType::Null;
}

void Bus::ConsumeDurability() {
}

int Bus::GetWheel() const {
    return 0;
}
int Bus::GetMaxSpeed() const {
    return 0;
}

void Bus::SetMaxSpeed(int value) {
}

void Bus::SetWheel(int value) {
}
