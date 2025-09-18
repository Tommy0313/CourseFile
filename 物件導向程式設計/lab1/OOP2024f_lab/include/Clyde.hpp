#ifndef Clyde_HPP
#define Clyde_HPP

#include "Character.hpp"

class Clyde:public Character{
private:
public:
  Clyde(std::string id,Point position);
  virtual void DoBehavior(Point pacman) override;
};

#endif