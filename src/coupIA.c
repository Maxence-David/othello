#include "coups.h"
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "coupIA.h"
#include "majPlateau.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



void IA_CoupIA(PL_Plateau pl,CO_Couleur CouleurReference,C_Coup* Resultat, int* estPossible){
    
    CS_Coups CoupsATester;
    C_Coup CoupTest;

    int alpha = -5000;
    int beta = 5000;
    int BestScoreCoup;
    int scoreTemp;
    CoupsATester = CS_ObtenirCoupsPossible(pl,CouleurReference);
    int profondeur = 6;
    *estPossible = !CS_EstVide(CoupsATester);
    
    
    /*for (int i = 1; i < CS_NbCoups(CoupsATester) +1; i++){
    PO_Position temp = C_Obtenir_Position_Coup (CS_IemeCoup(CoupsATester, i));
    printf("%i, %i\n", PO_ObtenirX(temp), PO_ObtenirY(temp));
    }*/

    int i=1;
    if(*estPossible)
    {
        BestScoreCoup = -7000;
        for (i=1; i<=CS_NbCoups(CoupsATester); i++)
        {
            CoupTest = CS_IemeCoup(CoupsATester,i);
            scoreTemp = IA_scoreDUnCoup(CoupTest , pl , CouleurReference , profondeur , alpha , beta);
            if (BestScoreCoup<scoreTemp)
            {
                BestScoreCoup = scoreTemp;
                *Resultat = CoupTest;
            }
            /*CS_SupprimerCoup(CoupsATester,i);*/
            
        }
        
    }
    
}






int IA_scoreDUnCoup (C_Coup coup, PL_Plateau pl, CO_Couleur CouleurReference, int profondeur,int alpha , int beta  )
 {
     CO_Couleur AutreCouleur = CO_ChangerCouleur(CouleurReference);
     int TestFin = ((CS_NbCoups( CS_ObtenirCoupsPossible(pl,CouleurReference))==0) &&  (CS_NbCoups( CS_ObtenirCoupsPossible(pl,AutreCouleur))==0));
     PL_Plateau GrilleTemp;
     PL_CopierPlateau(&GrilleTemp,pl);
     maj(&GrilleTemp,coup);
     if (( profondeur==0 )||(TestFin==1))
     {
        
        return(IA_Evalue(GrilleTemp,CouleurReference));
     }
     else
     {
        return(IA_Alpha_Beta(GrilleTemp,CouleurReference,AutreCouleur,profondeur-1,alpha,beta));
        
     }
     

 }





int max (int a,int b ){
    if (a<=b){
        return(b);
    }
    else {
        return(a);
    }
}


int min(int a, int b ){
    if (a<=b){
        return(a);
    }
    else{
        return(b);
    }
}


int IA_Alpha_Beta (PL_Plateau pl,CO_Couleur CouleurReference,CO_Couleur CouleurActuel, int profondeur, int alpha, int beta)  {
    int resultat;
    int i;
    CS_Coups Coups_possible = CS_ObtenirCoupsPossible(pl,CouleurActuel);
    if (!CS_EstVide(Coups_possible)){
        resultat = IA_scoreDUnCoup(CS_IemeCoup(Coups_possible,1),pl,CouleurReference,profondeur,alpha,beta);
    }
    for (i=2;i<=CS_NbCoups(Coups_possible);i=i+1){
        int score =IA_scoreDUnCoup(CS_IemeCoup(Coups_possible,i),pl,CouleurReference,profondeur,alpha,beta);
        if(CouleurReference != CouleurActuel){
            resultat = max(score,resultat);
            if (resultat > alpha){
                alpha = resultat;
                if(alpha>beta){
                    return(resultat);
                }

        
            }
        }
        else{
            resultat = min(score,resultat);
            if (resultat<beta){
                beta = resultat;
                if (beta<alpha){
                    return(resultat);
                }
            }
        }
    }
    return(resultat);
}



int IA_Evalue(PL_Plateau pl, CO_Couleur CouleurReference){
    int i = 0;
    int j = 0;
    int resultat =0;
    int valeur[8][8]=   {{40,3,15,10,10,15,3,40},
                         {3,0,9,12,12,9,0,3},
                         {15,9,11,15,15,11,9,15},
                         {10,12,15,18,18,15,12,10},
                         {10,12,15,18,18,15,12,10},
                         {15,9,11,15,15,11,9,15},
                         {3,0,9,12,12,9,0,3},
                         {40,3,15,10,10,15,3,40}};
                         
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=8;j++)
        {
            if (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(i,j),pl))==CouleurReference){
                resultat = resultat + valeur[i-1][j-1];
            }
        }
    }
    return(resultat);
                         
}





