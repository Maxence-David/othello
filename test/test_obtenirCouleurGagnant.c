#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include "obtenirCouleurGagnant.h"
#include "couleur.h"
#include "plateau.h"
#include "pion.h"


int init_suite_success (void) {
  return 0;
}
int clean_suite_success (void) {
  return 0;
}
void test_pas_de_gagnant(void){
    int x,y;
    PI_Pion pion;
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    /*création d'une configuration de plateau pour laquelle il y a autant de pions blancs que de pions noirs*/
        for (y = 1; y <= HAUTEUR/2; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Blanc();
            }
        }
        for (y = (HAUTEUR/2)+1; y<= HAUTEUR; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Noir();
            }
        }
int resultatAttenduIlYAGagnant =0;
CO_Couleur resultatAttenduCouleur = CO_Noir();
int *resultatObtenuIlYAGagnant;
CO_Couleur *resultatObtenuCouleur;
OTH_obtenirCouleurGagnant(plateau, resultatObtenuIlYAGagnant, resultatObtenuCouleur);
CU_ASSERT_EQUAL(resultatAttenduIlYAGagnant, resultatObtenuIlYAGagnant);
CU_ASSERT_EQUAL(resultatAttenduCouleur, resultatObtenuCouleur);
}

void test_les_blancs_gagnent(void){
    int x,y;
    PI_Pion pion;
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    /*création d'une configuration de plateau pour laquelle il y a plus de pions blancs que de pions noirs*/
        for (y =(HAUTEUR/3)+1; y<= HAUTEUR; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Blanc();
            }
        }
        for (y = 1; y <= (HAUTEUR/3); y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Noir();
            }
        }
int resultatAttenduIlYAGagnant =1;
CO_Couleur resultatAttenduCouleur = CO_Noir();
int *resultatObtenuIlYAGagnant;
CO_Couleur *resultatObtenuCouleur;
OTH_obtenirCouleurGagnant(plateau, resultatObtenuIlYAGagnant, resultatObtenuCouleur);
CU_ASSERT_EQUAL(resultatAttenduIlYAGagnant, resultatObtenuIlYAGagnant);
CU_ASSERT_EQUAL(resultatAttenduCouleur, resultatObtenuCouleur);
}   

void test_les_noirs_gagnent(void){
    int x,y;
    PI_Pion pion;
    PL_Plateau plateau;
    PL_Initialiser_Plateau(&plateau);
    /*création d'une configuration de plateau pour laquelle il y a plus de pions noirs que de pions blancs*/
        for (y =(HAUTEUR/3)+1; y<= HAUTEUR; y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Noir();
            }
        }
        for (y = 1; y <= (HAUTEUR/3); y++) 
        {  
            for (x = 1; x <= LARGEUR; x++)   
            {
                pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); 
                PI_ChangerEtat(pion);
                pion.couleurPion = CO_Blanc();
            }
        }
int resultatAttenduIlYAGagnant =1;
CO_Couleur resultatAttenduCouleur = CO_Blanc();
int *resultatObtenuIlYAGagnant;
CO_Couleur *resultatObtenuCouleur;
OTH_obtenirCouleurGagnant(plateau, resultatObtenuIlYAGagnant, resultatObtenuCouleur);
CU_ASSERT_EQUAL(resultatAttenduIlYAGagnant, resultatObtenuIlYAGagnant);
CU_ASSERT_EQUAL(resultatAttenduCouleur, resultatObtenuCouleur);
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

        if( /*(NULL == CU_add_test(pSuite, "test pas de gagnants", test_pas_de_gagnant)) || */
        (NULL == CU_add_test(pSuite, "test pions blancs gagnent", test_les_blancs_gagnent)) /*||
        (NULL == CU_add_test(pSuite, "test pions noirs gagnent", test_les_noirs_gagnent))*/
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