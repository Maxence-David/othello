/**
 * \file obtenirCouleurGagnant.h
 * \brief Fonctions permettant d'obtenir la couleur du gagnant
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __OBTENIR_COULEUR_GAGNANT__
#define __OBTENIR_COULEUR_GAGNANT__

#include "couleur.h" 
#include "plateau.h"

/**
 * \fn  void OTH_obtenirCouleurGagnant(PL_Plateau plateau, int* ilYaUnGagnant, CO_Couleur* couleurGagnant)
 * \brief Fonction qui permet de savoir si il y a un gangnant, et si oui quelle est sa couleur 
 * \param PL_Plateau    Le plateau
 * \return int,CO_Couleur   Un boolén pour savoir si il y a un gagnant et sa couleur   
 */
void OTH_obtenirCouleurGagnant(PL_Plateau plateau, int* ilYaUnGagnant, CO_Couleur* couleurGagnant);

#endif

