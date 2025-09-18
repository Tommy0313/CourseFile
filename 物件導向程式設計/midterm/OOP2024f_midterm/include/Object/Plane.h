//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_PLANE_H
#define OOP_MIDTERM_PLANE_H

#include "Vehicle.h"

#include <string>

class Plane final : public Vehicle {
private:

    /* member */
public:
    Plane(
        std::string country,
        std::string model,
        int         durability,
        VehicleType type,
        int         currentAltitude,
        int         maxAltitude
    );

    virtual FuelType    GetFuelType() override;
    virtual VehicleType GetVehicleType() override;
    virtual void        ConsumeDurability() override;

    int GetMaxAltitude() const;
    int GetCurrentAltitude() const;

    void SetCurrentAltitude(int value);
    void SetMaxAltitude(int value);

};

#endif  // OOP_MIDTERM_PLANE_H
