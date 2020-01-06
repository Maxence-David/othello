#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include "plateau.h"
#include "pion.h"
#include "partieTerminee.h"
#include "couleur.h"

int init_suite_success (void) {
    return 0;
}
int clean_suite_success (void) {
    return 0;
}

void test_plateau_plein(void){
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    PI_Pion pion;
    int x, y;
    int resultatAttendu = 1;
        for (y = 1; y <= HAUTEUR; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); /* on met l'état de tous les pions à 1 = le plateau est donc plein*/
                PI_ChangerEtat(pion);
            }
        }
    int resultatObtenu = OTH_plateauPlein(plateau);
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_plateau_une_case_vide(void){
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    PI_Pion pion;
    int x, y;
    int resultatAttendu = 0;
        for (y = 2; y <= HAUTEUR; y++) /*on laisse une case vide*/
        {  
            for (x = 2; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); /* on met l'état de tous les pions à 1 sauf pour la case laissée vide*/
                PI_ChangerEtat(pion);
            }
        }
    int resultatObtenu = OTH_plateauPlein(plateau);
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_plus_de_coups_plateau_non_plein(void){
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    int x, y;
    int resultatObtenuJoueur1, resultatObtenuJoueur2;
    int resultatAttendu = 1;
    PI_Pion pion;
        for (y = 1; y <= HAUTEUR; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau);
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Noir();
            }
        }   
    /* on créé une configuration de plateau pour laquelle il reste une case vide mais plus de coups possible*/
    /* cf http://www.ffothello.org/othello/regles-du-jeu/ , rubrique "fin de la partie"*/
        for (y = 1; y <= HAUTEUR; y++) 
        {  
            pion = PL_ObtenirPion(PO_defPosition(y,y),plateau);
            pion.couleurPion = CO_Blanc();
            pion = PL_ObtenirPion(PO_defPosition(1,y),plateau);
            pion.couleurPion = CO_Blanc();
        }
        for (x = 1; x <= LARGEUR; x++) 
        {  
            pion = PL_ObtenirPion(PO_defPosition(x,8),plateau);
            pion.couleurPion = CO_Blanc();
        }
        for (y = 2; x <= HAUTEUR; y++) 
        {  
            pion = PL_ObtenirPion(PO_defPosition(2,y),plateau);
            pion.couleurPion = CO_Blanc();
        }
    pion = PL_ObtenirPion(PO_defPosition(5,3),plateau);
    pion.couleurPion = CO_Blanc();
    pion = PL_ObtenirPion(PO_defPosition(6,4),plateau);
    pion.couleurPion = CO_Blanc();
    pion = PL_ObtenirPion(PO_defPosition(7,5),plateau);
    pion.couleurPion = CO_Blanc();
    PI_ChangerEtat(PL_ObtenirPion(PO_defPosition(1,2),plateau)); /* on laisse une case vide*/
    /*fin de la création de la configuration particulière*/
    resultatObtenuJoueur1 = OTH_plusDeCoups(plateau, CO_Noir());
    resultatObtenuJoueur2 = OTH_plusDeCoups(plateau, CO_Blanc());

    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenuJoueur1);
    CU_ASSERT_EQUAL(resultatAttendu, resultatObtenuJoueur2);
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
        if( (NULL == CU_add_test(pSuite, "test plateau plein", test_plateau_plein)) || 
        (NULL == CU_add_test(pSuite, "test plateau non plein (une case vide)", test_plateau_une_case_vide)) ||
        (NULL == CU_add_test(pSuite, "test plusDeCoups avec un plateau non plein", test_plus_de_coups_plateau_non_plein)) 
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