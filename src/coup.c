#include "pion.h"
#include "position.h"
#include "coup.h"

C_Coup C_PlacerCoup(PI_Pion pion, PO_Position positionCoup);

PO_Position C_Obtenir_Position_Coup(C_Coup Coup)
{
    return Coup.positionCoup;
}

CO_Couleur C_Obtenir_Couleur_Coup(C_Coup Coup)
{
    return C_ObtenirCouleurPion(Coup.Pion);
}

int C_Coup_Valide(C_Coup Coup); /*a coder*/
