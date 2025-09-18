//
// Created by 陳世昂 on 2024/11/12.
//

#include "Factory/FactoryJapan.h"

namespace Factory {
namespace Japan {

std::shared_ptr<Bus> ProduceBus() {
    return std::make_shared<Bus>("test", "test", -1, VehicleType::Null,  -1, -1);;
}

std::shared_ptr<Plane> ProducePlane() {
    return std::make_shared<Plane>("test", "test", -1, VehicleType::Null,  -1, -1);;
}

std::shared_ptr<Boat> ProduceBoat() {
    return std::make_shared<Boat>("test", "test", -1, VehicleType::Null, -1);;
}

std::shared_ptr<Train> ProduceTrain() {
  return std::make_shared<Train>("test", "test", -1, VehicleType::Null,  -1, -1);;
}

}  // namespace Japan
}  // namespace Factory
