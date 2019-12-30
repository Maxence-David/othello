#include <stdlib.h>
#include <CUnit/Basic.h>
#include "coup.h"
#include "pion.h"
#include "plateau.h"
#include "position.h"
#include "couleur.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_C_obtenirPionCoup(void) {
  C_Coup coup;
  CO_Couleur couleur = BLANC ;
  PI_Pion pion = PI_CreerPion(couleur);
  PO_Position pos = PO_defPosition(2,3);
  coup = C_InitCoup(pos,pion);
  CU_ASSERT_TRUE(PI_ObtenirCouleurPion(C_obtenirPionCoup(coup))==PI_ObtenirCouleurPion(pion));
}

void test_C_Obtenir_Position_Coup(void) {
  C_Coup coup;
  CO_Couleur couleur = BLANC ;
  PI_Pion pion = PI_CreerPion(couleur);
  PO_Position pos = PO_defPosition(2,3);
  coup = C_InitCoup(pos,pion);
  CU_ASSERT_TRUE(PO_ObtenirX(C_Obtenir_Position_Coup(coup))==PO_ObtenirX(pos)&&PO_ObtenirY(C_Obtenir_Position_Coup(coup))==PO_ObtenirY(pos));
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
  if ((NULL == CU_add_test(pSuite, "C_obtenirPionCoup", test_C_obtenirPionCoup))
      || (NULL == CU_add_test(pSuite, "C_Obtenir_Position_Coup", test_C_Obtenir_Position_Coup))
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
