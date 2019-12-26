#ifndef __faireUnePartie__
#define __faireUnePartie__

#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "caractereEnEntier.h"
#include "placerCoup.h"
#include "coupIA.h"

/**
 * \fn  faireUnePartie()
 * \brief Fonction principale
 * \param fonction d'affichage du plateau
 * \param la fonction d'optention d'un coup humain
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_faireUnePartie_J_VS_J(affichagePlateau ,obtenirCoupJOUEUR );


CO_Couleur OTH_faireUnePartie_J_VS_IA(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a, ObtenirCoupIA b);


#endif
