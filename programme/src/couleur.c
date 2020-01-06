#include "couleur.h"

CO_Couleur CO_Blanc()
{
    return BLANC;
}

CO_Couleur CO_Noir()
{
    return NOIR;
}

CO_Couleur CO_ChangerCouleur(CO_Couleur CouleurActuelle )
{
    if (CouleurActuelle == BLANC)
    {
        return NOIR;
    }
    else
    {
        return BLANC;
    }
}

int CO_estNoir(CO_Couleur UneCouleur)
{
    if (UneCouleur == NOIR)
    {
	return 1 ;
    }
    else 
    {
	return 0 ;
    }
}

int CO_estBlanc(CO_Couleur UneCouleur)
{
    if (UneCouleur == BLANC)
    {
	return 1 ;
    }
    else 
    {
	return 0 ;
    }
}

