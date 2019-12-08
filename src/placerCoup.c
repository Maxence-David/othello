#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "placerCoup.h"

C_Coup OTH_placerCoup(PL_Plateau plateau, int partieFinie)
{

}

int OTH_retournerAuMoinsUnPion(PL_Plateau plateau, C_Coup coup)
{
    int modifHG, modifH, modifHD, modifD, modifBD, modifB, modifBG, modifG;

    modifHG = OTH_testModifDirection(plateau, coup, HG);
    modifH = OTH_testModifDirection(plateau, coup, H);
    modifHD = OTH_testModifDirection(plateau, coup, HD);
    modifD = OTH_testModifDirection(plateau, coup, D);
    modifBD = OTH_testModifDirection(plateau, coup, BD);
    modifB = OTH_testModifDirection(plateau, coup, B);
    modifBG = OTH_testModifDirection(plateau, coup, BG);
    modifG = OTH_testModifDirection(plateau, coup, G);
    return(modifHG || modifH || modifHD || modifD || modifBD || modifB || modifBG || modifG);

}

int OTH_testModifDirection(PL_Plateau plateau, C_Coup coup, Direction dir)
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
        while((PI_ObtenirEtatPion(PL_ObtenirPion(positionAtester, plateau))) && (PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == couleurAdverse) && (0 <= PO_ObtenirX(positionAtester)) && (PO_ObtenirX(positionAtester) <= 8) && (0 <= PO_ObtenirY(positionAtester)) && (PO_ObtenirY(positionAtester) <= 8))
        {
            positionAtester = PO_defPosition(PO_ObtenirX(positionAtester) + incrementX, PO_ObtenirY(positionAtester) + incrementY);
        }
        if ((PI_ObtenirEtatPion(PL_ObtenirPion(positionAtester, plateau)) != 0) && (PI_ObtenirCouleurPion(PL_ObtenirPion(positionAtester, plateau)) == C_Obtenir_Couleur_Coup(coup)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}