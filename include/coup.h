#ifndef __COUP_OTHELLO__
#define __COUP_OTHELLO__

#include "pion.h"
#include "position.h"


/**
 * \brief Le type C_Coup permet de représenter un coup
 *
 */

typedef struct {
    PO_Position positionCoup; /**< position du coup sur le plateau*/
    PI_Pion Pion; /**< pion a placer (sa couleur)*/
}C_Coup;

/**
 * \fn  OTH_InitCoup()
 * \brief Fonction qui creer un  coup 
 * \return OTH_Coup
 */
C_Coup C_InitCoup();

/**
 * \fn  C_PlacerCoup()
 * \brief Fonction pour posser un coup sur la plateau 
 * \param PI_Pion pion, pion a placer
 * \param PO_Position positionCoup, la position ou placer le coup sur la plateau 
 * \return C_Coup
 */
C_Coup C_PlacerCoup(PI_Pion pion, PO_Position positionCoup);

/**
 * \fn  C_Obtenir_Position_Coup()
 * \brief Fonction pour obtenir la possition d'un coup
 * \param C_Coup coup, 
 * \return PO_Position
 */
PO_Position C_Obtenir_Position_Coup(C_Coup Coup);

/**
 * \fn  C_Obtenir_Couleur_Coup()
 * \brief Fonction pour obtenir la couleur d'un coup
 * \param C_Coup coup, 
 * \return CO_Couleur
 */
CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup);

/**
 * \fn  C_Coup_Valide()
 * \brief Fonction de verification d'un coup 
 * \param C_Coup coup, 
 * \return int
 */
int C_Coup_Valide(C_Coup Coup);

#endif
