//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_CAR_H
#define OOP_MIDTERM_CAR_H

#include "Vehicle.h"

#include <stdexcept>
#include <string>

#define String std::string

class Bus : public Vehicle {
private:
    int wheel = 0;
    int maxSpeed = 0;

public:
    Bus(std::string country,
        std::string model,
        int         durability,
        VehicleType type,
        int         wheel,
        int         maxSpeed);

    virtual FuelType    GetFuelType() override;
    virtual VehicleType GetVehicleType() override;
    virtual void        ConsumeDurability() override;

    int GetWheel() const;
    int GetMaxSpeed() const;

    void SetWheel(int value);
    void SetMaxSpeed(int value);
};

#endif  // OOP_MIDTERM_CAR_H
