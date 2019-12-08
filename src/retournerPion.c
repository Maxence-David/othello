#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "position.h"
#include "pion.h"

void retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion){
  PI_Pion lePionModifie;
  lePionModifie = obtenirPion(lePlateau, positionDuPion);
  lePionModifie.couleurPion = changerCouleur(obtenirCouleurPion(lePionModifie));
  poserPion(lePionModifie, positionDuPion, lePlateau);
  return(lePionModife);
}
