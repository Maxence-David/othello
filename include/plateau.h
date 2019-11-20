
#ifndef __PLATEAU_OTHELLO__
#define __PLATEAU_OTHELLO__

#include "couleur.h"
#include "position.h"
#include "coup.h"
#include <stdbool.h>





/**
 * \brief Le type OTH_Plateau permet de représenter le plateau de jeu 
 *
 */
typedef struct {
    int largeur; /**< largeur du plateau */
    int hauteur;    /**< hauteur du plateau */
    OTH_pions cases[largeur][hauteur]  /**< tableau dynamique taille = longeur*largeur  */
}OTH_Plateau;

/**
 * \fn OTH_Plateau OTH_CreerPlateau(int largeur, int hauteur)
 * \brief Fonction de création d'un plateau de cases inactive
 *
 * \return OTH_Plateau
 */
OTH_Plateau OTH_CreerPlateau();



