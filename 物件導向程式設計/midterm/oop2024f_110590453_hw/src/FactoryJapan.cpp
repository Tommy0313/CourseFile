//
// Created by 陳世昂 on 2024/11/12.
//

#include "Factory/FactoryJapan.h"

namespace Factory {
namespace Japan {

std::shared_ptr<Bus> ProduceBus() {
    return std::make_shared<Bus>(Bus("Japan", "Yamaha", 0, VehicleType::BUS,  12, 80));;
}

std::shared_ptr<Plane> ProducePlane() {
    return std::make_shared<Plane>(Plane("Japan", "Mitsubishi", 0, VehicleType::PLANE,  0, 12000));;
}

std::shared_ptr<Boat> ProduceBoat() {
    return std::make_shared<Boat>(Boat("Japan", "Shinkansen", 0, VehicleType::BOAT, 30));;
}

std::shared_ptr<Train> ProduceTrain() {
  return std::make_shared<Train>(Train("Japan", "Toyota", 0, VehicleType::TRAIN,  6, 12));;
}

}  // namespace Japan
}  // namespace Factory
