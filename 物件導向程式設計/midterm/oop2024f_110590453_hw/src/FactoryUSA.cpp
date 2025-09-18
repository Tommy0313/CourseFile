//
// Created by 陳世昂 on 2024/11/12.
//

#include "Factory/FactoryUSA.h"

namespace Factory{
namespace USA {

std::shared_ptr<Bus> ProduceBus() {
    return std::make_shared<Bus>(Bus("USA", "Ford", 0, VehicleType::BUS,  12, 80));;
}

std::shared_ptr<Plane> ProducePlane() {
    return std::make_shared<Plane>(Plane("USA", "Boeing", 0, VehicleType::PLANE,  0, 12000));;
}

std::shared_ptr<Boat> ProduceBoat() {
    return std::make_shared<Boat>(Boat("USA", "Bayliner", 0, VehicleType::BOAT, 30));;
}

std::shared_ptr<Train> ProduceTrain() {
    return std::make_shared<Train>(Train("USA", "Amtrak", 0, VehicleType::TRAIN,  6, 12));;
}

}
}