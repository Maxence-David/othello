/**
 * \file position.h
 * \brief TAD Position
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __POSITION_OTHELLO__
#define __POSITION_OTHELLO__


/**
 * \brief Le type PO_Position permet de représenter un pion
 *
 */

typedef struct {
    int positiony; /**< position y */
    int positionx; /**< position x*/
}PO_Position;



/**
 * \fn  PO_Position PO_Defposition(int y, int x)
 * \brief Fonction pour definir la position
 * \param int position y
 * \param int position x
 * \return PO_Position
 */
PO_Position PO_defPosition(int y, int x);

/**
 * \fn  PO_ObtenirX()
 * \brief Fonction pour obtenir la position x
 * \param PO_Position 
 * \return int
 */
int PO_ObtenirX(PO_Position position);

/**
 * \fn  PO_ObtenirY()
 * \brief Fonction pour obtenir la position y
 * \param PO_Position 
 * \return int
 */
int PO_ObtenirY(PO_Position position);

#endif
