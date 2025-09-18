#ifndef PINKY_HPP
#define PINKY_HPP

#include "Character.hpp"

class Pinky:public Character{
private:
  int mode = 0;
  int move_x = 3;
  int move_y = -3;
public:
  Pinky(std::string id, Point position);
  virtual void DoBehavior(Point pacman) override;

};

#endif