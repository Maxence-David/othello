#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"
#include "position.h"
#include "pion.h"
#include <stdio.h>
#include <stdlib.h>
#include "couleur.h"


void OTH_retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion){
  PI_Pion lePionModifie;
  lePionModifie = PL_ObtenirPion(positionDuPion, *lePlateau);
  lePionModifie.couleurPion = CO_ChangerCouleur(PI_ObtenirCouleurPion(lePionModifie));
  PL_PoserPion(lePionModifie, positionDuPion, lePlateau);
}


void pour_chaque_direction(PO_Position posARetourner, PL_Plateau *lePlateau, C_Coup leCoup){ 
  PI_Pion pionSuivant;
  PO_Position posCoup;
  do{
    pionSuivant = PL_ObtenirPion(posARetourner,*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
    OTH_retournerPion(lePlateau, posARetourner);
    posCoup = PO_defPosition(PO_ObtenirX(posARetourner), PO_ObtenirY(posARetourner));/*on se place sur le pion que l'on vient de retourner(on récup sa position)*/
  }
  while (C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant));/* on réitère tant que l'on est pas arrivé à un pion de même couleur*/
}

void OTH_majPlateau(PL_Plateau *lePlateau, C_Coup leCoup){

  PO_Position posCoup, posARetourner;
  posCoup = C_Obtenir_Position_Coup(leCoup);
  
  if (OTH_testModifDirection(*lePlateau, leCoup, H) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, B) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, G) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup));
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, D) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, HG) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, HD) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, BG) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, BD) != 0) {
    posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner, lePlateau, leCoup);
  }
}

