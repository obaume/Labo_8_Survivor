/*
-----------------------------------------------------------------------------------
Nom du fichier : aleatoire.cpp
Auteur(s)      : Oscar Baume & Dorian Gillioz
Date creation  : 10.11.2021
Description    : Définition de la fonction de la librairie aleatoire
Remarque(s)    : Bibliothèque réutilisé du labo 05 Reflex
Modification   : ---
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <time.h>
#include "Aleatoire.h"

using namespace std;

int aleatoire(int min, int max){
   static bool premiere_fois = true;

   // Si la fonction est appelée pour la première fois
   if (premiere_fois){
      // génere un seed pour les randoms
      srand((unsigned int)time(NULL));
      premiere_fois = false;
   }
   // retourne un nombre entre min et max
   return (int(unsigned(rand()) % (unsigned)(max - min + 1) + (unsigned)min));
}
