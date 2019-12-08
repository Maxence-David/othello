#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "position.h"
#include "pion.h"

void retournerPion(PL_Plateau *lePlateau, PO_Position positionDuPion){
  PI_Pion lePionModifie;
  lePionModifie = PL_obtenirPion(lePlateau, positionDuPion);
  lePionModifie.couleurPion = CO_changerCouleur(PI_obtenirCouleurPion(lePionModifie));
  PL_poserPion(lePionModifie, positionDuPion, lePlateau);
  return(lePionModife);
}
