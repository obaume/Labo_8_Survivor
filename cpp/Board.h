//
// Created by oscar on 14.01.2022.
//

#ifndef CPP_BOARD_H
#define CPP_BOARD_H
#include <vector>
#include <ostream>
#include "Robot.h"

enum class Status{EN_COURS, FINI};

class Board {
public:
   Board(Data largeur, Data hauteur, Data nombre_robot);
   ~Board();
   friend std::ostream& operator<<(std::ostream&);
   void effectuer_tour();
   void supprimer_superposer();
private:
   vector<Robot> robots;
   Status status;
};


#endif //CPP_BOARD_H
