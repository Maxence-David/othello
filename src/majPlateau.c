#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"
#include "position.h"
#include "pion.h"
#include <stdio.h>
#include <stdlib.h>
#include "couleur.h"


typedef enum {HG, BG, HD, BD, H, B, G, D} Directions;

void pour_chaque_direction(PO_Position posARetourner){ 
  do{
    pionSuivant = PL_ObtenirPion(posARetourner,lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
    retournerPion(lePlateau, posARetourner);
    posCoup = PO_defPosition(PO_obtenirX(posARetourner), PO_obtenirY(posARetourner));/*on se place sur le pion que l'on vient de retourner(on récup sa position)*/
  }
  while (C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant));/* on réitère tant que l'on est pas arrivé à un pion de même couleur*/
}

void majPlateau(PL_Plateau lePlateau, C_Coup leCoup){

  PO_Position posCoup, posARetourner;
  PI_Pion pionSuivant;
  posCoup = C_Obtenir_Position_Coup(leCoup);
  
  if (testModifDirection(lePlateau, leCoup, H) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup), PO_obtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, B) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup), PO_obtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, G) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)-1, PO_obtenirY(posCoup));
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, D) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)+1, PO_obtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, HG) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)-1, PO_obtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, HD) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)+1, PO_obtenirY(posCoup)+1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, BG) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)-1, PO_obtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner);
  }

  if (testModifDirection(lePlateau, leCoup, BD) != 0) {
    posARetourner = PO_defPosition(PO_obtenirX(posCoup)+1, PO_obtenirY(posCoup)-1);
    pour_chaque_direction(posARetourner);
  }
}


void retournerPion(PL_Plateau lePlateau, PO_Position positionDuPion){
  PI_Pion lePionModifie;
  lePionModifie = PL_obtenirPion(lePlateau, positionDuPion);
  lePionModifie.couleurPion = CO_changerCouleur(PI_obtenirCouleurPion(lePionModifie));
  PL_poserPion(lePionModifie, positionDuPion, lePlateau);
  return(lePionModife);
}
