#ifndef __COUP_IA__
#define __COUP_IA__

#include "coups.h"
#include "coup.h"
#include "couleur.h"
#include "plateau.h"

typedef void (*ObtenirCoupIA)(PL_Plateau pl, CO_Couleur CouleurReference,C_Coup* coup, int* booleen);


/**
 * \fn  IA_coupIA ()
 * \brief Fonction qui donne le coup de l'IA 
 * \param CO_Couleur CouleurReference
 * \param PL_Plateau pl 
 * \return C_Coup
 */
void IA_CoupIA(PL_Plateau pl,CO_Couleur CouleurReference,C_Coup* Resultat, int* estPossible){



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






#endif
