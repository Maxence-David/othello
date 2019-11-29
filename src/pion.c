#include "couleur.h"
#include "pion.h"

OTH_Pion OTH_CreerPion(OTH_Couleur couleur)
{
    OTH_Pion resultat;
    resultat.couleurPion = couleur;
    resultat.etatPion = 1;
    return resultat;
}

OTH_Pion OTH_ChangerEtat(OTH_Pion pion)
{
    OTH_Pion resultat; 
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

OTH_Couleur OTH_ObtenirCouleurPion(OTH_Pion pion)
{
    return pion.couleurPion;
}

int OTH_ObtenirEtatPion(OTH_Pion pion)
{
    return pion.etatPion;
}
