#include "Object/Inky.hpp"
#include <iostream>

namespace Object {

Inky::Inky() {
};

std::string Inky::GetName() const {
    return name;
};

Object::GamePosition Inky::GetPosition() const {
    return pos;
};

void Inky::SetState(Object::MonsterState s) {
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

void Inky::Move(const Object::GamePosition& playerPos) {
    pos = state->Behavior(GhostType::INKY,pos,playerPos);
}
}  // namespace Object
