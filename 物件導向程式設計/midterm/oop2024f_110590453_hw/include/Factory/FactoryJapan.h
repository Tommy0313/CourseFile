//
// Created by adven on 10/24/2024.
//

#ifndef OOP_MIDTERM_FACTORYJAPAN_H
#define OOP_MIDTERM_FACTORYJAPAN_H

#include <memory>

#include "Object/Boat.h"
#include "Object/Bus.h"
#include "Object/Plane.h"
#include "Object/Train.h"

namespace Factory {
namespace Japan {

std::shared_ptr<Bus> ProduceBus();

std::shared_ptr<Plane> ProducePlane();

std::shared_ptr<Boat> ProduceBoat();

std::shared_ptr<Train> ProduceTrain();

}  // namespace Japan
}  // namespace Factory

#endif  // OOP_MIDTERM_FACTORYJAPAN_H
