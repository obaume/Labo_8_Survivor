//
// Created by oscar on 14.01.2022.
//

#include <iostream>
#include "Robot.h"
#include "Aleatoire.h"

Data Robot::suivant  = 1;
Data Robot::total    = 0;

Robot::Robot():NO_(suivant) {
   coord.first = coord.second = 0;
   ++total;
   ++suivant;
}

Robot::Robot(Coord coord): NO_(suivant) {
   this->coord = coord;
   ++total;
   ++suivant;
}

Robot::Robot(const Robot &r):NO_(r.NO_) {
   coord = r.coord;
}

Robot::~Robot() {
   --total;
}

Coord Robot::get_coord() const{
   return coord;
}



bool Robot::operator==(const Robot& r) {
 return (coord == r.coord);
}

void Robot::deplacer(Coord coord) {
   this->coord = coord;
}

Data Robot::get_num() const {
   return NO_;
}

std::ostream &operator<<(std::ostream &os, const Robot &b) {
   os << b.coord.first << ", " << b.coord.second;
   return os;
}

void Robot::deplacer(Data max_hauteur, Data max_largeur, Data min_hauteur,
                     Data min_largeur) {

   Direction direction = Direction(aleatoire((int)Direction::HAUT, (int)
      Direction::DROITE));
   //std::cout << " se deplace #" << (int)direction << std::endl;
   switch (direction) {
      case Direction::HAUT   :
         if (coord.first != max_hauteur-1)
         coord.first += 1;
         break;
      case Direction::BAS    :
         if (coord.first != min_hauteur)
         coord.first -= 1;
         break;
      case Direction::GAUCHE :
         if (coord.second != min_largeur)
         coord.second  -= 1;
         break;
      case Direction::DROITE :
         if (coord.second != max_largeur-1)
         coord.second  += 1;
         break;
   }
}


bool Robot::operator<(const Robot& r) const{
   if(coord.first < r.coord.first)
      return true;
   else if(r.coord.first < coord.first)
      return false;
   else if(coord.first == r.coord.first)
      if(coord.second < r.coord.second){
         return true;
      }
      else{
         return false;
      }
}
