#ifndef __COUPS_OTHELLO__
#define __COUPS_OTHELLO__

#include "pion.h"

/**
 * \brief Le type CS_Coups permet de représenter un coup
 *
 */

typedef struct  { 
    C_Coup tabcoups[64]; /**< tableau de coup 64 max car le plateau fait 64 cases*/
    int nbcoups; /**< nombre de coups dans le tableau */
}CS_Coups;


/**
 * \fn  OTH_InitCoups()
 * \brief Fonction qui creer un tableau de coup 
 * \param 
 * \param 
 * \return OTH_Coups
 */
CS_Coups OTH_InitCoups();


/**
 * \fn  CS_EstVide ()
 * \brief Fonction qui verifie si le tableau de coups est vide 
 * \param CS_Coups coups, tableau de coups
 * \return int 
 */
 int CS_EstVide (CS_Coups coups);
