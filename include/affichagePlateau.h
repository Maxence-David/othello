#ifndef __AFFICHAGE_PLATEAU__
#define __AFFICHAGE_PLATEAU__

#include "plateau.h"
#include "position.h"

typedef void (*affichagePlateau)(PL_Plateau);
typedef PO_Position (*entrerCoup)(CO_Couleur);
typedef void (entrerCoupTournoi)(PO_Position*,int* );
/**
 * \fn  affichagePlateau()
 * \brief Fonction qui affiche le plateau dans le terminal
 * \param PL_Plateau    Le plateau à afficher
 * \return void
 */
void OTH_affichagePlateau(PL_Plateau plateau);

/**
 * \fn  OTH_entrerCoup()
 * \brief Fonction qui demande a l'utilisateur d'entrer une position 
 * \param CO_Couleur    La couleur du de l'utilisateur
 * \return PO_Position  La posision à laquelle l'utilisateur a joué
 */
PO_Position OTH_entrerCoup(CO_Couleur couleurJoueurCourant);
 

/**
 * \fn  OTH_entrerCoupTournoi()
 * \brief Fonction qui gere l'entre d'un coup pour le tournoi
 * \param[in,out]   PO_Position position la position du coup
 * \param[in,out] int booleen de validité
 */
void OTH_entrerCoupTournoi(PO_Position* position, int* booleen);

/**
 * \fn  affichageFinPartie()
 * \brief Fonction qui affiche le resultat de la partie
 * \param CO_couleur la couleur du gagnant
 * \return void
 */
void affichageFinPartie (CO_Couleur couleur);
#endif
