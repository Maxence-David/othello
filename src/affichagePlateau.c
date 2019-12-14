/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

#include "plateau.h"

void OTH_affichagePlateau(PL_Plateau plateau)
{
    int x,y;

    for (y = 1; y <= PL_obtenirHauteur(plateau); y++)    /*On parcourt les lignes*/
    {
        for (x = 1; x <= PL_obtenirLargeur(plateau); x++)    /*Et les colonnes*/
        {
            if (PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == 0)   /*On vérifie l'état du pion pour chaque position*/
            {
                printf("-");    /*Le caractère '-' est utilisé pour une case vide*/
            }
            else
            {
                if (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == NOIR) /*On vérifie la couleur du pion pour chaque position*/
                {
                    printf("o");    /*Le caractère 'o' est utilisé pour les pions NOIRs*/
                }
                else
                {
                    printf("+");    /*Le caractère '+' est utilisé pour les pions NOIRs*/
                }
            }
        }
        printf("\n");   /*On saute une ligne à la fin de chaque ligne parcourue*/
    }
}