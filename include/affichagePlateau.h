#ifndef __AFFICHAGE_PLATEAU__
#define __AFFICHAGE_PLATEAU__

#include "plateau.h"
#include "position.h"

typedef void (*affichagePlateau)(PL_Plateau);
typedef void (*entrerCoup)(PO_Position*);
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
 


void OTH_entrerCoupTournoi(PO_Position* position, int* booleen);


void affichageFinPartie (CO_Couleur couleur);
#endif
