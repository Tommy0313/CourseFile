#include "../include/Blinky.hpp"
//#include "../include/Character.hpp"
//#include <iostream>

Blinky::Blinky(std::string id, Point position) :Character(position,id){

}

void Blinky::DoBehavior(Point pacman) {
    Point position = GetPosition();
    setPosition(move_x,move_y);
    if (mode==0) {
        if (position.y == 15) {
            mode = 1;
            move_x = 3;
            move_y = 0;
        }
    }
    else if (mode==1) {
        if (position.x == 15) {
            mode = 2;
            move_x = 0;
            move_y = -3;
        }
    }
    else if (mode==2) {
        if (position.y == 0) {
            mode = 3;
            move_x = -3;
            move_y = 0;
        }
    }
    else if (mode==3) {
        if (position.x == 0) {
            mode = 0;
            move_x = 0;
            move_y = 3;
        }
    }
}

