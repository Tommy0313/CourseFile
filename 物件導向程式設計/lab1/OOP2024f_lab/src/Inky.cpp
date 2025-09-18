#include "../include/Inky.hpp"

Inky::Inky(std::string id, Point position):Character(position,id) {

}

void Inky::DoBehavior(Point pacman) {
    Point nowPosition = GetPosition();
    setPosition(move_x,move_y);
    if(mode == 0) {
        if(nowPosition.x == 15) {
            mode = 1;
            move_x = 3;
            move_y = 3;
        }
    }
    else if(mode == 1) {
        if(nowPosition.x == 0) {
            mode = 0;
            move_x = -3;
            move_y = -3;
        }
    }
}
