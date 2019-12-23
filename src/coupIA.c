#include "coups.h"
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "coupIA.h"
#include "majPlateau.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>






C_Coup IA_CoupIA(PL_Plateau pl,CO_Couleur CouleurReference){
    
    CS_Coups CoupsATester;
    C_Coup CoupTest;
    C_Coup Resultat=C_InitCoup();
    int alpha = -5000;
    int beta = 5000;
    int BestScoreCoup;
    int scoreTemp;
    CoupsATester = IA_ObtenirCoupsPossible( pl,CouleurReference);
    int profondeur = 6;
    int estPossible = !CS_EstVide(CoupsATester);
    int i=1;
    if(estPossible==1)
    {
        BestScoreCoup = 0;
        while (i<=CS_NbCoups(CoupsATester))
        {
            CoupTest = CS_IemeCoup(CoupsATester,i);
            scoreTemp = IA_scoreDUnCoup(CoupTest , pl , CouleurReference , profondeur , alpha , beta);
            if (BestScoreCoup<scoreTemp)
            {
                BestScoreCoup = scoreTemp;
                Resultat = CoupTest;
            }
            CS_SupprimerCoup(CoupsATester,i);
            i=i+1;
        }
        
    }
    return(Resultat);
    
}


 int IA_scoreDUnCoup (C_Coup coup, PL_Plateau pl, CO_Couleur CouleurReference, int profondeur,int alpha , int beta  )
 {
     CO_Couleur AutreCouleur = CO_ChangerCouleur(CouleurReference);
     int ScoreFinal = 0 ;
     int TestFin = ((CS_NbCoups( IA_ObtenirCoupsPossible(pl,CouleurReference))==0) &&  (CS_NbCoups( IA_ObtenirCoupsPossible(pl,AutreCouleur))==0));
     PL_Plateau GrilleTemp;
     PL_CopierPlateau(&GrilleTemp,pl);
     OTH_majPlateau(GrilleTemp,coup);
     if (( profondeur==0 )||(TestFin==0))
     {
         ScoreFinal = IA_Evalue(GrilleTemp,CouleurReference);
         return(ScoreFinal);
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
    CS_Coups Coups_possible = IA_ObtenirCoupsPossible(pl,CouleurActuel);
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
                resultat = resultat + valeur[i][j];
            }
        }
    }
    return(resultat);
                         
}


CS_Coups IA_ObtenirCoupsPossible (PL_Plateau pl, CO_Couleur CouleurReference )
{
    int i =0;
    PI_Pion pion = PI_CreerPion(CouleurReference);
    int j=0;
    CS_Coups resultat = CS_InitCoups();
    for (i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            PO_Position position = PO_defPosition(i,j);
            C_Coup coup = C_PlacerCoup(pion,position);
            if (C_Coup_Valide(coup, pl) == 1)
            {
                CS_AjouterCoup(resultat,coup);
            }
        }
    }
    return(resultat);


}


