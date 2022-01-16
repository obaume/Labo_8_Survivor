#include <iostream>
#include <chrono>
#include <thread>
#include "Board.h"
#include "saisie.h"

using namespace std;

int main() {

   Board b(saisie_entre(2,1000,
                        "Largeur",
                        "Veuillez entrer une valeur correct"),
           saisie_entre(2,1000,
                        "Hauteur",
                        "Veuillez entrer une valeur correct"),
           saisie_entre(2,10,
                        "Nombre objet",
                        "Veuillez entrer une valeur correct"));
   do{

      cout << b;
      b.effectuer_tour();

   }
   while(!b.est_fini());
   cout << endl << "MERCI";
}