
/*
-----------------------------------------------------------------------------------
Nom du fichier      : Plateau.cpp
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         : Définition des fonction de la classe Plateau
Remarque(s)         :
Modification:       ---
                    Date   :
                    Auteur :
                    Raison :
Compilateur         : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <ostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Plateau.h"
#include "Aleatoire.h"

using namespace std;

const chrono::duration SLEEPING_TIME = 200ms;

Plateau::Plateau(Data largeur, Data hauteur, Data nombre_robot)
   : max_hauteur(hauteur), max_largeur(largeur),
     min_hauteur(0), min_largeur(0){
   status = Status::EN_COURS;
   robots.resize(nombre_robot);
   vector<Coord> temp;
   // création des coordonnées unique pour les robots
   for(Data i = 0; i < nombre_robot; ++i){
      Coord c;
      // on tourne
      do
      {
         c = {
            aleatoire((int)min_hauteur,(int)max_hauteur-1),
            aleatoire((int)min_largeur,(int)max_largeur-1)
         };
      }
         // tant que la coordonnée c se trouve déjà dans le vecteur temp
      while(find(temp.begin(),temp.end(),c) != temp.end());
      // ajouter la coordonnée c dans le vecteur temp
      temp.push_back(c);
   }

   auto i = robots.begin();
   // pour chacune des coordonnées unique
   for(Coord& c : temp){
      // on déplace le robot se trouvant à l'itérateur i
      i->deplacer(c);
      ++i;
   }
}

Plateau::~Plateau() {
   // supprimer les robots du vecteur
   robots.clear();
}

void Plateau::jouer() {
   // fait
   do{
      this_thread::sleep_for(SLEEPING_TIME);
      // raffraichi le terminale de la console
      system("cls");
      this->effectuer_tour();
      cout << *this;
   }
   // tant que la partie est en cours
   while(!this->est_fini());
}

bool Plateau::est_fini() const {
   return status == Status::FINI;
}


void Plateau::effectuer_tour() {
   // si le status est en cours et qu'il reste + 1 robot sur le plateau
   if (robots.size() != 1 and status == Status::EN_COURS) {
      // pour chaque robots du plateau
      for (auto y = robots.begin(); y < robots.end(); ++y){
         // on le délpace
         Direction direction = Direction(aleatoire((int)Direction::HAUT,
                                                   (int)Direction::DROITE));
         if(peut_se_deplacer(y->get_coord(), direction))
            y->deplacer(direction);
         for(auto i = robots.begin(); i < robots.end(); ++i) {
            // si ce sont 2 robots différent et qu'ils ont les mêmes coord
            if (y->get_num() != i->get_num()
                and y->get_coord() == i->get_coord()){
               // on supprime le robot qui se fait marcher dessus
               robots.erase(i);
            }
         }
      }
      // Si il ne reste plus qu'un robot
      if(robots.size() == 1)
         status = Status::FINI;
   } else
      status = Status::FINI;
}

vector<Robot> Plateau::trouver_robot(Data ligne) const {
   vector<Robot> output;
   // pour tour les robots du plateau
   for(const Robot& r : robots){
      // qui sont à la ligne cherchée
      if(r.get_coord().first == ligne){
         // on les ajoutes à ce qu'on va retourner
         output.push_back(r);
      }
   }
   return output;
}

ostream& operator <<(ostream &os, const Plateau& plateau) {
   // string remplis d'espace pour la largeur du plateau
   const string   ESPACE          = string(plateau.max_largeur, ' '),
      BORDURE_PLATEAU = string(plateau.max_largeur + 2, '-');
   const unsigned ZERO_ASCII      = 48;

   os << BORDURE_PLATEAU << endl;
   vector<Robot> ligne;
   for (Data i = 0; i < plateau.max_hauteur; ++i) {
      // on cherche les robots de la ligne i
      ligne = plateau.trouver_robot(i);
      // affiche la borne de gauche
      os << '|';
      // si la ligne est vide
      if (ligne.empty()) {
         // on affiche une ligne vide
         os << ESPACE;
      }
         // sinon
      else {
         // on copie une ligne vide
         string output = ESPACE;
         // et pour chaque robot de la ligne
         for (const Robot& r: ligne) {
            // on place son numéro à la coordonnées Y du robot
            output.at(r.get_coord().second) = char(r.get_num() + ZERO_ASCII);
         }
         os << output ;
      }
      // affiche la borne de droite
      os << '|' << endl;
   }
   os << BORDURE_PLATEAU << endl << endl;

   if(plateau.status == Status::FINI){
      cout << "Notre vainqueur est le robot #" << plateau.robots.at(0).get_num() << endl;
   }

   return os;
}

bool Plateau::peut_se_deplacer(const Coord& coord, Direction direction) const{
   return
      (direction == Direction::HAUT    and coord.first   != min_hauteur)    or
      (direction == Direction::BAS     and coord.first   != max_hauteur -1) or
      (direction == Direction::GAUCHE  and coord.second  != min_largeur)    or
      (direction == Direction::DROITE  and coord.second  != max_largeur -1);

}