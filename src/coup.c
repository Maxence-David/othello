#include "pion.h"
#include "position.h"
#include "coup.h"

PO_Position C_Obtenir_Position_Coup(C_Coup Coup)
{
    return Coup.positionCoup;
}

CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup)
{
    return C_ObtenirCouleurPion(Coup.Pion);
}

int coupValide (C_Coup leCoup, Pl_Plateau lePlateau){
  
  return (OTH_estVide(C_obtenirPositionCoup(leCoup, lePlateau) && retournerAuMoinsUnPion(lePlateau,leCoup));

}
