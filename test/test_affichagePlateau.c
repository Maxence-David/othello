#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include "plateau.h"
#include"couleur.h"
#include"pion.h"
#include "affichagePlateau.h"
#include <sys/stat.h>

int init_suite_success (void) {
return 0;
}
int clean_suite_success (void) {
return 0;
}

void test_case_vide (void){
int resultatAttendu = 1;
PL_Plateau plateau;
PL_Initialiser_Plateau(&plateau); /* tous les pions sont à l'état inactif*/

struct stat st; /* on récupère le résultat de l'affichage dans un fichier */
freopen("redir.txt", "w", stdout);
OTH_affichagePlateau(plateau);
stat("redir.txt", &st);
FILE *fichier = fopen("redir.txt", "r"); /*on vérifie que seul le symbole de la case vide a été print*/
while(fgetc(fichier)!=EOF){
    char caractere_lu = fgetc(fichier);
    if ((caractere_lu=='o') || (caractere_lu=='+')){
        resultatAttendu = 0;
    }
}
fclose(fichier);
CU_ASSERT_TRUE(resultatAttendu);
}

void test_pions_noirs (void){
int resultatAttendu = 1;
int x,y;
PL_Plateau plateau;
PI_Pion pion;
PL_Initialiser_Plateau(&plateau);
for (y = 1; y <= HAUTEUR; y++) 
{  
    for (x = 1; x <= LARGEUR; x++)   
    {
        pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); /* on créé un plateau rempli uniquement de pions noirs*/
        pion.couleurPion = CO_Noir();

    }
}
struct stat st; /* on récupère le résultat de l'affichage dans un fichier */
freopen("redir.txt", "w", stdout);
OTH_affichagePlateau(plateau);
stat("redir.txt", &st);
FILE *fichier = fopen("redir.txt", "r"); /*on vérifie que seul le symbole du pion noir a été print*/
while(fgetc(fichier)!=EOF){
    char caractere_lu = fgetc(fichier);
    if ((caractere_lu==' ') || (caractere_lu=='o')){
        resultatAttendu = 0;
    }
}
fclose(fichier);
CU_ASSERT_TRUE(resultatAttendu);
}

void test_pions_blancs (void){
int resultatAttendu = 1;
int x,y;
PL_Plateau plateau;
PI_Pion pion;
PL_Initialiser_Plateau(&plateau);
for (y = 1; y <= HAUTEUR; y++) 
{  
    for (x = 1; x <= LARGEUR; x++)   
    {
        pion = PL_ObtenirPion(PO_defPosition(y,x),plateau); /* on créé un plateau rempli uniquement de pions blancs*/
        pion.couleurPion = CO_Blanc();

    }
}
struct stat st; /* on récupère le résultat de l'affichage dans un fichier */
freopen("redir.txt", "w", stdout);
OTH_affichagePlateau(plateau);
stat("redir.txt", &st);
FILE *fichier = fopen("redir.txt", "r"); /*on vérifie que seul le symbole du pion blanc a été print*/
while(fgetc(fichier)!=EOF){
    char caractere_lu = fgetc(fichier);
    if ((caractere_lu==' ') || (caractere_lu=='+')){
        resultatAttendu = 0;
    }
}
fclose(fichier);
CU_ASSERT_TRUE(resultatAttendu);
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

if( (NULL == CU_add_test(pSuite, "test case vide", test_case_vide)) || 
(NULL == CU_add_test(pSuite, "test pions noirs", test_pions_noirs)) ||
(NULL == CU_add_test(pSuite, "test pions blancs", test_pions_blancs))
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