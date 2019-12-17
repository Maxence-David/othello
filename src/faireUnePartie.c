#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "caractereEnEntier.h"
#include "placerCoup.h"
#include "majPlateau.h"
#include"partieTerminee.h"
#include "affichagePlateau.h"
#include "coupIA.h"

CO_Couleur OTH_faireUnePartie(){

  CO_Couleur joueurCourant;
  int booleen;
  int contreIA;
  PL_Plateau unPlateau;
  C_Coup coupDeIA, coupJoueur1, coupJoueur2, coupJoueur;

  scanf("%d", contreIA);/* si l'utilisateur veut joueur contre l'IA ou contre un autre joueur*/
  joueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  *unPlateau = PL_creerPlateau();
  if(contreIA != 0){ 
    while(OTH_partieTerminee(unPlateau,joueurCourant) == 0){
      booleen = OTH_partieTerminee(unPlateau, joueurCourant);
      coupJoueur1 = OTH_placerCoup(unPlateau, booleen);
      OTH_majPlateau(unPlateau, coupJoueur1);
      OTH_affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur1);
      booleen = OTH_partieTerminee(unPlateau, joueurCourant);
      coupJoueur2 = OTH_placerCoup(unPlateau, booleen);
      OTH_majPlateau(unPlateau, coupJoueur2);
      OTH_affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur1);
    }
  }
   else {
    if(contreIA == 0){ 
	   while(OTH_partieTerminee(unPlateau,joueurCourant) == 0){
      booleen = OTH_partieTerminee(unPlateau, joueurCourant);
      coupJoueur = OTH_placerCoup(unPlateau, booleen);
      OTH_majPlateau(unPlateau, coupJoueur);
      OTH_affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur);
      coupDeIA  = CoupIA(unPlateau, joueurCourant);
      OTH_majPlateau(unPlateau, coupJoueur2);
      OTH_affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupDeIA);
      }
    }
  }
    return(OTH_obtenirCouleurGagnant(unPlateau));
}
