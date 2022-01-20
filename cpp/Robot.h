/*
-----------------------------------------------------------------------------------
Nom du fichier      : Robot.h
Nom du laboratoire  :
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         : En-tête de la class Robot.
                      Définition de la class et de ces composants
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

// directions utilisées pour déplacer un robot
enum class Direction {HAUT,BAS,GAUCHE,DROITE};

class Robot {
   /**
    * Nom                : operator<<
    * Définition         : Opérateur de flux pour un objet de la class Robot
    * Remarques          :
    * @param os          : Flux
    * @param robot       : Objet de la class Robot à afficher
    * @return            : On retourne le flux os
    */
   friend std::ostream& operator <<(std::ostream& os, const Robot& robot);
public:
   /**
    * Nom                : Robot
    * Définition         : Constructeur vide d'objet de la class Robot
    * Remarques          :
    */
   Robot();
   /**
    * Nom                : Robot
    * Définition         : Constructeur d'objet par copie de la class Robot
    * Remarques          :
    * @param robot       : Robot à copier
    */
   Robot(const Robot& robot);
   /**
    * Nom                : Robot
    * Définition         : Constructeur d'objet de la class Robot
    * Remarques          :
    * @param coord       : Coordonnées du Robot sous forme de pair
    */
   Robot(Coord coord);
   /**
    * Nom                : ~Robot
    * Définition         : Destructeur d'objet de la class Robot
    * Remarques          :
    */
   ~Robot();
   /**
    * Nom                : operator<
    * Définition         : Opérateur de comparaison "plus petit que" de la class
    *                      Robot
    * Remarques          :
    * @param robot       : Objet robot que l'on souhaite comparer
    * @return            : Si le robot courant est plus petit que le robot en
    *                      paramétre
    */
   bool operator<(const Robot& robot) const;
   /**
    * Nom                : operator==
    * Définition         : Opérateur de comparaison "est égal" de la class Robot
    * Remarques          :
    * @param robot       : Robot que l'on souhaite comparer
    * @return            : Si le robot courant est égal au robot en paramétre
    */
   bool operator==(const Robot& robot) const;
   /**
    * Nom                : operator=
    * Définition         : Opérateur d'affectation de la class Robot
    * Remarques          :
    * @param robot       : Robot que l'on souhaite comparer
    * @return            : Le robot courant modifié
    */
   Robot& operator=(const Robot& robot);
   /**
    * Nom                : deplacer
    * Définition         : Fonction qui change de manière aléatoire une coordonnée du
    *                      robot courant en prenant en compte les dimentions du
    *                      plateau
    * Remarques          :
    * @param max_hauteur : Bord du haut du plateau
    * @param max_largeur : Bord de droite du plateau
    * @param min_hauteur : Bord du bas du plateau
    * @param min_largeur : Bord de gauche du plateau
    */
   void deplacer(Data max_hauteur, Data max_largeur, Data min_hauteur,
                 Data min_largeur);
   /**
    * Nom                : deplacer
    * Définition         : Fonction qui change les coordonnées du robot courant
    *                      par la pair entree en paramétre
    * Remarques          :
    * @param coord       : Coordonnées que l'on attribue a notre robot courant
    */
   void deplacer(Coord coord);
   /**
    * Nom                : get_num()
    * Définition         : Fonction publique permettant d'obtenir la valeur de la
    *                      donnée NO d'un Robot
    * Remarques          : Utilisé pour l'opérateur de flux de Plateau
    */
   Data get_num() const;
   /**
    * Nom                : get_coord()
    * Définition         : Fonction publique permettant d'obtenir la valeur de la
    *                      donnée coord d'un Robot
    * Remarques          :
    */
   Coord get_coord() const;
private:
   // Numéro unique de l'objet Robot
   const  Data NO;
   // Nombre total de robot existant, numero de série du robot suivant
   static Data suivant;
   // Coordonnées du Robot
   Coord coord;
};

#endif //CPP_ROBOT_H