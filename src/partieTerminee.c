#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "couleur.h"
#include "pion.h"



int OTH_plateauPlein(PL_Plateau plateau)
{
    int i,j;
    int caseVide;
    PO_Position position;

    caseVide = 0;
    i = 1;
    while (!caseVide && i<= 8)
    {
        j = 1;
        while (!caseVide && j <= 8)
        {
            position = PO_defPosition(i,j);
            if (PL_estVide(position,plateau))
            {
                caseVide = 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return !caseVide;
}

int OTH_plusDeCoups(PL_Plateau plateau, CO_Couleur couleurJoueurCourant)
{
    int i,j,coupOK;

    coupOK = 0;
    i = 1;
    while (!coupOK && i <= 8)
    {
        j = 1;
        while (!coupOK && j <= 8)
        {
            if (C_coupValide(PI_creerPion(couleurJoueurCourant),PO_defPosition(i,j),plateau))
            {
                coupOK = 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return !coupOK;
}

int partieTerminee(PL_Plateau plateau, CO_Couleur couleurJoueurCourant)
{
    return (OTH_plateauPlein(plateau) || OTH_plusDeCoups(plateau, couleurJoueurCourant));
}