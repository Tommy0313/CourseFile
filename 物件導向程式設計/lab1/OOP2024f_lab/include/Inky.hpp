#ifndef INKY_HPP
#define INKY_HPP

#include "Character.hpp"

class Inky:public Character{
private:
  int mode = 1;
  int move_x = -3;
  int move_y = -3;
public:
  Inky(std::string id, Point position);
  virtual void DoBehavior(Point pacman) override;

};

#endif