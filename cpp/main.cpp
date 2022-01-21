/*
-----------------------------------------------------------------------------------
Nom du fichier      : main.cpp
Auteur(s)           : Baume Oscar & Centeno Cédric
Date creation       : 14.01.2022
Description         : Programme qui simule une bataille entre un nombre choisi par
                      l'utilisateur de robot, dans un plateau au dimension choisi
                      par l'utilisateur.
Remarque(s)         : Il faut un minimum de 2 robots pour avoir une bataille.
Modification:       ---
                    Date   :
                    Auteur :
                    Raison :
Compilateur         : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <limits>
#include "Plateau.h"
#include "saisie.h"

using namespace std;

int main() {
   const string MSG_BIENVENUE = "Bonjour, ce programme va simuler une \'bataille\'"
                                " entre un nombre choisi de \nrobot dans un "
                                "plateau d'une dimension de votre choix. Les robots se "
                                "deplace \naleatoirement sur le plateau, lorsqu\'un "
                                "robot se deplace sur une case deja occupe\nle "
                                "robot occupant la case est tue.",
                MSG_FIN       = "Appuyez sur ENTER pour mettre fin au programme.",
                MSG_ERREUR    = "Veuillez entrer une valeur correct";

   const int    MIN_DIMENSION = 10,  MAX_DIMENSION = 1000,
                MIN_ROBOT     = 1,   MAX_ROBOT     = 10;

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
   // lance la bataille
   plateau.jouer();
   // affiche le message de fin de jeu
   cout << MSG_FIN << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
