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

/*
void pour_chaque_direction(PO_Position posARetourner, PL_Plateau *lePlateau, C_Coup leCoup){ 
  PI_Pion pionSuivant;
  do{
    pionSuivant = PL_ObtenirPion(posARetourner,*lePlateau); 
    OTH_retournerPion(lePlateau, posARetourner);
    posARetourner = PO_defPosition(PO_ObtenirX(posARetourner), PO_ObtenirY(posARetourner));
  } 
  while (C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant));
}*/

void OTH_majPlateau(PL_Plateau *lePlateau, C_Coup leCoup){

  PI_Pion pionSuivant;
  PO_Position posCoup, posARetourner;
  posCoup = C_Obtenir_Position_Coup(leCoup); 
  PL_PoserPion(C_obtenirPionCoup(leCoup),C_Obtenir_Position_Coup(leCoup),lePlateau);

  if (OTH_testModifDirection(*lePlateau, leCoup, H) != 0) {
    pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)-1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)-2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if (PO_ObtenirX(posCoup)<1 || (PO_ObtenirY(posCoup)-2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
    /* on réitère tant que l'on est pas arrivé à un pion de même couleur*/
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, B) != 0) {
pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)+1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup), PO_ObtenirY(posCoup)+2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if (PO_ObtenirX(posCoup)<1 || (PO_ObtenirY(posCoup)+2)>8){
       if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, G) != 0) {
pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup));
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)-2, PO_ObtenirY(posCoup)),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)-2)<1 || (PO_ObtenirY(posCoup))>8){
       if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, D) != 0) {
    pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup));
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)+2, PO_ObtenirY(posCoup)),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)+2)<1 || (PO_ObtenirY(posCoup)+2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, HG) != 0) {
pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup)-1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)-2, PO_ObtenirY(posCoup)-2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)-2)<1 || (PO_ObtenirY(posCoup)-2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, HD) != 0) {
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup)-1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)+2, PO_ObtenirY(posCoup)-2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)+2)<1 || (PO_ObtenirY(posCoup)-2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, BG) != 0) {
pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)-1, PO_ObtenirY(posCoup)+1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)-2, PO_ObtenirY(posCoup)+2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)-2)<1 || (PO_ObtenirY(posCoup)+2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }

  if (OTH_testModifDirection(*lePlateau, leCoup, BD) != 0) {
pionSuivant.couleurPion = CO_ChangerCouleur(C_Obtenir_Couleur_Coup(leCoup));
    while(C_Obtenir_Couleur_Coup(leCoup) != PI_ObtenirCouleurPion(pionSuivant)){
      posARetourner = PO_defPosition(PO_ObtenirX(posCoup)+1, PO_ObtenirY(posCoup)+1);
      pionSuivant = PL_ObtenirPion(PO_defPosition(PO_ObtenirX(posCoup)+2, PO_ObtenirY(posCoup)+2),*lePlateau); /* on garde en mémoire le pion que l'on va retourner, utile pour la condition du répéter tant que */
      if ((PO_ObtenirX(posCoup)+2)<1 || (PO_ObtenirY(posCoup)+2)>8){
        if (C_Obtenir_Couleur_Coup(leCoup) == CO_Noir())
          pionSuivant.couleurPion = CO_Noir();
        else{
          pionSuivant.couleurPion = CO_Blanc();
        }
      }
      else{
        OTH_retournerPion(lePlateau, posARetourner);
        posCoup = posARetourner;
      }
    }
  }
}

