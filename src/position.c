#include "position.h"

OTH_Position OTH_Defposition(int x, int y)
{
    OTH_Position resultat;
    resultat.positionx = x;
    resultat.positiony = y;
    return resultat;

}

int OTH_ObtenirX(OTH_Position position)
{
    return position.positionx;
}

int OTH_ObtenirY(OTH_Position position)
{
    return position.positiony;
}

