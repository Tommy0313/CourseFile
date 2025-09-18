#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Character.hpp"

class Pacman:public Character{
private:
public:
  Pacman(std::string id, Point position);
  virtual void DoBehavior(Point pacman) override;

};

#endif