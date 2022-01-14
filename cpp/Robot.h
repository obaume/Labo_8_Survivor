//
// Created by oscar on 14.01.2022.
//

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include <utility>
#include "Board.h"

enum class Direction {HAUT,BAS,GAUCHE,DROITE};

class Robot {
   friend class Board;
public:
   Robot();
   Robot(Coord coord);
   ~Robot();
   void deplacer(Direction direction);
   void deplacer(Coord coord);
   Data get_num(const Robot& r);
   Coord get_coord();
private:
   bool operator==(const Robot& r);
   const    Data NO_;
   static   Data total, suivant;
   Coord coord;
};

#endif //CPP_ROBOT_H
