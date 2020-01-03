#include "pion.h"
#include "position.h"
#include "coup.h"
#include "placerCoup.h"
#include "plateau.h"

C_Coup C_InitCoup(PO_Position position, PI_Pion pion)
{
  C_Coup leCoup;

  leCoup.positionCoup = position;
  leCoup.Pion = pion;
  return leCoup;
}

PO_Position C_Obtenir_Position_Coup(C_Coup Coup)
{
    return Coup.positionCoup;
}

PI_Pion C_obtenirPionCoup(C_Coup coup)
{
  return coup.Pion;
}

CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup)
{
    return PI_ObtenirCouleurPion(Coup.Pion);
}

int C_Coup_Valide (C_Coup leCoup, PL_Plateau lePlateau){

  return (PI_ObtenirEtatPion(C_obtenirPionCoup(leCoup)) && !OTH_retournerAuMoinsUnPion(lePlateau,leCoup));

}
