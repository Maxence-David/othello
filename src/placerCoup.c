#include "position.h"
#include "coup.h"
#include "plateau.h"

typedef enum {HG,H,HD,D,BD,B,BG,G} Direction;

C_Coup OTH_placerCoup(PL_Plateau plateau, int partieFinie)
{

}

int OTH_coupValide(PL_Plateau plateau, C_Coup coup)
{

}

int OTH_retournerAuMoinsUnPion(PL_Plateau plateau, C_Coup coup)
{
    int modifHG, modifH, modifHD, modifD, modifBD, modifB, modifBG, modifG;

    modifHG = testModifDirection(plateau, coup, HG);
    modifH = testModifDirection(plateau, coup, H);
    modifHD = testModifDirection(plateau, coup, HD);
    modifD = testModifDirection(plateau, coup, D);
    modifBD = testModifDirection(plateau, coup, BD);
    modifB = testModifDirection(plateau, coup, B);
    modifBG = testModifDirection(plateau, coup, BG);
    modifG = testModifDirection(plateau, coup, G);
    return(modifHG || modifH || modifHD || modifD || modifBD || modifB || modifBG || modifG);

}

int testModifDirection(PL_Plateau plateau, C_Coup coup, Direction dir)
{
    int incrementX, incrementY;
    PO_Position positionAtester;
    CO_Couleur couleurAdverse;

    switch (dir)
    {
        case HG :
            incrementX = -1;
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
    positionAtester = PO_defPosition(PO_ObtenirX(C_Obtenir_Position_Coup(coup)) + incrementX, PO_ObtenirY(C_Obtenir_Position_Coup(coup)) + incrementY);
    if (C_Obtenir_Couleur_Coup(coup) == NOIR)
    {
        couleurAdverse = BLANC;
    }
    else
    {
        couleurAdverse = NOIR;
    }
    if (C_Obtenir_Couleur_Coup(coup) == PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)))
    {
        return 0;
    }
    else
    {
        while((PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == couleurAdverse) && (0 <= PO_ObtenirX(positionAtester)) && (PO_ObtenirX(positionAtester) <= 8) && (0 <= PO_ObtenirY(positionAtester)) && (PO_ObtenirY(positionAtester) <= 8))
        {
            positionAtester = PO_defPosition(PO_ObtenirX(positionAtester) + incrementX, PO_ObtenirY(positionAtester) + incrementY);
        }
        if (PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == C_Obtenir_Couleur_Coup(coup))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}