#include <stdlib.h>
#include <CUnit/Basic.h>
#include "pion.h"
#include "couleur.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_PI_ChangerEtat(void) {
  PI_Pion pion = PI_CreerPion(NOIR);
  PI_ChangerEtat(pion);
  CU_ASSERT_TRUE(pion.etatPion==0);
}

void test_PI_ObtenirCouleurPion() {
  CU_ASSERT_TRUE(PI_ObtenirCouleurPion(PI_CreerPion(BLANC))==BLANC);

}

void test_PI_ObtenirEtatPion() {
  CU_ASSERT_TRUE(PI_ObtenirEtatPion(PI_CreerPion(BLANC))==1);

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
  if ((NULL == CU_add_test(pSuite, "PI_ChangerEtat", test_PI_ChangerEtat))
      || (NULL == CU_add_test(pSuite, "PI_ObtenirCouleurPion", test_PI_ObtenirCouleurPion))
      || (NULL == CU_add_test(pSuite, "PI_ObtenirEtatPion", test_PI_ObtenirEtatPion))
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
