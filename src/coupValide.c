#include "coup.h"
#include "plateau.h"

int coupValide (C_Coup leCoup, Pl_Plateau lePlateau){
  
  if (OTH_estVide(obtenirPosition(leCoup, lePlateau) && retournerAumoinsUnPion(lePlateau,leCoup)){
      return(1);
    }
    else{
      return(0);
    }
}
