/**
 * \file plateau.h
 * \brief TAD Plateau
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __PLATEAU_OTHELLO__
#define __PLATEAU_OTHELLO__

#include "couleur.h"
#include "position.h"
#include "pion.h"
/*#include <stdbool.h>*/



/**
* 
* \brief hauteur plateau 
*/
#define HAUTEUR 8
/**
* 
* \brief largeur du plateau 
*/
#define LARGEUR 8

/**
 * \typedef
 * \brief Le type PL_Plateau permet de représenter le plateau de jeu 
 *
 */
typedef PI_Pion PL_Plateau[LARGEUR][HAUTEUR];  /**< tableau dynamique taille = longeur*largeur  */

/**
 * \fn  void PL_QuatrePionsDebut(PL_Plateau* plateau)
 * \brief Fonction qui pose les 4 pions au centre du plateau (configuration avant le début de la partie)
 * \param[in,out] PL_Plateau* plateau  le plateau qu'il faut configurer
 * \return void
 */
void PL_QuatrePionsDebut(PL_Plateau* plateau);

/**
 * \fn  void PL_Initialiser_Plateau(PL_Plateau* plateau)
 * \brief Fonction de création d'un plateau de cases inactive
 * \param[in,out] PL_Plateau plateau a initialiser
 * \return void
 */
void PL_Initialiser_Plateau(PL_Plateau* plateau);


/**
 * \fn PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau)
 * \brief Fonction pour obtenir un pion d'un plateau
 * \param PO_Position Position dont on veut le pion
 * \param PL_Plateau Le plateau
 * \return PI_Pion
 */
PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau);

/**
 * \fn int PL_obtenirHauteur(PL_Plateau plateau)
 * \brief Fonction pour obtenir la hauteur du plateau
 * \param PL_Plateau Le plateau
 * \return int
 */
int PL_obtenirHauteur(PL_Plateau plateau);

/**
 * \fn int PL_obtenirLargeur(PL_Plateau plateau)
 * \brief Fonction pour obtenir la largeur du plateau
 * \param PL_Plateau Le plateau
 * \return int
 */
int PL_obtenirLargeur(PL_Plateau plateau);


/**
 * \fn void PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau* plateau)
 * \brief Fonction pour poser un pion sur un plateau
 * \param[in] PI_Pion Pion que l'on veut poser
 * \param[in] PO_Position Position où on veut poser le pion
 * \param[in,out] PL_Plateau Plateau où on pose le pion
 */
void PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau* plateau);



/**
 * \fn int PL_estVide(PO_Position position, PL_Plateau plateau)
 * \brief Fonction pour savoir si une case est vide
 * \param PO_Position Position à evaluer
 * \param PL_Plateau Le plateau
 * \return int (O si vide autre sinon)
 */
int PL_estVide(PO_Position position, PL_Plateau plateau);

/**
 * \fn void PL_ViderPlateau(PL_Plateau* plateau)
 * \brief Fonction pour vider le plateau
 * \param[in,out] PL_Plateau Le plateau a vider
 * \return void
 */
void PL_ViderPlateau(PL_Plateau* plateau);

/**
 * \fn void PL_CopierPlateau(PL_Plateau* plateau,PL_Plateau plateau_a_copier)
 * \brief Fonction pour copier le plateau
 * \param[in,out] PL_Plateau plateau La copie du plateau
 * \param[in] PL_Plateau plateau_a_copier Le plateau a copier
 */
void PL_CopierPlateau(PL_Plateau* plateau,PL_Plateau plateau_a_copier);

#endif
