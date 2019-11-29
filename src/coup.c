#include "pion.h"
#include "position.h"
#include "coup.h"

OTH_Coup OTH_PlacerCoup(OTH_Pion pion, OTH_Position positionCoup);

OTH_Position OTH_Obtenir_Position_Coup(OTH_Coup Coup)
{
    return Coup.positionCoup;
}

OTH_Couleur OTH_Obtenir_Couleur_Coup(OTH_Coup Coup)
{
    return OTH_ObtenirCouleurPion(Coup.Pion);
}

int OTH_Coup_Valide(OTH_Coup Coup); /*
