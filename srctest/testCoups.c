#include <stdlib.h>
#include <CUnit/Basic.h>
#include "coups.h"


int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CS_InitCoups(void) {
  CU_ASSERT_TRUE(CS_NbCoups(CS_InitCoups())==0);
}

void test_CS_IemeCoup() {
  CS_Coups coups = CS_InitCoups();
  C_Coup coup1 = C_InitCoup(PO_defPosition(1,1),PI_CreerPion(BLANC));
  C_Coup coup2 = C_InitCoup(PO_defPosition(2,2),PI_CreerPion(NOIR));
  CS_AjouterCoup(&coups,coup1);
  CS_AjouterCoup(&coups,coup2);
  CU_ASSERT_TRUE(C_Egale(CS_IemeCoup(coups,1),coup1));
  CU_ASSERT_TRUE(C_Egale(CS_IemeCoup(coups,2),coup2));
}

void test_CS_AjouterCoup(void) {
  C_Coup coup = C_InitCoup(PO_defPosition(2,2),PI_CreerPion(BLANC));
  CS_Coups coups = CS_InitCoups();
  unsigned int nbCoups = CS_NbCoups(coups);
  CS_AjouterCoup(&coups,coup);
  CU_ASSERT_TRUE(CS_NbCoups(coups)==nbCoups+1);
}

void test_CS_EstPresent() {
  CS_Coups coups = CS_InitCoups();
  C_Coup coup1 = C_InitCoup(PO_defPosition(2,2),PI_CreerPion(BLANC));
  C_Coup coup2 = C_InitCoup(PO_defPosition(2,4),PI_CreerPion(NOIR));
  CS_AjouterCoup(&coups,coup1);
  CU_ASSERT_TRUE(CS_EstPresent(coups,coup1));
  CU_ASSERT_FALSE(CS_EstPresent(coups,coup2));
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

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL==CU_add_test(pSuite, "CS_InitCoups", test_CS_InitCoups))
      || (NULL==CU_add_test(pSuite, "CS_IemeCoup", test_CS_IemeCoup))
      || (NULL==CU_add_test(pSuite, "CS_AjouterCoup", test_CS_AjouterCoup))
      || (NULL==CU_add_test(pSuite, "CS_EstPresent", test_CS_EstPresent))
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
