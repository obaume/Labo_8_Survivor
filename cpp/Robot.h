/*
-----------------------------------------------------------------------------------
Nom du fichier      : Robot.h
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

#ifndef CPP_ROBOT_H
#define CPP_ROBOT_H
#include <utility>
#include "Plateau.h"
#include "preferences.h"

enum class Direction {HAUT,BAS,GAUCHE,DROITE};

class Robot {
   friend class Board;
   friend std::ostream& operator <<(std::ostream& os, const Robot& b);
public:
   Robot();
   Robot(const Robot& r);
   Robot(Coord coord);
   ~Robot();
   bool operator<(const Robot& r) const;
   bool operator==(const Robot& r);
   Robot& operator=(const Robot& r);
   void deplacer(Data max_hauteur, Data max_largeur, Data min_hauteur,
                 Data min_largeur);
   void deplacer(Coord coord);
   Data get_num() const;
   Coord get_coord() const;
private:
   const Data NO;
   static   Data total, suivant;
   Coord coord;
};

#endif //CPP_ROBOT_H
