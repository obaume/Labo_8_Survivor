/*
-----------------------------------------------------------------------------------
Nom du fichier      : Plateau.h
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         : Header de la class Plateau.
                      Définition de la class et de ces composants.
Remarque(s)         : On défini la class Robot vide car on en a besoin dans la class
                      pour pouvoir définir un std::vector<Robot>.
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
// Status que peut avoir un plateau
enum class Status{EN_COURS, FINI};


class Plateau {
   /**
    * Nom            : operator<<
    * Définition     : Opérateur de flux pour un objet de la class Plateau
    * Remarques      :
    * @param os      : Flux
    * @param plateau : Objet de la class plateau à afficher
    * @return        : On retourne le flux os
    */
   friend std::ostream& operator<<(std::ostream& os, const Plateau& plateau);
public:
   /**
    * Nom                 : Plateau
    * Définition          : Constructeur d'objet de la class Plateau
    * Remarques           : Constructeur vide n'existe pas
    * @param largeur      : Largeur du plateau
    * @param hauteur      : Hauteur du plateau
    * @param nombre_robot : Nombre de robot qui seront sur le plateau
    */
   Plateau(Data largeur, Data hauteur, Data nombre_robot);
   /**
    * Nom        : ~Plateau
    * Définition : Destructeur d'objet de la class Plateau
    * Remarques  : -
    */
   ~Plateau();
   /**
    * Nom        : effectuer_tour
    * Définition : Fonction qui effectue un "tour" de jeu.
    *              On y déplace les robots, vérifie si il y a 2 robots à la même
    *              position -> si c'est le cas "tue" le robot qui s'est fait
    *              marcher dessus.
    * Remarques  : fonction non const car on modifie le vecteur robots
    */
   void effectuer_tour();
   /**
    * Nom        : est_fini
    * Définition : Fonction qui retourne si la "partie" est fini
    * Remarques  :
    * @return    : Si le status du plateau est Status::FINI
    */
   bool est_fini() const;
   /**
    * Nom          : trouver_robot
    * Définition   : fonction qui retourne les robots se trouvant sur une ligne du
    *                plateau.
    * Remarques    :
    * @param ligne : Numéro de la ligne ou il faut chercher les robots
    * @return      : vecteur des robots de la ligne "ligne"
    */
   std::vector<Robot> trouver_robot(Data ligne) const;

private:
   // Vecteur des robots du plateau
   std::vector<Robot> robots;
   // status du plateau
   Status status;
   // Dimension du plateau
   const Data  max_hauteur,
               max_largeur,
               min_hauteur,
               min_largeur;
};


#endif //CPP_BOARD_H
