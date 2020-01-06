/**
 * \file faireUnePartie.h
 * \brief Fonctions permettant de jouer une partie
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __FAIRE_UNE_PARTIE__
#define __FAIRE_UNE_PARTIE__

#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "caractereEnEntier.h"
#include "placerCoup.h"
#include "coupIA.h"

/**
 * \fn  CO_Couleur OTH_faireUnePartie_J_VS_J( )
 * \brief Fonction principale
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_faireUnePartie_J_VS_J();

/**
 * \fn  CO_Couleur OTH_faireUnePartie_J_VS_IA(CO_Couleur couleurJoueurHumain)
 * \brief Fonction principale
 * \param CO_Couleur couleurJoueurHumain
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_faireUnePartie_J_VS_IA(CO_Couleur couleurJoueurHumain);


/**
 * \fn  CO_Couleur OTH_Tournoi(entrerCoupTournoi OTH_entrerCoupTournoi, ObtenirCoupIA IA_CoupIA,CO_Couleur CouleurJoueur)
 * \brief Fonction principale
 * \param fct d'entrer coup tournoi et coupIA
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_Tournoi(CO_Couleur CouleurJoueur);


#endif
