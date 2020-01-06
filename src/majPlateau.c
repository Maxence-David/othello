#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"
#include "position.h"
#include "pion.h"
#include <stdio.h>
#include <stdlib.h>
#include "couleur.h"
#include <assert.h>



void OTH_retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion){
  assert(!PL_estVide(positionDuPion,*lePlateau));
  PI_Pion lePionModifie;
  lePionModifie = PL_ObtenirPion(positionDuPion, *lePlateau);

  lePionModifie.couleurPion = CO_ChangerCouleur(PI_ObtenirCouleurPion(lePionModifie));
  (*lePlateau)[PO_ObtenirX(positionDuPion)-1][PO_ObtenirY(positionDuPion)-1]=lePionModifie;
}


void MAJ_Partielle(C_Coup coup,PL_Plateau *plateau,int deplacementX,int deplacementY){
  int i,j,Xcoup,Ycoup,n;
  int nbretournelment = 0;
  int test = 1;
  int test2 =1;
  PO_Position position;
  CO_Couleur CouleurREF = PI_ObtenirCouleurPion(C_obtenirPionCoup(coup));
  Xcoup = PO_ObtenirX(C_Obtenir_Position_Coup(coup));
  Ycoup = PO_ObtenirY(C_Obtenir_Position_Coup(coup));
  i = Xcoup+deplacementX;
  j = Ycoup+deplacementY;
  while (test && (i>0) && (i<=8) && (j>0) && (j<=8)) {
  
    position = PO_defPosition(i,j);
    if (PL_estVide(position,*plateau)){
      test = 0;
    }
    else
    {
      if (PI_ObtenirCouleurPion(PL_ObtenirPion(position,*plateau)) == CouleurREF){
        test2 =0;
        test =0;
      }
      else
      {
        nbretournelment = nbretournelment +1;

      }
      i = i + deplacementX;
      j = j + deplacementY;

    }
  }
  if( !test2){

    for (n=1;n<=nbretournelment;n++){
      position = PO_defPosition(Xcoup + n*deplacementX,Ycoup +n*deplacementY);
      OTH_retournerPion(plateau,position);
    }
  }

   
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




void maj (PL_Plateau* plateau,C_Coup coup){
  
  MAJ_Partielle(coup,plateau,0,1);
  MAJ_Partielle(coup,plateau,0,-1);
  MAJ_Partielle(coup,plateau,1,0);
  MAJ_Partielle(coup,plateau,-1,0);
  MAJ_Partielle(coup,plateau,1,-1);
  MAJ_Partielle(coup,plateau,1,1);
  MAJ_Partielle(coup,plateau,-1,1);
  MAJ_Partielle(coup,plateau,-1,-1);
  PL_PoserPion(C_obtenirPionCoup(coup),C_Obtenir_Position_Coup(coup),plateau);

}





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

