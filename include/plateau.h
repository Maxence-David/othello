
#ifndef __PLATEAU_OTHELLO__
#define __PLATEAU_OTHELLO__

#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
/*#include <stdbool.h>*/



/**
* \def HAUTEUR 8
* \brief hauteur plateau 
*/
#define HAUTEUR 8
/**
* \def LARGEUR 8
* \brief largeur du plateau 
*/
#define LARGEUR 8

/**
 * \brief Le type PL_Plateau permet de représenter le plateau de jeu 
 *
 */
typedef PI_Pion PL_Plateau[LARGEUR][HAUTEUR];  /**< tableau dynamique taille = longeur*largeur  */

/**
 * \fn  PL_QuatrePionsDebut()
 * \brief Fonction qui pose les 4 pions au centre du plateau (configuration avant le début de la partie)
 * \param[in,out] PL_Plateau* plateau  le plateau qu'il faut configurer
 */
void PL_QuatrePionsDebut(PL_Plateau* plateau);

/**
 * \fn  PL_InitialiserPlateau()
 * \brief Fonction de création d'un plateau de cases inactive
 * \param[in,out] PL_Plateau plateau a initialiser 
 */
void PL_Initialiser_Plateau(PL_Plateau* plateau);


/**
 * \fn PL_ObtenirPion()
 * \brief Fonction pour obtenir un pion d'un plateau
 * \param PO_Position position dont on veut le pion
 * \param PL_Plateau
 * \return PI_Pion
 */
PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau);

/**
 * \fn PL_obtenirHauteur()
 * \brief Fonction pour obtenir la hauteur du plateau
 * \param PL_Plateau
 * \return int
 */
int PL_obtenirHauteur(PL_Plateau plateau);

/**
 * \fn PL_obtenirLargeur()
 * \brief Fonction pour obtenir la largeur du plateau
 * \param PL_Plateau
 * \return int
 */
int PL_obtenirLargeur(PL_Plateau plateau);


/**
 * \fn PL_PoserPion()
 * \brief Fonction pour poser un pion sur un plateau
 * \param[in] PO_Position position dont on veut le pion
 * \param[in,out] PL_Plateau, plateau ou on ajoute le pion
 * \param[in] PI_Pion
 */
void PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau* plateau);



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
 * \param[in,out] PL_Plateau a vider
 */
void PL_ViderPlateau(PL_Plateau* plateau);

/**
 * \fn PL_CopierPlateau()
 * \brief Fonction pour copier le plateau
 * \param[in,out] PL_Plateau plateau, la copie du plateau
 * \param[in] PL_Plateau plateau_a_copier, le plateau a copier
 */
void PL_CopierPlateau(PL_Plateau* plateau,PL_Plateau plateau_a_copier);

#endif
