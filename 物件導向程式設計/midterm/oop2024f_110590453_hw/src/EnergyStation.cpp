//
// Created by 陳世昂 on 2024/11/12.
//
#include "System/EnergyStation.hpp"
#include <stdexcept>

void EnergyStation::AddEnergy(int value) {
    if(value < 0) {
        throw std::invalid_argument("");
    }
    if(energy+value>10000) {
        throw std::invalid_argument("");
    }
    else {
        energy += value;
    }
}

void EnergyStation::AddFuel(int value) {
    if(value < 0) {
        throw std::invalid_argument("");
    }
    if(fuel+value>3000) {
        throw std::invalid_argument("");
    }
    else {
        fuel += value;
    }
}

int EnergyStation::GetEnergy() {
    return energy;
}
int EnergyStation::GetFuel() {
    return fuel;
}
void EnergyStation::ChargeVehicle(std::shared_ptr<Vehicle> vehicle) {
    switch (vehicle->GetFuelType()) {
    case FuelType::Electricity:
        vehicle->AddEnergy(1000-vehicle->GetEnergy());
        fuel -= 1000-vehicle->GetEnergy();
        break;
    case FuelType::Gasoline:
        vehicle->AddEnergy(1000-vehicle->GetEnergy());
        energy -= 1000-vehicle->GetEnergy();
        break;
    }
}
