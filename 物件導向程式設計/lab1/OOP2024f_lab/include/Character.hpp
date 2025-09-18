#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <memory>


struct Point{
    int x = 0;
    int y = 0;
    Point(int x,int y): x(x),y(y) {}
};

class Character{
private:
    std::shared_ptr<Point> position;
    std::string id;
public:
    Character(Point position, std::string id);
    void setPosition(int x, int y);
    virtual void DoBehavior(Point pacman)=0; //移動位置
    Point GetPosition(); //回傳當前位置
};

#endif