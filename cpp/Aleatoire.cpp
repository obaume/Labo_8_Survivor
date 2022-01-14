/*
-----------------------------------------------------------------------------------
Nom du fichier : aleatoire.cpp
Auteur(s)      : Dorian Gillioz
Date creation  : 10.11.2021
Description    : Définition de la fonction de la librairie aleatoire
Remarque(s)    : ---
Modification   : ---
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <time.h>
#include "preferences.h"
#include "Aleatoire.h"

using namespace std;

int aleatoire(Data min, Data max){
   static bool premiere_fois = true;

   // Si la fonction est appelée pour la première fois
   if (premiere_fois){
      // génere un seed pour les randoms
      srand((unsigned int)time(NULL));
      premiere_fois = false;
   }
   // retourne un nombre entre min et max
   return rand() % (max - min + 1) + min;
}
