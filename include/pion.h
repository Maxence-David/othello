#ifndef __PION_OTHELLO__
#define __PION_OTHELLO__

#include "couleur.h"




/**
 * \brief Le type OTH_Pion permet de représenter un pion
 *
 */

typedef struct {
    OTH_Couleur couleurPion; /**< couleur du pion*/
    int etatPion; /**< etat du pion : 0 = inactif, autre =actif*/
}OTH_Pion;

/**
 * \fn  OTH_CreerPion()
 * \brief Fonction pour creer un pion

 * \return OTH_Pion
 */
OTH_Pion OTH_CreerPion();

/**
 * \fn  OTH_ChangerEtat()
 * \brief Fonction pour changer l'etat d'un pion 
 * \param OTH_Pion pion dont on change l'etat
 * \return OTH_Pion
 */
OTH_Pion OTH_ChangerEtat(OTH_Pion pion);

/**
 * \fn  OTH_ObtenirCouleurPion()
 * \brief Fonction pour obtenir la couleur d'un pion 
 * \param OTH_Pion pion dont on doit changer la couleur 
 * \return OTH_Couleur
 */
OTH_Couleur OTH_ObtenirCouleurPion(OTH_Pion pion);


/**
 * \fn  OTH_ObtenirEtatPion()
 * \brief Fonction pour obtenir l'etat d'un pion
 * \param OTH_Pion pion dont on veut l'etat
 * \return int
 */
int OTH_ObtenirEtatPion(OTH_Pion pion);