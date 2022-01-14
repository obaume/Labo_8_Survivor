//
// Created by oscar on 14.01.2022.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include <utility>
#include "Board.h"

enum class Direction {HAUT,BAS,GAUCHE,DROITE};

using Data  = unsigned;
using Coord = std::pair<Data,Data>;

class Robot {
public:
   Robot();
   Robot(Coord coord);
   ~Robot();
   void deplacer(Direction direction);
   void deplacer(Coord coord);
   Coord get_coord();
private:
   const    Data NO_;
   static   Data total, next;
   Coord coord;
};

#endif //CPP_ROBOT_H
