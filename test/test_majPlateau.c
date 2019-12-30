#include <stdio.h>
#include <stdlib.h>
#include<CUnit/Basic.h>
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
    PL_Initialiser_Plateau(lePlateau);  /**<On initialise le plateau avec la configuration de base*/
    PL_QuatrePionsDebut(lePlateau);
    positionDuPion = PO_defPosition(4, 4);  /**<On choisit un pion blanc*/
    OTH_retournerPion(lePlateau, positionDuPion);   /**<On retourne un pion blanc*/
    resultatObtenu = estNoir(PI_ObtenirCouleurPion(PL_ObtenirPion(positionDuPion, lePlateau))); /**<On vérifie qu'il est bien devenu noir*/
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_changement_couleur_pion_noir_vers_blanc(void)
{
    int resultatAttendu = 1;
    int resultatObtenu = 0;

    PL_Plateau lePlateau;
    PO_Position positionDuPion;
    PL_Initialiser_Plateau(lePlateau);  /**<On initialise le plateau avec la configuration de base*/
    PL_QuatrePionsDebut(lePlateau);
    positionDuPion = PO_defPosition(4, 5);  /**<On choisit un pion noir*/
    OTH_retournerPion(lePlateau, positionDuPion);   /**<On retourne un pion noir*/
    resultatObtenu = estBlanc(PI_ObtenirCouleurPion(PL_ObtenirPion(positionDuPion, lePlateau)));    /**<On vérifie qu'il est bien devenu blanc*/
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_pour_maj_plateau(void)
{
    int resultatAttendu = 1;
    int resultatObtenu = 0;

    int i, j;
    PL_Plateau lePlateau;
    C_Coup leCoup;
    PI_Pion pionNoir = PI_CreerPion(CO_Noir());
    PI_Pion pionBlanc = PI_CreerPion(CO_Blanc());

    PL_Initialiser_Plateau(lePlateau);  /**<Création d'une configuration particulière dans laquelle la pose d'un pion va en retourner 8 (un dans chaque direction)*/
    for(i=1; i<=5; i++)
    {
        PL_PoserPion(pionNoir, PO_defPosition(i,1),&lePlateau);
        PL_PoserPion(pionNoir, PO_defPosition(i,5),&lePlateau);
    }
    for(i=2; i<=4; i++)
    {
        PL_PoserPion(pionNoir, PO_defPosition(1,i),&lePlateau);
        PL_PoserPion(pionNoir, PO_defPosition(5,1),&lePlateau);
    }
    for(i=2; i<=4; i++)
    {
        PL_PoserPion(pionBlanc, PO_defPosition(i,2),&lePlateau);
        PL_PoserPion(pionBlanc, PO_defPosition(i,4),&lePlateau);
    }
    PL_PoserPion(pionBlanc, PO_defPosition(2,3),&lePlateau);
    PL_PoserPion(pionBlanc, PO_defPosition(4,3),&lePlateau);

    leCoup = C_InitCoup(PO_defPosition(3,3),pionNoir);

    OTH_majPlateau(&lePlateau, leCoup); /**<Le coup a été placé de manière à ce qu'il rende tous les autres pions noirs*/

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(estBlanc(PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),lePlateau))))  /**On vérifie qu'il n'y a aucun pion blanc<*/
            {
                resultatObtenu = 0; /**<Si il y a un pion blanc, resultatObtenu reste à 0*/
            }
            else
            {
                resultatObtenu = 1; /**<Si tous les pions sont noir, resultatObtenu passe à 1*/
            }
            
        }
    }

    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

int main(int argc , char** argv){
    CU_pSuite pSuite = NULL;

        if (CUE_SUCCESS != CU_initialize_registry())
            return CU_get_error() ;

    pSuite = CU_add_suite("Tests boite noire", init_suite_success , clean_suite_success ) ;
        if (NULL == pSuite) {
            CU_cleanup_registry() ;
            return CU_get_error() ;
        }

        if( (NULL == CU_add_test(pSuite, "test changement de couleur de blanc vers noir", test_changement_couleur_pion_blanc_vers_noir)) || 
            (NULL == CU_add_test(pSuite, "test changement de couleur de noir vers blanc", test_changement_couleur_pion_noir_vers_blanc)) ||
            (NULL == CU_add_test(pSuite, "test maj plateau", test_pour_maj_plateau))
        ){
        CU_cleanup_registry() ;
        return CU_get_error() ;
        }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    CU_cleanup_registry();
    return CU_get_error();
}