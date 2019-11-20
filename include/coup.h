#ifndef __COUP_OTHELLO__
#define __COUP_OTHELLO__

#include "pion.h"
#include "position"


/**
 * \brief Le type OTH_Coup permet de représenter un coup
 *
 */

typedef struct {
    OTH_Position positionCoup; /**< position du coup sur le plateau*/
    OTH_Pion Pion; /**< pion a placer (sa couleur)*/
}OTH_Coup;

/**
 * \fn  OTH_PlacerCoup()
 * \brief Fonction pour posser un coup sur la plateau 
 * \param OTH_Pion pion, pion a placer
 * \param OTH_Position positionCoup, la position ou placer le coup sur la plateau 
 * \return OTH_Coup
 */
OTH_Coup OTH_PlacerCoup(OTH_Pion pion, OTH_Position positionCoup);

/**
 * \fn  OTH_Obtenir_Position_Coup()
 * \brief Fonction pour obtenir la possition d'un coup
 * \param OTH_Coup coup, 
 * \return OTH_Position
 */
OTH_Position OTH_Obtenir_Position_Coup(OTH_Coup Coup);

/**
 * \fn  OTH_Obtenir_Couleur_Coup()
 * \brief Fonction pour obtenir la couleur d'un coup
 * \param OTH_Coup coup, 
 * \return OTH_Couleur
 */
OTH_Couleur OTH_Obtenir_Couleur_Coup(OTH_Coup Coup);

/**
 * \fn  OTH_Coup_Valide()
 * \brief Fonction de verification d'un coup 
 * \param OTH_Coup coup, 
 * \return int
 */
int OTH_Coup_Valide(OTH_Coup Coup);