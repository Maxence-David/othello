#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "caractereEnEntier.h"
#include "placerCoup.h"
#include "majPlateau.h"
#include "partieTerminee.h"
#include "affichagePlateau.h"
#include "coupIA.h"

CO_Couleur OTH_faireUnePartie_J_VS_J(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a){

  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;
  C_Coup coupDeIA, coupJoueur1, coupJoueur2, coupJoueur;

  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant) == 0){

      (*OTH_affichagePlateau)(unPlateau);
      (*a)( OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur1,&booleen);
      if(booleen==1){
        OTH_majPlateau(&unPlateau, coupJoueur1);
      }
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);

      (*OTH_affichagePlateau)(unPlateau);
      (*a)(OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur2,&booleen);
      if(booleen==1){
        OTH_majPlateau(&unPlateau, coupJoueur2);
      } 
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);

    }


    return(OTH_obtenirCouleurGagnant(unPlateau));
}



CO_Couleur OTH_faireUnePartie_J_VS_IA(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a, ObtenirCoupIA b){
  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;
  C_Coup coupDeIA, coupJoueur1,  coupJoueur;

  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant) == 0){

  
      (*OTH_affichagePlateau)(unPlateau);
      (*a)( OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur1,&booleen);
      if(booleen==1){
        OTH_majPlateau(&unPlateau, coupJoueur1);
      }
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);

      (*OTH_affichagePlateau)(unPlateau);
      (*b)( unPlateau, CouleurJoueurCourant,&coupDeIA,&booleen);
      if (booleen==1){
        OTH_majPlateau(&unPlateau, coupDeIA);
      }
      
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);
    }
    return(OTH_obtenirCouleurGagnant(unPlateau));
}
