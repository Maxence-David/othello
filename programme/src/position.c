#include "position.h"

PO_Position PO_defPosition(int x, int y)
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

int PO_Egal(PO_Position pos1, PO_Position pos2)
{
    return ((PO_ObtenirX(pos1)==PO_ObtenirX(pos2)) && (PO_ObtenirY(pos1)==PO_ObtenirY(pos2)));
}
