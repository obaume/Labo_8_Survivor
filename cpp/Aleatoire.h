/*
-----------------------------------------------------------------------------------
Nom du fichier : aleatoire.cpp
Auteur(s)      : Dorian Gillioz
Date creation  : 10.11.2021
Description    : Déclaration de la fonction de la librairie aleatoire
Remarque(s)    : ---
Modification   : ---
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef CPP_ALEATOIRE_H
#define CPP_ALEATOIRE_H

#include <cstdlib>
#include "preferences.h"

// Nom           : aleatoire
// Description   : Permet de donner un nombre aléatoire compris entre deux valeurs données
// Param min     : La valeur la plus petite de l'intervalle
// Param max     : La valeur la plus grande de l'intervalle
// Retour        : le nombre aléatoire
// Exception     : n/a
int aleatoire(int min, int max);

#endif //CPP_ALEATOIRE_H
