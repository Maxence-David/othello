#include "coups.h"
#include "plateau.h"
#include "coup.h"
#include "couleur.h"
#include "coupIA.h"







C_Coup CoupIA(PL_Plateau pl,CO_Couleur CouleurReference){
    
    CS_Coups CoupsATester;
    C_Coup CoupTest;
    C_Coup BestCoup;
    C_Coup Resultat;
    int alpha = -5000;
    int beta = 5000;
    int BestScoreCoup;
    int scoreTemp;
    CoupsATester = IA_ObtenirCoupsPossible( pl,CouleurReference);
    int profondeur = 6;
    int estPossible = !CS_EstVide(CoupsATester);
    int i=1;
    if(estPossible)
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
            CoupsATester = CS_SupprimerCoup(CoupsATester,i);
            i=i+1;
        }
        
    }
    return(Resultat);
    
}
