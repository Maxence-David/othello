#include "position.h"

PO_Position OTH_Defposition(int x, int y)
{
    PO_Position resultat;
    resultat.positionx = x;
    resultat.positiony = y;
    return resultat;

}

int PO_ObtenirX(PO_Position position)
{
    return position.positionx;
}

int PO_ObtenirY(PO_Position position)
{
    return position.positiony;
}

