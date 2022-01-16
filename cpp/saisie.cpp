/*
-----------------------------------------------------------------------------------
Nom du fichier : saisie.cpp
Auteur(s)      : Dorian Gillioz
Date creation  : 10.11.2021
Description    : Définition des fonctions de la librairie saisie
Remarque(s)    : ---
Modification   : ---
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <limits>
#include "saisie.h"

using namespace std;

Data saisie_entre(const Data& min, const Data& max, const string& message,const
string& msg_erreur){

   Data  saisie;
   bool erreur;

   do {
      cout << message << " [" << min << " - " << max << "] : ";
      cin >> saisie;
      erreur = cin.fail() || saisie < min || saisie > max;

      if (erreur){
         cout << msg_erreur << endl;
         cin.clear();
      }
      // on vide le buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while(erreur);

   return saisie;
}

bool recommencer(const string& message, const char& option_vrai, const char& option_faux) {

   char choix;

   do {
      cout << message << "[" << option_vrai << "-" << option_faux << "]";
      cin >> choix;
   } while (choix != option_vrai && choix != option_faux);

   return choix == option_vrai;
}

