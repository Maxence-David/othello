/**
 * \file partieTerminee.h
 * \brief Fonctions permettant de savoir si une partie est terminée
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __PARTIE_TERMINEE__
#define __PARTIE_TERMINEE__

#include "couleur.h"
#include "plateau.h"


/**
 * \fn  int OTH_plateauPlein(PL_Plateau plateau)
 * \brief Fonction qui détermine si un plateau est plein
 * \param PL_Plateau plateau  Le plateau
 * \return int  Un booléen (1=Vrai si le plateau est plein)
 */
int OTH_plateauPlein(PL_Plateau plateau);

/**
 * \fn  int OTH_plusDeCoups(PL_Plateau plateau, CO_Couleur couleurJoueurCourant)
 * \brief Fonction qui permet de savoir si il y a encore des coups possibles
 * \param PL_Plateau plateau    Le plateau
 * \param CO_Couleur couleurJoueurCourant   La couleur du joueur en train de jouer
 * \return int   Un booléen (1=Vrai si il n'y a plus de coups possibles)
 */
int OTH_plusDeCoups(PL_Plateau plateau, CO_Couleur couleurJoueurCourant);

/**
 * \fn  int OTH_partieTerminee(PL_Plateau plateau, CO_Couleur couleurJoueurCourant,CO_Couleur couleurAutreJoueur)
 * \brief Fonction qui permet de savoir si la partie est terminée ou non
 * \param PL_Plateau plateau    Le plateau
 * \param CO_Couleur couleurJoueurCourant   La couleur du joueur en train de jouer
 * \return int   Un booléen (1=Vrai si la partie est treminée)
 */
int OTH_partieTerminee(PL_Plateau plateau, CO_Couleur couleurJoueurCourant,CO_Couleur couleurAutreJoueur);

#endif

