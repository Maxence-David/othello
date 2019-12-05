#include "couleur.h"
#include "position.h"
#include "coup.h"
#include "pion.h"
#include "plateau.h"

PL_Plateau PL_CreerPlateau();

PI_Pion PL_ObtenirPion(PO_Position position, PL_Plateau plateau);

PL_Plateau PL_PoserPion(PI_Pion pion, PO_Position position, PL_Plateau plateau);

int PL_estVide(PO_Position position, PL_Plateau plateau)
{
    return PI_ObtenirEtatPion(PL_ObtenirPion(position,plateau));
}

PL_Plateau PL_ViderPlateau(PL_Plateau plateau);