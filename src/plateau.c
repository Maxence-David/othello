#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include "plateau.h"

OTH_Plateau OTH_CreerPlateau();

OTH_Pion OTH_ObtenirPion(OTH_Position position, OTH_Plateau plateau);

OTH_Plateau OTH_PoserPion(OTH_Pion pion, OTH_Position position, OTH_Plateau plateau);

int OTH_estVide(OTH_Position position, OTH_Plateau plateau)
{
    return OTH_ObtenirEtatPion(OTH_ObtenirPion(position,plateau));
}

OTH_Plateau OTH_ViderPlateau(OTH_Plateau plateau);