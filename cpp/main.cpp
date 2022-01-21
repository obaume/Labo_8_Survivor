/*
-----------------------------------------------------------------------------------
Nom du fichier      : main.cpp
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
   const string            MSG_BIENVENUE = "Bonjour, ce programme va simuler une \'bataille\'"
                                           " entre un nombre choisi de \nrobot dans un "
                                           "plateau d'une dimension de votre choix. Les robots se "
                                           "deplace \naleatoirement sur le plateau, lorsqu\'un "
                                           "robot se deplace sur une case deja occupe\nle "
                                           "robot occupant la case est tue.",
                           MSG_FIN       = "Appuyez sur ENTER pour mettre fin au programme.",
                           MSG_ERREUR    = "Veuillez entrer une valeur correct";

   const int               MIN_DIMENSION = 10,  MAX_DIMENSION = 1000,
                           MIN_ROBOT     = 1,   MAX_ROBOT     = 10;
   const chrono::duration  SLEEPING_TIME = 200ms;

   cout << MSG_BIENVENUE << endl << endl;
   // création du tableau comprenant la saisie contrôlée des valeurs
   Plateau plateau(saisie_entre(MIN_DIMENSION, MAX_DIMENSION,
                                "Largeur",
                                MSG_ERREUR),
                   saisie_entre(MIN_DIMENSION,MAX_DIMENSION,
                                "Hauteur",
                                MSG_ERREUR),
                   saisie_entre(MIN_ROBOT,MAX_ROBOT,
                                "Nombre objet",
                                MSG_ERREUR));
   // affichage du plateau avant que le jeu commence
   cout << plateau;
   do{
      this_thread::sleep_for(SLEEPING_TIME);
      system("cls");
      plateau.effectuer_tour();
      cout << plateau;
   }
   while(!plateau.est_fini());
   cout << MSG_FIN << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}