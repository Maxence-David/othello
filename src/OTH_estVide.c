#include "plateau.h"

int OTH_estVide(PO_Position position, PL_Plateau plateau)
{
    return PI_etatPion(PL_obtenirPion(position,plateau));
}