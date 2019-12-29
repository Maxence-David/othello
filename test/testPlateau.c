#include <stdlib.h>
#include <CUnit/Basic.h>
#include "plateau.h"
#include "pion.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_PL_Initialiser_Plateau() {
  PL_Plateau pl;
  PL_Initialiser_Plateau(&pl);
  for (unsigned int i=1; i<=HAUTEUR; i++) {
    for (unsigned int j=1; j<=LARGEUR; j++) {
      CU_ASSERT_TRUE(PL_estVide(PO_defPosition(i,j),pl));
    }
  }
}

void test_PL_PoserPion() {
  PL_Plateau pl;
  PL_Initialiser_Plateau(&pl);
  PI_Pion pion = PI_CreerPion(BLANC);
  PO_Position pos = PO_defPosition(2,2);
  PL_PoserPion(pion,pos,&pl);
  CU_ASSERT_FALSE(PL_estVide(pos,pl));
}

void test_PL_estVide() {
  PL_Plateau pl;
  PO_Position pos = PO_defPosition(2,2);
  CU_ASSERT_TRUE(PI_ObtenirEtatPion(PL_ObtenirPion(pos,pl))==0);
}

void test_PL_CopierPlateau() {
  PL_Plateau pl, plcopy;
  PL_Initialiser_Plateau(&pl);
  PL_PoserPion(PI_CreerPion(NOIR),PO_defPosition(1,1),&pl);
  PL_CopierPlateau(pl,&plcopy);
  CU_ASSERT_TRUE(plcopy==pl);
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
  if ((NULL == CU_add_test(pSuite, "PL_Initialiser_Plateau", test_PL_Initialiser_Plateau))
      || (NULL == CU_add_test(pSuite, "PL_PoserPion", test_PL_PoserPion))
      || (NULL == CU_add_test(pSuite, "PL_estVide", test_PL_estVide))
      || (NULL == CU_add_test(pSuite, "PL_CopierPlateau", test_PL_CopierPlateau))
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
