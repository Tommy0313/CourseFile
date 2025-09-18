#include "Object/Blinky.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"
#include <iostream>

namespace Object {

Blinky::Blinky() {}

std::string Blinky::GetName() const {
    return name;
};

Object::GamePosition Blinky::GetPosition() const {
    return pos;
};

void Blinky::SetState(Object::MonsterState s) {
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

void Blinky::Move(const Object::GamePosition& playerPos) {
    pos = state->Behavior(GhostType::BLINKY,pos,playerPos);
};
}  // namespace Object
