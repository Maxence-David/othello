/**
 * \file pion.h
 * \brief TAD Pion
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __PION_OTHELLO__
#define __PION_OTHELLO__

#include "couleur.h"




/**
 * 
 * \brief Le type PI_Pion permet de représenter un pion
 *
 */

typedef struct {
    CO_Couleur couleurPion; /**< couleur du pion*/
    int etatPion; /**< etat du pion : 0 = inactif, autre =actif*/
}PI_Pion;

/**
 * \fn  PI_Pion PI_CreerPion(CO_Couleur couleur)
 * \brief Fonction pour creer un pion
 * \param CO_Couleur La couleur du pion
 * \return PI_Pion
 */
PI_Pion PI_CreerPion(CO_Couleur couleur);

/**
 * \fn  void PI_ChangerEtat(PI_Pion pion)
 * \brief procedure pour changer l'etat d'un pion 
 * \param PI_Pion pion dont on change l'etat
 * \return void
 */
void PI_ChangerEtat(PI_Pion pion);

/**
 * \fn  CO_Couleur PI_ObtenirCouleurPion(PI_Pion pion)
 * \brief Fonction pour obtenir la couleur d'un pion 
 * \param PI_Pion pion dont on doit changer la couleur 
 * \return CO_Couleur
 */
CO_Couleur PI_ObtenirCouleurPion(PI_Pion pion);


/**
 * \fn  int PI_ObtenirEtatPion(PI_Pion pion)
 * \brief Fonction pour obtenir l'etat d'un pion
 * \param PI_Pion pion dont on veut l'etat
 * \return int
 */
int PI_ObtenirEtatPion(PI_Pion pion);

/**
 * \fn  int PI_Egal(PI_Pion pion1, PI_Pion pion2)
 * \brief Fonction pour verifier l'egalité de deux pions
 * \param PI_Pion Le premier pion
 * \param PI_Pion Le second pion
 * \return int Un booléen
 */
int PI_Egal(PI_Pion pion1, PI_Pion pion2);

#endif

