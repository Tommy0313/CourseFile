//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_BOAT_H
#define OOP_MIDTERM_BOAT_H

#include <exception>
#include <iostream>
#include <string>
#include "Vehicle.h"

class Boat : public Vehicle {
private:
    bool sailing = false;
    int  maxSpeed = 0;

public:
    Boat(
        std::string country,
        std::string model,
        int         durability,
        VehicleType type,
        int         maxSpeed
    );

    virtual FuelType GetFuelType() override ;
    virtual VehicleType GetVehicleType() override ;
    virtual void ConsumeDurability() override;

    void SetSailing(bool status);
    void SetMaxSpeed(int value) ;

    int                 GetSailing() const ;
    int                 GetMaxSpeed() const ;
};

#endif  // OOP_MIDTERM_BOAT_H
