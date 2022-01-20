/*
-----------------------------------------------------------------------------------
Nom du fichier      : Robot.cpp
Nom du laboratoire  :
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         :
Remarque(s)         :
Modification:       ---
                    Date   :
                    Auteur :
                    Raison :
Compilateur         : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include "Robot.h"
#include "Aleatoire.h"

Data Robot::suivant  = 0;
Data Robot::total    = 0;

Robot::Robot(): NO(suivant) {
   coord.first = coord.second = 0;
   ++total;
   ++suivant;
}

Robot::Robot(Coord coord): NO(suivant) {
   this->coord = coord;
   ++total;
   ++suivant;
}

Robot::Robot(const Robot &r): NO(r.NO) {
   coord = r.coord;
}

Robot::~Robot() {
   --total;
}

Coord Robot::get_coord() const{
   return coord;
}

Robot &Robot::operator=(const Robot &r) {
   (Data&) this->NO = r.NO;
   this->coord = r.coord;
   return *this;
}

bool Robot::operator==(const Robot& r) {
 return (coord == r.coord and NO != r.NO);
}

void Robot::deplacer(Coord coord) {
   this->coord = coord;
}

Data Robot::get_num() const {
   return NO;
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
