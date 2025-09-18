#ifndef OOP_MIDTERM_ENERGYSTATION_SYSTEM_HPP
#define OOP_MIDTERM_ENERGYSTATION_SYSTEM_HPP

#include <memory>
#include "Object/Vehicle.h"

class EnergyStation final {
private:
/* member */
public:
    void AddEnergy(int value);
    void AddFuel(int value);

    int GetEnergy();
    int GetFuel();

    void ChargeVehicle(std::shared_ptr<Vehicle> vehicle);
};

#endif  // OOP_MIDTERM_ENERGYSTATION_HPP
