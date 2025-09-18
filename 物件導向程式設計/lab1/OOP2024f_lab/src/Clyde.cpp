#include "../include/Clyde.hpp"

Clyde::Clyde(std::string id, Point position):Character(position,id) {

}

void Clyde::DoBehavior(Point pacman) {
    Point nowPosition = GetPosition();
    setPosition(pacman.x - nowPosition.x, pacman.y - nowPosition.y);
    /*
    if (nowPosition.x == pacman.x) {
        if (nowPosition.y > pacman.y) {
            setPosition(0,-2);
        }
        else {
            setPosition(0, 2);
        }
    }
    else if (nowPosition.y == pacman.y) {
        if (nowPosition.x > pacman.x) {
            setPosition(-2,0);
        }
        else {
            setPosition(2, 0);
        }
    }
    else {
        if(nowPosition.x > pacman.x) {
            setPosition(-3,0);
        }
        else if(nowPosition.x < pacman.x) {
            setPosition(3, 0);
        }
        if(nowPosition.y > pacman.y) {
            setPosition(0, -3);
        }
        else if(nowPosition.y < pacman.y) {
            setPosition(0, 3);
        }
    }
    */
}