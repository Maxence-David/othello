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
  PO_Position position = leCoup.positionCoup;
  return ( (lePlateau[PO_ObtenirX(position)-1][PO_ObtenirY(position)-1].etatPion == 0) && OTH_retournerAuMoinsUnPion(lePlateau,leCoup));

}

int C_Egale(C_Coup coup1, C_Coup coup2) {
	return (PI_egal(coup1.Pion,coup2.Pion) && PO_egal(coup1.positionCoup,coup2.positionCoup));
}
