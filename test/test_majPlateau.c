#include <stdio.h>
#include <stdlib.h>
#include "majPlateau.h"

int init_suite_success(void)
{
    return 0;
}
int clean_suite_success(void)
{
    return 0;
}

void test_changement_couleur_pion_blanc_vers_noir(void)
{
    int resultatAttendu = 1;
    int resultatObtenu = 0;

    PL_Plateau lePlateau;
    PO_Position positionDuPion;
    PL_Initialiser_Plateau(lePlateau);
    PL_QuatrePionsDebut(lePlateau);
    positionDuPion = PO_defPosition(4, 4);
    OTH_retournerPion(lePlateau, positionDuPion);
    resultatObtenu = estNoir(PI_ObtenirCouleurPion(PL_ObtenirPion(positionDuPion, lePlateau)));
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_changement_couleur_pion_noir_vers_blanc(void)
{
    int resultatAttendu = 1;
    int resultatObtenu = 0;

    PL_Plateau lePlateau;
    PO_Position positionDuPion;
    PL_Initialiser_Plateau(lePlateau);
    PL_QuatrePionsDebut(lePlateau);
    positionDuPion = PO_defPosition(4, 5);
    OTH_retournerPion(lePlateau, positionDuPion);
    resultatObtenu = estBlanc(PI_ObtenirCouleurPion(PL_ObtenirPion(positionDuPion, lePlateau)));
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

