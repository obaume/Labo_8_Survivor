/*
-----------------------------------------------------------------------------------
Nom du fichier      : <nom du fichier>.<xxx>
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

#ifndef CPP_BOARD_H
#define CPP_BOARD_H
#include "Robot.h"
#include <vector>
#include <ostream>
#include "preferences.h"

class Robot;
enum class Status{EN_COURS, FINI};

class Plateau {
   friend std::ostream& operator <<(std::ostream& os, const Plateau& b);
public:
   Plateau(Data largeur, Data hauteur, Data nombre_robot);
   ~Plateau();
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
