/*
-----------------------------------------------------------------------------------
Nom du fichier : saisie.h
Auteur(s)      : Baume Oscar & Dorian Gillioz
Date creation  : 10.11.2021
Description    : En-tête de la librairie pour les saisies utilisateurs du programme
Remarque(s)    : ---
Modification   :
                 Date        : 15.01.2022
                 Auteur      : Oscar Baume
                 Description : Utilisation de preferences.h pour Data à la place
                               de int.
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef CPP_SAISIE_H
#define CPP_SAISIE_H

#include <cstdlib>
#include <string>
#include "preferences.h"

// Nom           : saisie_entre
// Description   : Permet de saisir entre deux valeurs passées en paramètres
// Remarque(s)   : Les saisies sont vérifiées et affiche un message en cas d'erreur
// Param min     : La valeur la plus petite de l'intervalle
// Param max     : La valeur la plus grande de l'intervalle
// Param message : La valeur la plus grande de l'intervalle
// Retour        : la saisie de l'utilisateur
// Exception     : n/a
Data saisie_entre(const Data& min, const Data& max, const std::string& message,const
std::string& msg_erreur);

// Nom               : recommencer
// Description       : Permet de donner la possibilité de recommencer le jeu en fonction de la réponse donnée
// Param option_vrai : Le caractère à choisir pour redémarrer le jeu
// Param option_faux : Le caractère à choisir pour terminer le jeu
// Retour            : Si le jeu doit redémmarer ou non
// Exception         : n/a
bool recommencer(const std::string& message, const char& option_vrai,
                 const char& option_faux);

#endif //CPP_SAISIE_H
