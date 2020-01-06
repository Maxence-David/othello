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
 * \fn  CO_Couleur OTH_faireUnePartie_J_VS_J(affichagePlateau ,obtenirCoupJOUEUR )
 * \brief Fonction principale
 * \param fonction d'affichage du plateau
 * \param la fonction d'optention d'un coup humain
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_faireUnePartie_J_VS_J(affichagePlateau ,obtenirCoupJOUEUR );

/**
 * \fn  CO_Couleur OTH_faireUnePartie_J_VS_IA(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a, ObtenirCoupIA b)
 * \brief Fonction principale
 * \param fonction d'affichage du plateau
 * \param la fonction d'optention d'un coup humain et ia
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_faireUnePartie_J_VS_IA(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a, ObtenirCoupIA b);


/**
 * \fn  CO_Couleur OTH_Tournoi(entrerCoupTournoi OTH_entrerCoupTournoi, ObtenirCoupIA IA_CoupIA,CO_Couleur CouleurJoueur)
 * \brief Fonction principale
 * \param fct d'entrer coup tournoi et coupIA
 * \return CO_Couleur la couleur du joueur gagnant
 */

CO_Couleur OTH_Tournoi(entrerCoupTournoi OTH_entrerCoupTournoi, ObtenirCoupIA IA_CoupIA,CO_Couleur CouleurJoueur);


#endif
