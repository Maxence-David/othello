#include "couleur.h"
#include "pion.h"

PI_Pion PI_CreerPion(CO_Couleur couleur)
{
    PI_Pion resultat;
    resultat.couleurPion = couleur;
    resultat.etatPion = 1;
    return resultat;
}

void* PI_ChangerEtat(PI_Pion pion)
{
    PI_Pion resultat; 
    if (pion.etatPion = 0)
    {
        resultat.etatPion = 1;
    }
    else
    {
        resultat.etatPion = 0;
    }
    pion = resultat;
}

CO_Couleur PI_ObtenirCouleurPion(PI_Pion pion)
{
    return pion.couleurPion;
}

int PI_ObtenirEtatPion(PI_Pion pion)
{
    return pion.etatPion;
}
