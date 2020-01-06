/**
 * \file couleur.h
 * \brief TAD Couleur
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __COULEUR__
#define __COULEUR__

/**
 * 
 * \brief Le type CO_Couleur permet de représenter la couleur 
 *
 */
typedef enum {BLANC,NOIR} CO_Couleur;



/**
 * \fn  CO_Couleur CO_Blanc()
 * \brief Fonction d'initialisation couleur a blanc
 * \param
 * \return CO_Couleur
 */
CO_Couleur CO_Blanc();

/**
 * \fn  CO_Couleur CO_Noir()
 * \brief Fonction d'initialisation de couleur a Noir
 * \param
 * \return CO_Couleur
 */
CO_Couleur CO_Noir();

/**
 * \fn  CO_Couleur CO_ChangerCouleur(CO_Couleur CouleurActuelle );
 * \brief Fonction de changement de couleur 
 * \param CO_Couleur on donne la couleur actuel
 * \return CO_Couleur
 */
CO_Couleur CO_ChangerCouleur(CO_Couleur CouleurActuelle );

/**
 * \fn  int CO_estNoir(CO_Couleur UneCouleur);
 * \brief Fonction qui permet de savoir si la couleur est Noire
 * \param CO_Couleur on donne la couleur à tester
 * \return int 1=vrai si la couleur est bien noire
 */
int CO_estNoir(CO_Couleur UneCouleur);

/**
 * \fn  int CO_estBlanc(CO_Couleur UneCouleur);
 * \brief Fonction qui permet de savoir si la couleur est Blanche
 * \param CO_Couleur on donne la couleur à tester
 * \return int 1=vrai si la couleur est bien blanche
 */
int CO_estBlanc(CO_Couleur UneCouleur);

#endif

