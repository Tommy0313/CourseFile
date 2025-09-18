//
// Created by 陳世昂 on 2024/11/11.
//

#ifndef OOP_TRANSFERLAYER_HPP
#define OOP_TRANSFERLAYER_HPP

#include <memory>
#include "Object/Vehicle.h"

namespace Transform {
template<class T>
inline std::shared_ptr<Vehicle> UpCasting(std::shared_ptr<T> type) noexcept {
    return std::dynamic_pointer_cast<T>(type);
}
}

#endif  // OOP_TRANSFERLAYER_HPP
