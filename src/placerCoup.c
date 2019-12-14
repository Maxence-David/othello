#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"
#include "position.h"
#include "pion.h"

C_Coup OTH_placerCoup(PL_Plateau plateau, int partieFinie)
{
  PI_Pion pionAPlacer; unsigned int abscisse; unsigned int ordonnee; C_Coup nouveauCoup;
  pionAPlacer.couleur = definirCouleurNouveauJoueuer(pionAPlacer);
  nouveauCoup.pion = pionAPlacer;
  nouveauCoup.position = PO_defPosition(caractereEnEntier(getchar(abscisse)), caractereEnEntier(getchar(ordonne)));
  if (C_coupValide(nouveauCoup, pionAPlacer, C_obtenirPositionCoup(nouveauCoup), lePlateau)){
    PI_changerEtat(pionAPlacer);
    return(nouveauCoup);
  }				  

}

int OTH_retournerAuMoinsUnPion(PL_Plateau plateau, C_Coup coup)
{
    int modifHG, modifH, modifHD, modifD, modifBD, modifB, modifBG, modifG;

    modifHG = OTH_testModifDirection(plateau, coup, HG);    /*On teste les modifications dans toutes les directions*/
    modifH = OTH_testModifDirection(plateau, coup, H);
    modifHD = OTH_testModifDirection(plateau, coup, HD);
    modifD = OTH_testModifDirection(plateau, coup, D);
    modifBD = OTH_testModifDirection(plateau, coup, BD);
    modifB = OTH_testModifDirection(plateau, coup, B);
    modifBG = OTH_testModifDirection(plateau, coup, BG);
    modifG = OTH_testModifDirection(plateau, coup, G);
    return(modifHG || modifH || modifHD || modifD || modifBD || modifB || modifBG || modifG);   /*Si il y a une modification dans au moins une direction, on retourne vrai*/

}

int OTH_testModifDirection(PL_Plateau plateau, C_Coup coup, Direction dir)
{
    int incrementX, incrementY;
    PO_Position positionAtester;
    CO_Couleur couleurAdverse;

    switch (dir)    /*Suivant la direction que l'on veut tester, on affecte différentes valeurs aux varialbes d'incrémentation*/
    {
        case HG :
            incrementX = -1;    /*Ici par exemple, se déplacer vers en haut à gauche revient à reculer sur l'axe X et monter sur l'axe Y*/
            incrementY = 1;
        break;
        case H :
            incrementX = 0;
            incrementY = 1;
        break;
        case HD :
            incrementX = 1;
            incrementY = 1;
        break;
        case D :
            incrementX = 1;
            incrementY = 0;
        break;
        case BD :
            incrementX = 1;
            incrementY = -1;
        break;
        case B :
            incrementX = 0;
            incrementY = -1;
        break;
        case BG :
            incrementX = -1;
            incrementY = -1;
        break;
        case G :
            incrementX = -1;
            incrementY = 0;
        break;
    }
    positionAtester = PO_defPosition(PO_ObtenirX(C_Obtenir_Position_Coup(coup)) + incrementX, PO_ObtenirY(C_Obtenir_Position_Coup(coup)) + incrementY); /*La première postion à tester est la position du pion à laquelle on ajoute la valeur des incréments X et Y*/
    
    couleurAdverse = obtenirCouleurAdverse(coup);   /*On affecte à couleurAdverse la couleur de l'adversaire*/
    
    if ((PI_ObtenirEtatPion(PL_ObtenirPion(positionAtester, plateau))) && 
        (C_Obtenir_Couleur_Coup(coup) == PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau))))    /*Si le pion juste à coté du coup que l'on place est actif et de la même couleur, alors on ne va retourner aucun pion dans cette direction */
    {
        return 0;
    }
    else
    {
        while((0 <= PO_ObtenirX(positionAtester)) && (PO_ObtenirX(positionAtester) <= PL_obtenirLargeur(plateau)) && 
            (0 <= PO_ObtenirY(positionAtester)) && (PO_ObtenirY(positionAtester) <= PL_obtenirHauteur(plateau)) && 
            (PI_ObtenirEtatPion(PL_ObtenirPion(positionAtester, plateau))) && 
            (PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == couleurAdverse))    /*On teste les positions suivantes tant que les pions sont actifs, de la couleur adverse et que l'on ne sort pas du plateau*/
        {
            positionAtester = PO_defPosition(PO_ObtenirX(positionAtester) + incrementX, PO_ObtenirY(positionAtester) + incrementY); /*La position suivante à tester est obtenue en ajoutant les incréments X et Y à la postition actuelle*/
        }
        if ((0 <= PO_ObtenirX(positionAtester)) && (PO_ObtenirX(positionAtester) <= PL_obtenirLargeur(plateau)) &&
            (0 <= PO_ObtenirY(positionAtester)) && (PO_ObtenirY(positionAtester) <= PL_obtenirHauteur(plateau)) &&
            (PI_ObtenirEtatPion(PL_ObtenirPion(positionAtester, plateau)) != 0) && 
            (PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == C_Obtenir_Couleur_Coup(coup)))   /*Lorsqu'on atteint une poistion ne respectant pas les conditions mais qui est toujours dans le plateau, on regarde la couleur et l'état du pion associé*/
        {
            return 1;   /*Si le pion est de la couleur du joueur et est actif, alors il y aura au moins une modification*/
        }
        else
        {
            return 0;
        }
    }
}

CO_Couleur obtenirCouleurAdverse(C_Coup coup)
{
    if (C_Obtenir_Couleur_Coup(coup) == NOIR)   /*Si la couleur du joueur courant est BLANC, alors celle de l'adversaire est nécéssairement NOIR et inversément*/
    {
        return BLANC;
    }
    else
    {
        return NOIR;
    }
}
