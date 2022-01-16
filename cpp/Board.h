//
// Created by oscar on 14.01.2022.
//

#ifndef CPP_BOARD_H
#define CPP_BOARD_H
#include <vector>
#include <ostream>
#include "Robot.h"
#include "preferences.h"

class Robot;
enum class Status{EN_COURS, FINI};

class Board {
   friend std::ostream& operator <<(std::ostream& os, const Board& b);
public:
   Board(Data largeur, Data hauteur, Data nombre_robot);
   ~Board();
   void effectuer_tour();
   bool est_fini() const;
   std::vector<Robot> trouver_robot(Data ligne) const;

private:
   std::vector<Robot> robots;
   Status status;
   const Data  max_hauteur,
               max_largeur,
               min_hauteur,
               min_largeur;
};


#endif //CPP_BOARD_H
