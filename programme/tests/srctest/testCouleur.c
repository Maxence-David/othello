#include<stdlib.h>
#include<CUnit/Basic.h>
#include"couleur.h"
#include <stdbool.h>

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

void test_est_noir_pour_couleur_blanche(void){
  CO_Couleur couleur_blanche = CO_Blanc();
  CU_ASSERT_TRUE(!CO_estNoir(couleur_blanche));
}

void test_est_noir_pour_couleur_noire(void){
  CO_Couleur couleur_noire = CO_Noir();
  CU_ASSERT_TRUE(CO_estNoir(couleur_noire));
}

void test_est_blanc_pour_couleur_blanche(void){
  CO_Couleur couleur_blanche = CO_Blanc();
  CU_ASSERT_TRUE(CO_estBlanc(couleur_blanche));
}

void test_est_blanc_pour_couleur_noire(void){
  CO_Couleur couleur_noire = CO_Noir();
  CU_ASSERT_TRUE(!CO_estBlanc(couleur_noire));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;
  
    /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
      if((NULL == CU_add_test(pSuite, " test si c'est noir pour une couleur blanche", test_est_noir_pour_couleur_blanche))
      || (NULL == CU_add_test(pSuite, " test si c'est noir pour une couleur noire", test_est_noir_pour_couleur_noire))
      || (NULL == CU_add_test(pSuite, " test si c'est blanc pour une couleur blanche", test_est_blanc_pour_couleur_blanche))
      || (NULL == CU_add_test(pSuite, " test si c'est blanc pour une couleur noire", test_est_blanc_pour_couleur_noire))      
      ) 
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}


