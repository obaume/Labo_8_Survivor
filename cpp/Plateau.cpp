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
#include <ostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include "Plateau.h"
#include "Aleatoire.h"

using namespace std;


Plateau::Plateau(Data largeur, Data hauteur, Data nombre_robot)
      : max_hauteur(hauteur), max_largeur(largeur),
        min_hauteur(0), min_largeur(0){
   robots.resize(nombre_robot);

   vector<Coord> temp;
   for(Data i = 0; i < nombre_robot; ++i){
      Coord c;
      do
      {
         c = {
               aleatoire((int)min_hauteur,(int)max_hauteur-1),
               aleatoire((int)min_largeur,(int)max_largeur-1)
         };
      }
      while(find(temp.begin(),temp.end(),c) != temp.end());
      temp.push_back(c);
   }

   auto i = robots.begin();
   for(Coord& c : temp){
      i->deplacer(c);
      ++i;
   }
   status = Status::EN_COURS;
}

Plateau::~Plateau() {
   robots.clear();
}

bool Plateau::est_fini() const {
   return status == Status::FINI;
}

void Plateau::effectuer_tour() {
   if (robots.size() != 1 and status == Status::EN_COURS) {
      for (auto y = robots.begin(); y < robots.end(); ++y){
         y->deplacer(max_hauteur, max_largeur, min_hauteur, min_largeur);
         for(auto i = robots.begin(); i < robots.end(); ++i) {
            if (  y->get_num() != i->get_num()
                  and y->get_coord() == i->get_coord()){
               robots.erase(i);
            }
         }
      }
      if(robots.size() == 1)
         status = Status::FINI;
   } else{
      status = Status::FINI;
   }
}


vector<Robot> Plateau::trouver_robot(Data ligne) const {
   vector<Robot> output;
   for(const Robot& r : robots){
      if(r.get_coord().first == ligne){
         output.push_back(r);
      }
   }
   return output;
}

ostream& operator <<(ostream &os, const Plateau& b) {
   const string ESPACE = string(b.max_largeur,' ');
   const int LARGEUR_AFFICHAGE = (int)b.max_largeur + 2;
   const unsigned ZERO_ASCII = 48;

   os << setfill('-') << setw(LARGEUR_AFFICHAGE) << "-";
   os << endl;
   for (Data i = 0; i < b.max_hauteur; ++i) {
      vector<Robot> ligne = b.trouver_robot(i);
      os << '|';
      if (ligne.empty()) {
         os << setfill(' ') << setw((int)b.max_largeur + 1);
      } else {
         string output = ESPACE;
         for (const Robot& r: ligne) {
            output.at(r.get_coord().second) = char(r.get_num() + ZERO_ASCII);
         }
         os << output ;
      }
      os << '|' << endl;
   }
   os << setfill('-') << setw(LARGEUR_AFFICHAGE) << "-";
   os << endl << endl;
   for (const Robot& r: b.robots) {
      Coord c = r.get_coord();
      os << r.get_num() << " : [" << c.first << "," << c.second << "]" << endl;
   }
   return os;
}
