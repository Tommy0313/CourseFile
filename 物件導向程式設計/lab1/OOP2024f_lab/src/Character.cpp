#include "../include/Character.hpp"

Character::Character(Point position, std::string id) {
     this->position = std::make_shared<Point>(position);
     this->id = id;
}

void Character::setPosition(int x, int y) {
    if (this->position->x + x > 15) {
        this->position->x = 15;
    }
    else if (this->position->x + x < 0) {
        this->position->x = 0;
    }
    else {
        this->position->x += x;
    }
    if (this->position->y + y > 15) {
        this->position->y = 15;
    }
    else if (this->position->y + y < 0) {
        this->position->y = 0;
    }
    else {
        this->position->y += y;
    }
}


Point Character::GetPosition() {
    return *this->position;
}
