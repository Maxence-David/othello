#ifndef __PION_OTHELLO__
#define __PION_OTHELLO__

#include "couleur.h"




/**
 * \brief Le type PI_Pion permet de représenter un pion
 *
 */

typedef struct {
    CO_Couleur couleurPion; /**< couleur du pion*/
    int etatPion; /**< etat du pion : 0 = inactif, autre =actif*/
}PI_Pion;

/**
 * \fn  PI_CreerPion()
 * \brief Fonction pour creer un pion

 * \return PI_Pion
 */
PI_Pion PI_CreerPion(CO_Couleur couleur);

/**
 * \fn  PI_ChangerEtat()
 * \brief procedure pour changer l'etat d'un pion 
 * \param PI_Pion pion dont on change l'etat
 */
void* PI_ChangerEtat(PI_Pion pion);

/**
 * \fn  PI_ObtenirCouleurPion()
 * \brief Fonction pour obtenir la couleur d'un pion 
 * \param PI_Pion pion dont on doit changer la couleur 
 * \return CO_Couleur
 */
CO_Couleur PI_ObtenirCouleurPion(PI_Pion pion);


/**
 * \fn  PI_ObtenirEtatPion()
 * \brief Fonction pour obtenir l'etat d'un pion
 * \param PI_Pion pion dont on veut l'etat
 * \return int
 */
int PI_ObtenirEtatPion(PI_Pion pion);

#endif