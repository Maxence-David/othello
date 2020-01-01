#include <stdio.h>
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "coupIA.h"
#include "placerCoup.h"
#include "majPlateau.h"
#include "partieTerminee.h"
#include "affichagePlateau.h"
#include "obtenirCouleurGagnant.h"

CO_Couleur OTH_faireUnePartie_J_VS_J(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a){

  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;
  C_Coup coupJoueur1, coupJoueur2;
  

  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant,CO_ChangerCouleur(CouleurJoueurCourant)) == 0){

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
    int ilYaUnGagnant = 0;
    CO_Couleur couleurGagnant = CO_Noir();
    OTH_obtenirCouleurGagnant(unPlateau, &ilYaUnGagnant, &couleurGagnant);
    return(couleurGagnant);
}



CO_Couleur OTH_faireUnePartie_J_VS_IA(affichagePlateau OTH_affichagePlateau,obtenirCoupJOUEUR a, ObtenirCoupIA b){
  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;
  C_Coup coupDeIA, coupJoueur1;

  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant,CO_ChangerCouleur(CouleurJoueurCourant)) == 0){

  
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
    int ilYaUnGagnant = 0;
    CO_Couleur couleurGagnant = CO_Noir();
    OTH_obtenirCouleurGagnant(unPlateau, &ilYaUnGagnant, &couleurGagnant);
    return(couleurGagnant);
}


CO_Couleur OTH_Tournoi(entrerCoupTournoi OTH_entrerCoupTournoi, ObtenirCoupIA IA_CoupIA,CO_Couleur CouleurJoueur){
  
  CO_Couleur CouleurJoueurAdverse =CO_ChangerCouleur(CouleurJoueur);
  PL_Plateau plateau;
  PL_QuatrePionsDebut(&plateau);
  C_Coup coupJoueur;
  C_Coup CoupJoueurAdverse;
  int booleenTestJ;
  int booleenTestJA;
  PO_Position positionJoueurAdverse;
 
  while(OTH_partieTerminee(plateau,CouleurJoueurAdverse,CouleurJoueurAdverse) == 0) {

    if (CouleurJoueur==NOIR) {

      (*IA_CoupIA)(plateau,CouleurJoueur,&coupJoueur,&booleenTestJ);
      if (booleenTestJ) {
	
        OTH_majPlateau(&plateau,coupJoueur);
      }


      (*OTH_entrerCoupTournoi)(&positionJoueurAdverse,&booleenTestJA);
      if (booleenTestJA) {
        CoupJoueurAdverse =C_InitCoup(positionJoueurAdverse,PI_CreerPion(CouleurJoueurAdverse) );
        OTH_majPlateau(&plateau,CoupJoueurAdverse);
      }


    } else {
      (*OTH_entrerCoupTournoi)(&positionJoueurAdverse,&booleenTestJA);
      if (booleenTestJA) {
        CoupJoueurAdverse =C_InitCoup(positionJoueurAdverse,PI_CreerPion(CouleurJoueurAdverse) );
        OTH_majPlateau(&plateau,CoupJoueurAdverse);
      }
      (*IA_CoupIA)(plateau,CouleurJoueur,&coupJoueur,&booleenTestJ);
      if (booleenTestJ) {
	
        OTH_majPlateau(&plateau,coupJoueur);
      }
      }
    }
  int ilYaUnGagnant = 0;
  CO_Couleur couleurGagnant = CO_Noir();
  OTH_obtenirCouleurGagnant(plateau, &ilYaUnGagnant, &couleurGagnant);
  return(couleurGagnant);



}

