#ifndef OOP_MIDTERM_MAINTENANCESYSTEM_HPP
#define OOP_MIDTERM_MAINTENANCESYSTEM_HPP

#include <memory>

#include "Object/Boat.h"
#include "Object/Bus.h"
#include "Object/Plane.h"
#include "Object/Train.h"
#include "Object/Vehicle.h"
#include "TicketSystem.hpp"

void RepairVehicle(std::shared_ptr<Vehicle> vehicle);

#endif  // OOP_MIDTERM_MAINTENANCESYSTEM_HPP