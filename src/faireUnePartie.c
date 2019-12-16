#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"

CO_Couleur faireUnePartie(){

  CO_Couleur couleurDuGagnant, joueurCourant;
  int contreIA;
  PL_Plateau unPlateau;
  C_Coup coupIA;

  contreIA = caractereEnEntier(getchar()); /* si l'utilisateur veut joueur contre l'IA ou contre un autre joueur*/
  joueurCourant = noir; /* les noirs commencent (cf règles de l'othello)*/
  unPlateau = PL_creerPlateau();
  if(contreIA == 0){ 
    while(partieTerminee(unPlateau,joueurCourant) == 0){
      coupJoueur1 = placerCoup(unPlateau, partieTerminee(unPlateau, joueurCourant));
      majPlateau(unPlateau, coupJoueur1);
      affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur1);
      coupJoueur2 = placerCoup(unPlateau, partieTerminee(unPlateau, joueurCourant));
      majPlateau(unPlateau, coupJoueur2);
      affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur1);
    }
   else {
    if(contreIA != 0){ 
	   while(partieTerminee(unPlateau,joueurCourant) == 0){
      coupJoueur = placerCoup(unPlateau, partieTerminee(unPlateau, joueurCourant));
      majPlateau(unPlateau, coupJoueur);
      affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupJoueur);
      coupIA  = moduleIA(unPlateau);
      majPlateau(unPlateau, coupJoueur2);
      affichagePlateau(unPlateau);
      joueurCourant = C_Obtenir_Couleur_Coup(coupIA);
      }
    }
  }
    return(obtenirCouleurGagnant(unPlateau));
}
