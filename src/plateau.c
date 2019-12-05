#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include "plateau.h"

PL_Plateau OTH_CreerPlateau();

PI_Pion OTH_ObtenirPion(PO_Position position, PL_Plateau plateau);

PL_Plateau OTH_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau plateau);

int OTH_estVide(PO_Position position, PL_Plateau plateau)
{
    return PI_ObtenirEtatPion(PL_ObtenirPion(position,plateau));
}

PL_Plateau OTH_ViderPlateau(PL_Plateau plateau);