//
// Created by oscar on 14.01.2022.
//

#include "Robot.h"

Data Robot::suivant  = 1;
Data Robot::total    = 0;

Robot::Robot():NO_(suivant) {
   coord.first = coord.second = 0;
   ++total;
   ++suivant;
}

Robot::~Robot() {
   --total;
}

Robot::Robot(Coord coord): NO_(suivant) {
   this->coord = coord;
   ++total;
   ++suivant;
}

Coord Robot::get_coord() {}

bool Robot::operator==(const Robot& r) {
 return (coord == r.coord);
}

void Robot::deplacer(Coord coord) {
   this->coord = coord;
}

void Robot::deplacer(Direction direction) {
   switch (direction) {
      case Direction::HAUT   :
         coord.second += 1;
         break;
      case Direction::BAS    :
         coord.second -= 1;
         break;
      case Direction::GAUCHE :
         coord.first  -= 1;
         break;

      case Direction::DROITE :
         coord.first  += 1;
         break;
      }
}

Data Robot::get_num(const Robot& r) {
   return r.NO_;
}



