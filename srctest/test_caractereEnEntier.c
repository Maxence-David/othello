#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include "caractereEnEntier.h"

int init_suite_success (void) {
  return 0;
}
int clean_suite_success (void) {
  return 0;
}

void test_chaine_valide_longue (void){
  int resultatAttendu = 0;
  int resultatObtenu = 1;
  char* chaine_trop_longue = "abcd";
  resultatObtenu = OTH_chaineValide(chaine_trop_longue);
  CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_abs_invalide(void){
  int resultatAttendu = 0;
  int resultatObtenu = 1;
  char* chaine_invalide = "j2";
  resultatObtenu = OTH_chaineValide(chaine_invalide);
  CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_ord_invalide(void){
  int resultatAttendu = 0;
  int resultatObtenu = 1;
  char* chaine_invalide = "b9";
  resultatObtenu = OTH_chaineValide(chaine_invalide);
  CU_ASSERT_EQUAL(resultatAttendu, resultatObtenu);
}

void test_chaineEnEntiers(void){
  int resultatAttendu = 122;
  int resultatAttenduDeux = 57;
  char* chaine = "z9";
  int* a; int *b;
  OTH_chaineEnEntiers(chaine, a, b);
  CU_ASSERT_EQUAL(resultatAttendu, a);
  CU_ASSERT_EQUAL(resultatAttenduDeux, b);
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

    if( (NULL == CU_add_test(pSuite, "test chaine invalide", test_chaine_valide_longue)) || 
      (NULL == CU_add_test(pSuite, "test abscisse", test_abs_invalide)) ||
      (NULL == CU_add_test(pSuite, "test ordonnee", test_ord_invalide)) ||
      (NULL == CU_add_test(pSuite, "test fct chaineEnEntiers", test_chaineEnEntiers))
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