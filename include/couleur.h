
#ifndef __COULEUR__
#define __COULEUR__

/**
 * \brief Le type OTH_Couleur permet de représenter la couleur 
 *
 */
typedef enum {BLANC,NOIR} OTH_Couleur;



/**
 * \fn  OTH_Blanc()
 * \brief Fonction d'initialisation couleur a blanc
 *
 * \return OTH_Couleur
 */
OTH_Couleur OTH_Blanc();

/**
 * \fn  OTH_Noir()
 * \brief Fonction d'initialisation de couleur a Noir
 *
 * \return OTH_Couleur
 */
OTH_Couleur OTH_Noir();

/**
 * \fn  OTH_ChangerCouleur()
 * \brief Fonction de changement de couleur 
 * \param OTH_Couleur on donne la couleur actuel
 * \return OTH_Couleur
 */
OTH_Couleur OTH_ChangerCouleur(OTH_Couleur CouleurActuelle );

#endif