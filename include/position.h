#ifndef __POSITION_OTHELLO__
#define __POSITION_OTHELLO__


/**
 * \brief Le type OTH_Position permet de représenter un pion
 *
 */

typedef struct {
    char positiony; /**< position y */
    int positionx; /**< position x*/
}OTH_Position;



/**
 * \fn  OTH_Defposition()
 * \brief Fonction pour definir la position
 * \param char position y
 * \param int position x
 * \return OTH_Position
 */
OTH_Position OTH_Defposition(char y, int x);

/**
 * \fn  OTH_ObtenirX()
 * \brief Fonction pour obtenir la position x
 * \param OTH_Position 
 * \return int
 */
int OTH_ObtenirX(OTH_Position position);

/**
 * \fn  OTH_ObtenirY()
 * \brief Fonction pour obtenir la position y
 * \param OTH_Position 
 * \return char
 */
char OTH_ObtenirX(OTH_Position position);
