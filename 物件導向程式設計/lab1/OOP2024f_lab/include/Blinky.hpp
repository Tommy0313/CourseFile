#ifndef BLINKY_HPP
#define BLINKY_HPP

#include "Character.hpp"

class Blinky:public Character{
private:
  int mode = 0;
  int move_x = 0;
  int move_y = 3;
public:
  Blinky(std::string id,Point position);
  virtual void DoBehavior(Point pacman) override;
};

#endif