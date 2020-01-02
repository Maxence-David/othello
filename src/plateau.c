#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include "plateau.h"

void PL_QuatrePionsDebut(PL_Plateau* plateau){
  PL_Initialiser_Plateau(plateau);
  
  PL_PoserPion(PI_CreerPion(CO_Blanc()), PO_defPosition(4,4), plateau);
  PL_PoserPion(PI_CreerPion(CO_Noir()), PO_defPosition(4,5), plateau);
  PL_PoserPion(PI_CreerPion(CO_Blanc()), PO_defPosition(5,5), plateau);
  PL_PoserPion(PI_CreerPion(CO_Noir()), PO_defPosition(5,4), plateau);
}

/*
int PL_obtenirHauteur(PL_Plateau plateau)
{
  return plateau.hauteur;
}

int PL_obtenirLargeur(PL_Plateau plateau)
{
  return plateau.largeur;
}
*/


void PL_Initialiser_Plateau(PL_Plateau* plateau){
  int i;
  int j; 
  for (i=1; i <= HAUTEUR; i++){
    for (j=1; j <= LARGEUR; j++){
      PO_Position position = PO_defPosition(i,j);
      (*plateau)[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1].etatPion = 0;
    }
  }

}

PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau){
  
  return(plateau[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1]);
}

void PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau* plateau){
  (*plateau)[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1] = pion;

}

int PL_estVide(PO_Position position, PL_Plateau plateau)
{
  return PI_ObtenirEtatPion(PL_ObtenirPion(position,plateau));
}
/*
void PL_ViderPlateau(PL_Plateau* plateau){
  int i,j;
  
  for (i=1; i <= HAUTEUR; i++){
    for (j=1; j <= LARGEUR; j++){
      PO_Position position = PO_defPosition(i,j);
      if ((*plateau)[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1].etatPion == 1) {
	      PI_ChangerEtat(*
        
        
        plateau[i-1][j-1]); 
      }
    }
  }

}
*/



void PL_CopierPlateau(PL_Plateau* plateau,PL_Plateau plateau_a_copier){
  PO_Position position;
  int i;
  int j;
  for (i=1 ; i <= HAUTEUR ; i++){
    for(j=1 ; j <= LARGEUR ; j++){
      position = PO_defPosition(i,j);
      PI_Pion pion = PL_ObtenirPion(position, plateau_a_copier);
      if ( !PL_estVide(position,plateau_a_copier) ){
        PL_PoserPion(pion,position,plateau);
      }
      else{
        (*plateau)[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1].etatPion = 0;
      }

    }
  }
}
