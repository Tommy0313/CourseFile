#include "Object/Clyde.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"
#include <iostream>

namespace Object {

Clyde::Clyde() {
};

std::string Clyde::GetName() const {
    return name;
};

Object::GamePosition Clyde::GetPosition() const {
    return pos;
};

void Clyde::SetState(Object::MonsterState s) {
    switch (s) {
    case Object::MonsterState::Chase:
        state = std::make_shared<State::ChaseState>();
        break;
    case Object::MonsterState::Scatter:
        state = std::make_shared<State::ScatterState>();
        break;
    default:
        throw std::invalid_argument("Unknown state");
    }
}

void Clyde::Move(const Object::GamePosition& playerPos) {
    pos = state->Behavior(GhostType::CLYDE,pos,playerPos);
}
}  // namespace Object
