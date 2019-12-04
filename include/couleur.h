
#ifndef __COULEUR__
#define __COULEUR__

/**
 * \brief Le type CO_Couleur permet de représenter la couleur 
 *
 */
typedef enum {BLANC,NOIR} CO_Couleur;



/**
 * \fn  CO_Blanc()
 * \brief Fonction d'initialisation couleur a blanc
 *
 * \return CO_Couleur
 */
CO_Couleur CO_Blanc();

/**
 * \fn  CO_Noir()
 * \brief Fonction d'initialisation de couleur a Noir
 *
 * \return CO_Couleur
 */
CO_Couleur CO_Noir();

/**
 * \fn  CO_ChangerCouleur()
 * \brief Fonction de changement de couleur 
 * \param CO_Couleur on donne la couleur actuel
 * \return CO_Couleur
 */
CO_Couleur CO_ChangerCouleur(CO_Couleur CouleurActuelle );

#endif