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
#include <iostream>
#include <chrono>
#include <thread>
#include "Plateau.h"
#include "saisie.h"

using namespace std;

int main() {
   const int MIN_DIMENSION = 2,  MAX_DIMENSION = 1000,
             MIN_ROBOT = 2,      MAX_ROBOT = 9;

   Plateau b(saisie_entre(MIN_DIMENSION,MAX_DIMENSION,
                        "Largeur",
                        "Veuillez entrer une valeur correct"),
           saisie_entre(MIN_DIMENSION,MAX_DIMENSION,
                        "Hauteur",
                        "Veuillez entrer une valeur correct"),
           saisie_entre(MIN_ROBOT,MAX_ROBOT,
                        "Nombre objet",
                        "Veuillez entrer une valeur correct"));
   do{

      cout << b;
      b.effectuer_tour();

   }
   while(!b.est_fini());
   cout << endl << "MERCI";
}