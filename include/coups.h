#ifndef __COUPS_OTHELLO__
#define __COUPS_OTHELLO__

#include "pion.h"
#include "coup.h"

/**
 * \def MAX
 * \brief MAX = 64 coups possibles pour les 64 cases du plateau
 */

#define MAX 64

/**
 * \brief Le type CS_Coups permet de représenter un coup
 *
 */

typedef struct  { 
    C_Coup tabcoups[MAX]; /**< tableau de coup 64 max car le plateau fait 64 cases*/
    int nbcoups; /**< nombre de coups dans le tableau */
}CS_Coups;


/**
 * \fn  OTH_InitCoups()
 * \brief Fonction qui creer un tableau de coup 
 * \param 
 * \param 
 * \return OTH_Coups
 */
CS_Coups CS_InitCoups();


/**
 * \fn  CS_EstVide ()
 * \brief Fonction qui verifie si le tableau de coups est vide 
 * \param CS_Coups coups, tableau de coups
 * \return int 
 */
 int CS_EstVide (CS_Coups coups);



/**
 * \fn  CS_AjouterCoup ()
 * \brief Fonction qui ajoute un coup au tableau de coups
 * \param CS_Coups coups, tableau de coups
 * \param C_Coup, coup a ajouter 
 * \return int 
 */
 void CS_AjouterCoup (CS_Coups* coups,C_Coup coup);



/**
 * \fn  CS_IemeCoup ()
 * \brief Fonction renvoi le ieme coup
 * \param CS_Coups coups, tableau de coups
 * \param int i
 * \return C_Coup 
 */
 C_Coup CS_IemeCoup (CS_Coups coups,int i);

 /**
 * \fn  CS_NbCoups ()
 * \brief Fonction qui renvoi le nombre de coups du tableau 
 * \param CS_Coups coups, tableau de coups
 * \return int 
 */
 int CS_NbCoups (CS_Coups coups );

/**
 * \fn  CS_EstPresent ()
 * \brief Fonction qui test si un coup est prensent dans le tableau
 * \param CS_Coups coups, tableau de coups
 * \param C_Coup le coup à chercher
 * \return int 
 */
 int CS_EstPresent (CS_Coups coups,C_Coup coup);




 /**
 * \fn  CS_SupprimerCoup ()
 * \brief procedure qui supprime un coup du tableau
 * \param CS_Coups coups, tableau de coups
 * \param i possition du coup a suuprimer 
 * \return void
 */
 void CS_SupprimerCoup (CS_Coups* coups,int i);



 /**
 * \fn   CS_ObtenirCoupsPossible()
 * \brief procedure qui donne un tableau de coup jouable
 * \param PL_Plateau, la grille de jeu
 * \param CO_Couleur CouleurReference la couleur de de la liste de coup que l'on veux
 * \return CS_Coups
 */
CS_Coups CS_ObtenirCoupsPossible (PL_Plateau pl, CO_Couleur CouleurReference );


#endif

