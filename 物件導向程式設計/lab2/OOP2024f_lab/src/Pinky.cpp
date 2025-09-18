#include "Object/Pinky.hpp"

namespace Object {

Pinky::Pinky() {
};

std::string Pinky::GetName() const {
    return name;
};

Object::GamePosition Pinky::GetPosition() const {
    return pos;
};

void Pinky::SetState(Object::MonsterState s) {
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

void Pinky::Move(const Object::GamePosition& playerPos) {
     pos = state->Behavior(GhostType::PINKY,pos,playerPos);
}
}  // namespace Object
