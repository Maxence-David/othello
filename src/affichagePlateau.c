/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

#include "plateau.h"

void OTH_affichagePlateau(PL_Plateau plateau)
{
    int x = 1;
    int y;

    for (y = 1; y <= 8; y++)
    {
        for (x = 1; x <= 8; x++)
        {
            if (PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == 0)
            {
                printf("-");
            }
            else
            {
                if (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == NOIR)
                {
                    printf("o");
                }
                else
                {
                    printf("+");
                }
            }
        }
        printf("\n");
    }
}