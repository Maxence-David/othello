/**
 * \file coup.h
 * \brief TAD Coup
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __COUP_OTHELLO__
#define __COUP_OTHELLO__

#include "pion.h"
#include "position.h"
#include "plateau.h"


/**
 * \struct
 * \brief Le type C_Coup permet de représenter un coup
 *
 */

typedef struct {
    PO_Position positionCoup; /**< position du coup sur le plateau*/
    PI_Pion Pion; /**< pion a placer (sa couleur)*/
}C_Coup;

/**
 * \fn  C_Coup C_InitCoup(PO_Position position, PI_Pion pion)
 * \brief Fonction qui créé un  coup 
 * \param PO_Postition postition la postition sur laquelle on place le coup
 * \param PI_Pion pion le pion à placer
 * \return C_Coup
 */
C_Coup C_InitCoup(PO_Position position, PI_Pion pion);

/**
 * \fn  C_Coup C_PlacerCoup(PI_Pion pion, PO_Position positionCoup)
 * \brief Fonction pour posser un coup sur la plateau 
 * \param PI_Pion pion, pion a placer
 * \param PO_Position positionCoup, la position ou placer le coup sur la plateau 
 * \return C_Coup
 */
C_Coup C_PlacerCoup(PI_Pion pion, PO_Position positionCoup);

/**
 * \fn  PO_Position C_Obtenir_Position_Coup(C_Coup Coup)
 * \brief Fonction pour obtenir la possition d'un coup
 * \param C_Coup coup, 
 * \return PO_Position
 */
PO_Position C_Obtenir_Position_Coup(C_Coup Coup);

/**
 * \fn  PI_Pion C_obtenirPionCoup(C_Coup coup)
 * \brief Fonction pour obtenir le pion d'un coup
 * \param C_Coup coup, 
 * \return PI_Pion
 */
PI_Pion C_obtenirPionCoup(C_Coup coup);

/**
 * \fn  CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup)
 * \brief Fonction pour obtenir la couleur d'un coup
 * \param C_Coup coup, 
 * \return CO_Couleur
 */
CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup);

/**
 * \fn  int C_Coup_Valide(C_Coup leCoup, PL_Plateau lePlateau)
 * \brief Fonction de verification d'un coup 
 * \param C_Coup coup, 
 * \return int
 */
int C_Coup_Valide(C_Coup leCoup, PL_Plateau lePlateau);

#endif
