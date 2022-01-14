//
// Created by oscar on 14.01.2022.
//
#include <ostream>
#include <utility>
#include "Board.h"
#include "preferences.h"
#include "Aleatoire.h"

using namespace std;


Board::Board(Data largeur, Data hauteur, Data nombre_robot)
      :  MAX_HAUTEUR(hauteur),MAX_LARGEUR(largeur),
         MIN_HAUTEUR(0),MIN_LARGEUR(0){
   robots.resize(nombre_robot);
   vector<Coord> temp;
   for(Data i = 0; i < nombre_robot; ++i){
      Coord c;
      do
      {
         c = {
               aleatoire(MIN_HAUTEUR,MAX_HAUTEUR),
               aleatoire(MIN_LARGEUR,MAX_LARGEUR)
         };
      }
      while(find(temp.begin(),temp.end(),c) != temp.end());
      temp.push_back(c);
   }

   auto i = robots.begin();
   for(Coord c : temp){
      i = new Robot(c);
      ++i;
   }
}

Board::~Board() {}

void Board::effectuer_tour() {}

void Board::supprimer_superposer() {}

std::ostream &operator<<(ostream &os, const Board& b) {

}

