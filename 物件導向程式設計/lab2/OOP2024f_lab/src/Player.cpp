#include "Object/Player.hpp"
#include "Object/GameObject.hpp"

namespace Object {

std::string Player::GetName() const {
    return name;
};

Object::GamePosition Player::GetPosition() const {
    return pos;
};

void Player::Move(char direction) {
    switch (direction) {
        case 'w':
            pos.y += 1;
            break;
        case 'a':
            pos.x -= 1;
            break;
        case 's':
            pos.y -= 1;
            break;
        case 'd':
            pos.x += 1;
            break;
    }
    if (pos.x > 11) {
        pos.x = 11;
    }
    else if (pos.x < 0) {
        pos.x = 0;
    }

    if (pos.y > 11) {
        pos.y = 11;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }
}

bool Player::IsOutRange() {
    return (pos.x < 0 || pos.x >= 12 || pos.y < 0 || pos.y >= 12);
}

}  // namespace Object
