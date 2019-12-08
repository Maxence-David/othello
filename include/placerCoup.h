#ifndef __PARTIE_TERMINEE__
#define __PARTIE_TERMINEE__

#include "couleur.h"
#include "plateau.h"

/**
 * \brief Le type Direction qui représente une direction dans le plateau (H = Haut, B = Bas, D = Droite, G = Gauche)
 */
typedef enum {HG,H,HD,D,BD,B,BG,G} Direction;

/**
 * \fn  OTH_placerCoup()
 * \brief Fonction qui place un coup dans le plateau
 * \param PL_Plateau plateau  Le plateau
 * \paral int partieFinie   Booléen qui permet de vérifier que la partie n'est pas finie
 * \return C_Coup  Le coup
 */
C_Coup OTH_placerCoup(PL_Plateau plateau, int partieFinie);

/**
 * \fn  OTH_retournerAuMoinsUnPion()
 * \brief Fonction qui permet de savoir si il on retourne au moins un pion lorsqu'on joue un coup
 * \param PL_Plateau plateau    Le plateau
 * \param C_Coup coup   Le coup que l'on joue 
 * \return int   Un booléen (1=Vrai si on retourne au moins un pion)
 */
int OTH_retournerAuMoinsUnPion(PL_Plateau plateau, C_Coup coup);

/**
 * \fn  OTH_testModifDirection()
 * \brief Fonction qui permet de savoir si on retourne au moins un pion avec un coup dans une direction donnée
 * \param PL_Plateau plateau    Le plateau
 * \param C_Coup coup   Le coup joué
 * \param Direction dir La direction dans laquelle on cherche les modifications
 * \return int   Un booléen (1=Vrai si il y a une modification à faire)
 */
int OTH_testModifDirection(PL_Plateau plateau, C_Coup coup, Direction dir);

#endif