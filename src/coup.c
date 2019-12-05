#include "pion.h"
#include "position.h"
#include "coup.h"

C_Coup OTH_PlacerCoup(PI_Pion pion, PO_Position positionCoup);

PO_Position OTH_Obtenir_Position_Coup(C_Coup Coup)
{
    return Coup.positionCoup;
}

CO_Couleur OTH_Obtenir_Couleur_Coup(C_Coup Coup)
{
    return OTH_ObtenirCouleurPion(Coup.Pion);
}

int OTH_Coup_Valide(C_Coup Coup); /*a coder*/
