#ifndef __AFFICHAGE_PLATEAU__
#define __AFFICHAGE_PLATEAU__

#include "plateau.h"
#include "position.h"

typedef void (*affichagePlateau)(PL_Plateau);
typedef void (*entrerCoup)(PO_Position*);
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
 * \param position
 * \return void
 */
void OTH_entrerCoup(PO_Position* position);


#endif
