
#ifndef __PLATEAU_OTHELLO__
#define __PLATEAU_OTHELLO__

#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include <stdbool.h>





/**
 * \brief Le type OTH_Plateau permet de représenter le plateau de jeu 
 *
 */
typedef struct {
    int largeur; /**< largeur du plateau */
    int hauteur;    /**< hauteur du plateau */
    OTH_Pion cases[largeur][hauteur]  /**< tableau dynamique taille = longeur*largeur  */
}OTH_Plateau;

/**
 * \fn  OTH_CreerPlateau(int largeur, int hauteur)
 * \brief Fonction de création d'un plateau de cases inactive
 *
 * \return OTH_Plateau
 */
OTH_Plateau OTH_CreerPlateau();



/**
 * \fn OTH_ObtenirPion()
 * \brief Fonction pour obtenir un pion d'un plateau
 * \param OTH_Position position dont on veut le pion
 * \param OTH_Plateau
 * \return OTH_Pion
 */
OTH_Pion OTH_CreerPlateau(OTH_Position position, OTH_Plateau plateau);


/**
 * \fn OTH_PoserPion()
 * \brief Fonction pour poser un pion sur un plateau
 * \param OTH_Position position dont on veut le pion
 * \param OTH_Plateau
 * \param OTH_Pion
 * \return OTH_Plateau
 */
OTH_Plateau OTH_PoserPion(OTH_Pion pion, OTH_Position position, OTH_Plateau plateau);



/**
 * \fn OTH_estVide()
 * \brief Fonction pour savoir si une case est vide
 * \param OTH_Position pa evaluer
 * \param OTH_Plateau
 * \return int (O si vide autre sinon)
 */
int OTH_estVIde(OTH_Position position, OTH_Plateau plateau);

/**
 * \fn OTH_ViderPlateau()
 * \brief Fonction pour vider le plateau
 * \param OTH_Plateau
 * \return OTH_Plateau
 */
OTH_Plateau OTH_ViderPlateau(OTH_Plateau plateau);
