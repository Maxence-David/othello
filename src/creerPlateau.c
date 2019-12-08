#include "plateau.h"
#include "couleur.h"
#include "coup.h"
#include "pion.h"

PL_Plateau PL_creerPlateau(){
  CO_Couleur blanc, noir; PL_Plateau unPlateau;
  unPlateau.hauteur = 8;
  unPlateau.largeur = 8;
  PL_poserPion(PI_creerPion(blanc), PO_defPosition(4,4), unPlateau);
  PL_poserPion(PI_creerPion(noir), PO_defPosition(4,5), unPlateau);
  PL_poserPion(PI_creerPion(blanc), PO_defPosition(5,5), unPlateau);
  PL_poserPion(PI_creerPion(noir), PO_defPosition(5,4), unPlateau);
}
