#include "plateau.h"

int OTH_estVide(OTH_Position position, OTH_Plateau plateau)
{
    return OTH_etatPion(OTH_obtenirPion(position,plateau));
}