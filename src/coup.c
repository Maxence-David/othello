#include "pion.h"
#include "position.h"
#include "coup.h"
#include "placerCoup.h"
#include "plateau.h"

PO_Position C_Obtenir_Position_Coup(C_Coup Coup)
{
    return Coup.positionCoup;
}

CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup)
{
    return PI_ObtenirCouleurPion(Coup.Pion);
}

int C_Coup_Valide (C_Coup leCoup, PL_Plateau lePlateau){
  
  return PL_estVide(C_Obtenir_Position_Coup(leCoup), lePlateau) && OTH_retournerAuMoinsUnPion(lePlateau,leCoup);

}
