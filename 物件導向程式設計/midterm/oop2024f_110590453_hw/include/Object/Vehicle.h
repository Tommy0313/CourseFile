//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_VEHICLE_H
#define OOP_MIDTERM_VEHICLE_H

#include <exception>
#include <string>

typedef std::string str;
enum class VehicleType {
    Null,
    BOAT,
    BUS,
    PLANE,
    TRAIN,
};

enum class FuelType { Null, Electricity, Gasoline };

class Vehicle {
protected:
    VehicleType type;
    std::string country;
    std::string model;
    int         durability = 0;
    int         energy = 0;

public:
    Vehicle(str c, str m, int d, VehicleType type);

    virtual VehicleType GetVehicleType() = 0;
    virtual FuelType    GetFuelType() = 0;
    virtual void        ConsumeDurability() = 0;

    int         GetDurability();
    int         GetEnergy();
    std::string GetCountry();
    std::string GetModel();

    void AddDurability(int value);
    void AddEnergy(int value);

    bool IsDurabilityZero();
};

#endif  // OOP_MIDTERM_VEHICLE_H
