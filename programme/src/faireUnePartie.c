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


CO_Couleur OTH_faireUnePartie_J_VS_J(){

  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;



  
  C_Coup coupJoueur1, coupJoueur2;
  
  
  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant,CO_ChangerCouleur(CouleurJoueurCourant))){

      OTH_affichagePlateau(unPlateau);
      OTH_placerCoup( OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur1,&booleen);

      if(booleen != 0){
        maj(&unPlateau, coupJoueur1);
      }
      
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);

      OTH_affichagePlateau(unPlateau);
      OTH_placerCoup(OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur2,&booleen);
      if(booleen != 0){
        maj(&unPlateau, coupJoueur2);
      }
      CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);
    }
    
    int ilYaUnGagnant = 0;
    CO_Couleur couleurGagnant = CO_Noir();
    OTH_obtenirCouleurGagnant(unPlateau, &ilYaUnGagnant, &couleurGagnant);
    return(couleurGagnant);
}



CO_Couleur OTH_faireUnePartie_J_VS_IA(CO_Couleur couleurJoueurHumain){
  CO_Couleur CouleurJoueurCourant;
  int booleen;
  PL_Plateau unPlateau;
  C_Coup coupDeIA, coupJoueur1;

  CouleurJoueurCourant = CO_Noir(); /* les noirs commencent (cf règles de l'othello)*/
  PL_QuatrePionsDebut(&unPlateau);
  
    while(OTH_partieTerminee(unPlateau,CouleurJoueurCourant,CO_ChangerCouleur(CouleurJoueurCourant)) ){
      if (couleurJoueurHumain==NOIR){
  
        OTH_affichagePlateau(unPlateau);
        OTH_placerCoup( OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur1,&booleen);
        if(booleen!=0){
          maj(&unPlateau, coupJoueur1);
        }
        CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);



        OTH_affichagePlateau(unPlateau);
        printf("je cherche la meilleur solution pour te battre, patiente quelques instant ...\n ");
        IA_CoupIA( unPlateau, CouleurJoueurCourant,&coupDeIA,&booleen);
 
        if (booleen!=0){
          maj(&unPlateau, coupDeIA);
        }
        CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);
      }
      else
      {
        OTH_affichagePlateau(unPlateau);
        printf("je cherche la meilleur solution pour te battre, patiente quelques instant ...\n ");
        IA_CoupIA( unPlateau, CouleurJoueurCourant,&coupDeIA,&booleen);
 
        if (booleen!=0){
          maj(&unPlateau, coupDeIA);
        }
        CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);


        OTH_affichagePlateau(unPlateau);
        OTH_placerCoup( OTH_entrerCoup, unPlateau, CouleurJoueurCourant,&coupJoueur1,&booleen);
        if(booleen!=0){
          maj(&unPlateau, coupJoueur1);
        }
        CouleurJoueurCourant = CO_ChangerCouleur(CouleurJoueurCourant);

      }
      
    }
    int ilYaUnGagnant = 0;
    CO_Couleur couleurGagnant = CO_Noir();
    OTH_obtenirCouleurGagnant(unPlateau, &ilYaUnGagnant, &couleurGagnant);
    return(couleurGagnant);
}


CO_Couleur OTH_Tournoi(CO_Couleur CouleurJoueur){
  
  CO_Couleur CouleurJoueurAdverse =CO_ChangerCouleur(CouleurJoueur);
  PL_Plateau plateau;
  PL_QuatrePionsDebut(&plateau);
  C_Coup coupJoueur;
  C_Coup CoupJoueurAdverse;
  int booleenTestJ;
  int booleenTestJA;
  PO_Position positionJoueurAdverse;
 
  while(OTH_partieTerminee(plateau,CouleurJoueur,CouleurJoueurAdverse) ) {

    if (CouleurJoueur==NOIR) {

      IA_CoupIA(plateau,CouleurJoueur,&coupJoueur,&booleenTestJ);
      if (booleenTestJ != 0) {
        maj(&plateau,coupJoueur);

      }
      affichagecoupTournoi(coupJoueur,booleenTestJ);


      OTH_entrerCoupTournoi(&positionJoueurAdverse,&booleenTestJA);
      if (booleenTestJA!=0) {
        
        CoupJoueurAdverse =C_InitCoup(positionJoueurAdverse,PI_CreerPion(CouleurJoueurAdverse) );
        
        affichagecoupTournoi(CoupJoueurAdverse,booleenTestJA);
        maj(&plateau,CoupJoueurAdverse);
       
      }


    } else 
    {
      OTH_entrerCoupTournoi(&positionJoueurAdverse,&booleenTestJA);
      if (booleenTestJA!=0) {
        CoupJoueurAdverse =C_InitCoup(positionJoueurAdverse,PI_CreerPion(CouleurJoueurAdverse) );
        maj(&plateau,CoupJoueurAdverse);
      }



      IA_CoupIA(plateau,CouleurJoueur,&coupJoueur,&booleenTestJ);
      if (booleenTestJ!=0) {
	
        maj(&plateau,coupJoueur);
        
      }
      affichagecoupTournoi(coupJoueur,booleenTestJ);


      }
    }
  int ilYaUnGagnant = 0;
  CO_Couleur couleurGagnant = CO_Noir();
  OTH_obtenirCouleurGagnant( plateau, &ilYaUnGagnant, &couleurGagnant);
  return(couleurGagnant);



}

