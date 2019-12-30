#include "pion.h"
#include "coup.h"
#include "coups.h"



CS_Coups CS_InitCoups()
{
    CS_Coups coups;
    coups.nbcoups = 0; 
    return(coups);
}

int CS_EstVide (CS_Coups coups)
{
    return( coups.nbcoups==0);

}






C_Coup CS_IemeCoup (CS_Coups coups,int i)
{
    return(coups.tabcoups[i]);
}

void CS_AjouterCoup (CS_Coups coups,C_Coup coup)
{
    coups.tabcoups[coups.nbcoups]=coup;
    coups.nbcoups = coups.nbcoups+1;

}


int CS_NbCoups (CS_Coups coups )
{
    return(coups.nbcoups);
}

int CS_EstPresent (CS_Coups coups,C_Coup coup)
{
    int i = 0;
    int test = 0;
    for (i=0; i<=coups.nbcoups-1;i++){
        if (  (PO_ObtenirX(C_Obtenir_Position_Coup(coups.tabcoups[i]))==PO_ObtenirX(C_Obtenir_Position_Coup(coup))) &&(PO_ObtenirY(C_Obtenir_Position_Coup(coups.tabcoups[i]))==PO_ObtenirY(C_Obtenir_Position_Coup(coup))) && (C_Obtenir_Couleur_Coup(coups.tabcoups[i])==C_Obtenir_Couleur_Coup(coup))==1){
            test = 1;
        }  
    }
    return(test);
}


void CS_SupprimerCoup (CS_Coups coups,int i)
{
    int j=0;
    for (j=i;j<=coups.nbcoups-1;j++){
        coups.tabcoups[i]= coups.tabcoups[i+1];
    }
    coups.nbcoups = coups.nbcoups -1;
}

CS_Coups CS_ObtenirCoupsPossible (PL_Plateau pl, CO_Couleur CouleurReference )
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






