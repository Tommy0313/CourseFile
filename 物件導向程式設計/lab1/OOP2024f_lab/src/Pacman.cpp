#include "../include/Pacman.hpp"

#include <iostream>

Pacman::Pacman(std::string id, Point position):Character(position,id) {

}

void Pacman::DoBehavior(Point pacman) {
    char word;
    std::cin >> word;

    switch (word) {
        case 'W':
            setPosition(0,3);
            break;
        case 'A':
            setPosition(-3,0);
            break;
        case 'S':
            setPosition(0,-3);
            break;
        case 'D':
            setPosition(3,0);
            break;
    }
}