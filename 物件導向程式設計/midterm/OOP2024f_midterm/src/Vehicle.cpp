//
// Created by 陳世昂 on 2024/11/12.
//

#include "Object/Vehicle.h"

Vehicle::Vehicle(str c, str m, int d, VehicleType type) {}

int Vehicle::GetDurability() {
    return -1;
}
int Vehicle::GetEnergy() {
    return -1;
}
std::string Vehicle::GetCountry() {
    return "";
}
std::string Vehicle::GetModel() {
    return "";
}

void Vehicle::AddDurability(int value) {
}

void Vehicle::AddEnergy(int value) {
}

bool Vehicle::IsDurabilityZero() {
    return false;
}
