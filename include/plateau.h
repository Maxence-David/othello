
#ifndef __PLATEAU_OTHELLO__
#define __PLATEAU_OTHELLO__

#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
/*#include <stdbool.h>*/





/**
 * \brief Le type PL_Plateau permet de représenter le plateau de jeu 
 *
 */
typedef struct {
    unsigned int largeur; /**< largeur du plateau */
    unsigned int hauteur;    /**< hauteur du plateau */
    PI_Pion *cases  /**< tableau dynamique taille = longeur*largeur  */
} PL_Plateau;

/**
 * \fn  PL_CreerPlateau(int largeur, int hauteur)
 * \brief Fonction de création d'un plateau de cases inactive
 *
 * \return PL_Plateau
 */
PL_Plateau PL_CreerPlateau();



/**
 * \fn PL_ObtenirPion()
 * \brief Fonction pour obtenir un pion d'un plateau
 * \param PO_Position position dont on veut le pion
 * \param PL_Plateau
 * \return PI_Pion
 */
PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau);


/**
 * \fn PL_PoserPion()
 * \brief Fonction pour poser un pion sur un plateau
 * \param PO_Position position dont on veut le pion
 * \param PL_Plateau
 * \param PI_Pion
 * \return PL_Plateau
 */
PL_Plateau PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau plateau);



/**
 * \fn PL_estVide()
 * \brief Fonction pour savoir si une case est vide
 * \param PO_Position pa evaluer
 * \param PL_Plateau
 * \return int (O si vide autre sinon)
 */
int PL_estVide(PO_Position position, PL_Plateau plateau);

/**
 * \fn PL_ViderPlateau()
 * \brief Fonction pour vider le plateau
 * \param PL_Plateau
 * \return PL_Plateau
 */
PL_Plateau PL_ViderPlateau(PL_Plateau plateau);

#endif