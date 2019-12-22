#include "couleur.h"
#include "plateau.h"

void OTH_obtenirCouleurGagnant(PL_Plateau plateau, int* ilYaUnGagnant, CO_Couleur* couleurGagnant)
{
    int i, j;
    int nbPionsNoirs = 0;
    int nbPionsBlancs = 0;

    for(i=1; i<=HAUTEUR; i++)
    {
        for(j=1; j<=LARGEUR; j++)
        {
            if((PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == 1) && 
               (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == NOIR))
            {
                nbPionsNoirs = nbPionsNoirs+1;
            }
            else
            {
                if((PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == 1) && 
                   (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == BLANC))
                {
                    nbPionsBlancs = nbPionsBlancs+1;
                }
            }
        }
    }
    if(nbPionsNoirs > nbPionsBlancs)
    {
        *ilYaUnGagnant = 1;
        *couleurGagnant = NOIR;
    }
    else
    {
        if(nbPionsBlancs > nbPionsNoirs)
        {
            *ilYaUnGagnant = 1;
            *couleurGagnant = BLANC;
        }
        else
        {
            *ilYaUnGagnant = 0;
            *couleurGagnant = NOIR;
        }
    }
}