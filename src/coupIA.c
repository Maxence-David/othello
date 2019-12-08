#include "coups.h"
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "coupIA.h"







C_Coup CoupIA(PL_Plateau pl,CO_Couleur CouleurReference){
    
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
     PL_Plateau GrilleTemp = PL_CopierPlateau(pl);
     MiseAJourPlateau(GrilleTemp,coup);
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







