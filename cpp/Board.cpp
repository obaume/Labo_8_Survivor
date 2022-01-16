//
// Created by oscar on 14.01.2022.
//
#include <ostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include "Board.h"
#include "Aleatoire.h"

using namespace std;


Board::Board(Data largeur, Data hauteur, Data nombre_robot)
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

Board::~Board() {
   robots.clear();

}

bool Board::est_fini() const {
   return status == Status::FINI;
}

void Board::effectuer_tour() {
   static int tour = 1;
   cout << "tour #" << tour++ << endl;
   if (robots.size() != 1 and status == Status::EN_COURS) {
      for (size_t i = 0;i < robots.size();++i){
         Robot r1 = robots.at(i);
         cout << "r1 : " << r1.get_num()<<endl;
         //cout << "taille robots : " <<  robots.size() << endl;
         r1.deplacer(max_hauteur, max_largeur, min_hauteur, min_largeur);
         //cout << r1.get_num() << "[" <<r1.get_coord().first << "," << r1
           // .get_coord().second<< "] se deplace" << endl;
         /*for(Robot r2 : trouver_robot(r1.get_coord().first)) {
            if (r1 == r2 and r1.get_num() != r2.get_num()) {
               cout <<"r2 : " << r2.get_num()<<endl;
               cout << r1.get_num() << " tue " << r2.get_num() << endl;
               //cout << r2.get_num() << "[" << r2.get_coord().first << "," << r2
               //   .get_coord().second << "] est tue" << endl;
               vector<Robot> reste;
               for (const Robot &o: robots) {
                  if (o.get_num() != r2.get_num())
                     reste.push_back(o);
               }
               robots.clear();
               //cout << "Reste : " << reste.size() << endl;
               for (Robot &o: reste) {
                 //cout << o.get_num() << endl;
                  robots.push_back(o);
               }
            }
         }*/
      }
   } else{
      status = Status::FINI;
   }
}


vector<Robot> Board::trouver_robot(Data ligne) const {
   vector<Robot> output;
   for(const Robot& r : robots){
      if(r.get_coord().first == ligne){
         output.push_back(r);
      }
   }
   return output;
}

ostream& operator <<(ostream &os, const Board& b) {
   const string ESPACE = string(b.max_largeur,' ');
   const int LARGEUR_AFFICHAGE = (int)b.max_largeur + 2;
   const unsigned ZERO_ASCII = 48;

   os << setfill('-') << setw(LARGEUR_AFFICHAGE) << "-";
   os << endl << setfill(' ') << setw(0);
   for (Data i = 0; i < b.max_hauteur; ++i) {
      vector<Robot> ligne = b.trouver_robot(i);
      os << '|';
      if (ligne.empty()) {
         os << setw((int)b.max_largeur + 1);
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
