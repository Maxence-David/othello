#include "couleur.h"
#include "pion.h"

PI_Pion OTH_CreerPion(CO_Couleur couleur)
{
    PI_Pion resultat;
    resultat.couleurPion = couleur;
    resultat.etatPion = 1;
    return resultat;
}

PI_Pion OTH_ChangerEtat(PI_Pion pion)
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
    return resultat;
}

CO_Couleur OTH_ObtenirCouleurPion(PI_Pion pion)
{
    return pion.couleurPion;
}

int OTH_ObtenirEtatPion(PI_Pion pion)
{
    return pion.etatPion;
}
