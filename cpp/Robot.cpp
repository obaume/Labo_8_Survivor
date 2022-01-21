/*
-----------------------------------------------------------------------------------
Nom du fichier      : Robot.cpp
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         : Définition des fonction de la classe Robot
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

Data Robot::suivant = 0;

using namespace std;

std::ostream &operator<<(std::ostream &os, const Robot& robot) {
   return os << robot.coord.first << ", " << robot.coord.second;
}

Robot::Robot(): NO(suivant) {
   // on décide qu'un robot a par défaut les coordonnées 0 0
   coord.first = coord.second = 0;
   ++suivant;
}

Robot::Robot(const Robot& robot): NO(robot.NO) {
   // suivant n'est pas incrementé car ce constructeur est utilisé pour décaler
   // des robots dans un vecteur
   coord = robot.coord;
}


Robot::Robot(Coord coord): NO(suivant) {
   this->coord = coord;
   ++suivant;
}

Robot::~Robot() {
}

bool Robot::operator<(const Robot& robot) const{
   // comparer la première coordonnée des 2 robots
   if(coord.first < robot.coord.first) {
      return true;
   }
   else if(robot.coord.first < coord.first) {
      return false;
   }
   // si elles sont égales, comparer la deuxieme coordonnée
   else if(coord.first == robot.coord.first) {
      if (coord.second < robot.coord.second) {
         return true;
      } else {
         return false;
      }
   }
   // ce cas ne devrait jamais se produire, mais ajouté par securité
   return false;
}

bool Robot::operator==(const Robot& robot) const{
   // vérifie si deux robots différents ont les mêmes coordonnées
   return (coord == robot.coord and NO != robot.NO);
}

Robot &Robot::operator=(const Robot& robot) {
   // cast en reference car NO est une constante
   (Data&) this->NO = robot.NO;
   this->coord = robot.coord;
   return *this;
}

void Robot::deplacer(Direction direction) {
   switch (direction) {
      case Direction::HAUT   :
         coord.first -= 1;
         break;
      case Direction::BAS    :
         coord.first += 1;
         break;
      case Direction::GAUCHE :
         coord.second  -= 1;
         break;
      case Direction::DROITE :
         coord.second  += 1;
         break;
   }
}

void Robot::deplacer(Coord coord) {
   this->coord = coord;
}

Data Robot::get_num() const {
   return NO;
}

Coord Robot::get_coord() const{
   return coord;
}








