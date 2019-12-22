#include "couleur.h"
#include "plateau.h"

void OTH_obtenirCouleurGagnant(PL_Plateau plateau, int* ilYaUnGagnant, CO_Couleur* couleurGagnant)
{
    int i, j;
    int nbPionsNoirs = 0;   /**< Compteur pour le nombre de pions Noirs*/
    int nbPionsBlancs = 0;  /**< Compteur pour le nombre de pions Blancs*/


    for(i=1; i<=HAUTEUR; i++)   /**< On parcourt toutes les lignes*/
    {
        for(j=1; j<=LARGEUR; j++)   /**< On parcourt toutes les colonnes*/
        {
            if((PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == 1) && 
               (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == NOIR))
            {
                nbPionsNoirs = nbPionsNoirs+1;  /**< On incrémente nbPionsNoirs si le pion est actif et de couleur Noire*/
            }
            else
            {
                if((PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == 1) && 
                   (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),plateau)) == BLANC))
                {
                    nbPionsBlancs = nbPionsBlancs+1;    /**< On incrémente nbPionsBlancs si le pion est actif et de couleur Blanche*/
                }
            }
        }
    }
    if(nbPionsNoirs > nbPionsBlancs)
    {
        *ilYaUnGagnant = 1; /**< Si il y plus de pions noirs que de pions blans alors il y a un gagnant*/
        *couleurGagnant = NOIR; /**< Les poins noirs ont gangné*/
    }
    else
    {
        if(nbPionsBlancs > nbPionsNoirs)
        {
            *ilYaUnGagnant = 1; /**< Si il y plus de pions noirs que de pions blans alors il y a un gagnant*/       
            *couleurGagnant = BLANC;    /**< Les poins noirs ont gangné*/    
        }
        else
        {
            *ilYaUnGagnant = 0; /**< Si il y a le même nombre de pions blancs que noir, alors il n'y a pas de gagnant*/
            *couleurGagnant = NOIR; /**< On retourne une couleur par défaut*/
        }
    }
}