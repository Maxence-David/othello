#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plateau.h"
#include <stdio.h>

void OTH_affichagePlateau(PL_Plateau plateau)
{
    int x,y;

    printf("  abcdefhg ");
    printf("\n");
    printf(" +--------+");
    printf("\n"); 
    for (y = 1; y <= PL_obtenirHauteur(plateau); y++)    /*On parcourt les lignes*/
    {
        printf("%d|",y);    
        for (x = 1; x <= PL_obtenirLargeur(plateau); x++)    /*Et les colonnes*/
        {
            if (PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == 0)   /*On vérifie l'état du pion pour chaque position*/
            {
                printf(" ");    /*Le caractère ' ' est utilisé pour une case vide*/
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
        printf("|");
        printf("\n");   /*On saute une ligne à la fin de chaque ligne parcourue*/
    }
    printf(" +--------+");
    printf("\n"); 
}


void OTH_entrerCoup(PO_Position* position){
    
}



void OTH_entrerCoupTournoi(PO_Position* position, int* res){
    
}

