#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include "plateau.h"

PL_Plateau PL_creerPlateau(){
  CO_Couleur blanc, noir; PL_Plateau unPlateau;
  unPlateau.hauteur = 8;
  unPlateau.largeur = 8;
  PL_poserPion(PI_creerPion(blanc), PO_defPosition(4,4), unPlateau);
  PL_poserPion(PI_creerPion(noir), PO_defPosition(4,5), unPlateau);
  PL_poserPion(PI_creerPion(blanc), PO_defPosition(5,5), unPlateau);
  PL_poserPion(PI_creerPion(noir), PO_defPosition(5,4), unPlateau);
}

PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau);

int PL_obtenirHauteur(PL_Plateau plateau)
{
  return plateau.hauteur;
}

int PL_obtenirLargeur(PL_Plateau plateau)
{
  return plateau.largeur;
}

PL_Plateau PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau plateau);

int PL_estVide(PO_Position position, PL_Plateau plateau)
{
    return PI_ObtenirEtatPion(PL_ObtenirPion(position,plateau));
}

PL_Plateau PL_ViderPlateau(PL_Plateau plateau);
