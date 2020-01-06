/**
 * \file majPlateau.h
 * \brief Fonctions gérant la mise à jour du plateau
 * \author 
 * \version 1.0
 * \date 
 */

#ifndef __MAJ_Plateau__
#define __MAJ_Plateau__


#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"
#include "position.h"
#include "pion.h"
#include <stdio.h>
#include <stdlib.h>
#include "couleur.h"


/**
 * \fn void OTH_majPlateau(PL_Plateau *lePlateau, C_Coup leCoup)
 * \brief Fonction qui renouvelle le plateau après chaque coup
 * \param PL_Plateau lePlateau  l'ancien plateau
 * \param C_Coup leCoup  coup qui vient d'être placé
 * \return void
 */

void OTH_majPlateau(PL_Plateau *lePlateau, C_Coup leCoup);


/**
 * \fn  void OTH_retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion)
 * \brief Fonction qui retourne un pion (conséquence du coup qui vient d'être placé)
 * \param PL_Plateau lePlateau  le plateau
 * \param PO_Position positionDuPion  position du pion qui doit être retourné
 * \return void
 */

void OTH_retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion);


void maj (PL_Plateau* plateau,C_Coup coup);

#endif
