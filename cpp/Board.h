//
// Created by oscar on 14.01.2022.
//

#ifndef CPP_BOARD_H
#define CPP_BOARD_H
#include <vector>
#include <ostream>
#include "Robot.h"
#include "preferences.h"

enum class Status{EN_COURS, FINI};

class Board {
public:
   Board(Data largeur, Data hauteur, Data nombre_robot);
   ~Board();
   friend std::ostream& operator<<(std::ostream& os,const Board& b);
   void effectuer_tour();
   void supprimer_superposer();
private:
   vector<Robot> robots;
   Status status;
   const Data  MIN_HAUTEUR,
               MAX_HAUTEUR,
               MIN_LARGEUR,
               MAX_LARGEUR;
};


#endif //CPP_BOARD_H
