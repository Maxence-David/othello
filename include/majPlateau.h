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
 * \brief Le type Direction qui représente une direction dans le plateau (H = Haut, B = Bas, D = Droite, G = Gauche)
 */

typedef enum {HG, BG, HD, BD, H, B, G, D} Directions;

/**
 * \fn majPlateau()
 * \brief Fonction qui renouvelle le plateau après chaque coup
 * \param PL_Plateau lePlateau  l'ancien plateau
 * \param C_Coup leCoup  coup qui vient d'être placé
 * \return void
 */

void majPlateau(PL_Plateau lePlateau, C_Coup leCoup);

/**
 * \fn  retournerPion()
 * \brief Fonction qui retourne un pion (conséquence du coup qui vient d'être placé)
 * \param PL_Plateau lePlateau  le plateau
 * \param PO_Position positionDuPion  position du pion qui doit être retourné
 * \return void
 */

void retournerPion(PL_Plateau lePlateau, PO_Position positionDuPion);
