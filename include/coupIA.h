#ifndef __COUP_IA__
#define __COUP_IA__

#include "coups.h"
#include "coup.h"
#include "couleur.h"
#include "plateau.h"

typedef C_Coup (*ObtenirCoup)();
/**
 * \fn  IA_coupIA ()
 * \brief Fonction qui donne le coup de l'IA 
 * \param CO_Couleur CouleurReference
 * \param PL_Plateau pl 
 * \return C_Coup
 */
 C_Coup IA_coupIA (PL_Plateau pl, CO_Couleur CouleurReference);



/**
 * \fn  IA_scoreDUnCoup ()
 * \brief Fonction qui permet de claculer le score d'un coup en appelant alpha beta et évalué
 * \param PL_Plateau pl, plateau courant 
 * \param CO_Couleur CouleurReference 
 * \param C_Coup coup, le coup à evalué 
 * \param int profondeur, profondeur de récursion 
 * \param int Alpha
 * \param int Beta 
 * \return int 
 */
 int IA_scoreDUnCoup (C_Coup coup, PL_Plateau pl, CO_Couleur CouleurReference, int profondeur,int alpha , int beta  );

 
/**
 * \fn  IA_Alpha_Beta ()
 * \brief Fonction d'élaguage alpha beta
 * \param PL_Plateau pl, plateau courant 
 * \param CO_Couleur CouleurReference 
 * \param CO_Couleur CouleurActuel
 * \param int profondeur, profondeur de récursion 
 * \param int Alpha
 * \param int Beta 
 * \return int 
 */
 int IA_Alpha_Beta (PL_Plateau pl, CO_Couleur CouleurReference,CO_Couleur CouleurActuel, int profondeur,int alpha , int beta  );


 
/**
 * \fn  IA_Evalue ()
 * \brief Fonction d'élaguage alpha beta
 * \param PL_Plateau pl, plateau courant 
 * \param CO_Couleur CouleurReference 
 * \return int 
 */
 int IA_Evalue (PL_Plateau pl, CO_Couleur CouleurReference );


 /**
 * \fn  IA_ObtenirCoupsPossible ()
 * \brief Fonction qui donne un tableau de coups possible
 * \param PL_Plateau pl, plateau courant 
 * \param CO_Couleur CouleurReference 
 * \return CS_Coups
 */
 CS_Coups IA_ObtenirCoupsPossible (PL_Plateau pl, CO_Couleur CouleurReference );




#endif
