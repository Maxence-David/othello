#include "position.h"
#include "coup.h"
#include "plateau.h"
#include "couleur.h"
#include "pion.h"
#include "partieTerminee.h"



int OTH_plateauPlein(PL_Plateau plateau)
{
    int i,j;
    int caseVide;
    PO_Position position;

    caseVide = 0;   /*On initialise le booléen à faux*/
    i = 1;
    while (!caseVide && i<= HAUTEUR)  /*On itère sur les lignes tant que la case n'est pas vide et qu'on ne sort pas du plateu*/
    {
        j = 1;
        while (!caseVide && j <= LARGEUR) /*On itère sur les colonnes tant que la case n'est pas vide et qu'on ne sort pas du plateu*/
        {
            position = PO_defPosition(i,j); /*La position que l'on souhaite tester*/
            if (PL_estVide(position,plateau))
            {
                caseVide = 1;   /*caseVide devient vrai si la case sur laquelle on se trouve est bien vide*/
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return !caseVide;   /*On retourne faux si il y a au moins une case vide / on retourne vrai si aucune case n'est vide*/
}

int OTH_plusDeCoups(PL_Plateau plateau, CO_Couleur couleurJoueurCourant)
{
    int i,j,coupOK;
    C_Coup leCoup;

    coupOK = 0; /*On initialise le booléen vérifiant la validité d'un coup à faux*/
    i = 1;
    while (!coupOK && (i <= HAUTEUR))   /*On itère sur les lignes tant que le coup n'est pas valide n'est pas vide et qu'on ne sort pas du plateu*/
    {
        j = 1;
        while (!coupOK && j <= LARGEUR)   /*On itère sur les colonnes tant que le coup n'est pas valide et qu'on ne sort pas du plateu*/
        {
	        leCoup = C_InitCoup(PO_defPosition(i,j),PI_CreerPion(couleurJoueurCourant));
            if (C_Coup_Valide(leCoup,plateau))
            {
                coupOK = 1; /*Si la position à laquelle on se trouve est valide, coupOK devient vrai*/
                PI_ChangerEtat(C_obtenirPionCoup(leCoup));  /*On remet l'état du pion à inactif*/
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return !coupOK; /*On retourne vrai si il n'y a plus aucun coups valides et faux si il reste au moins un coup valide*/
}

int OTH_partieTerminee(PL_Plateau plateau, CO_Couleur couleurJoueurCourant,CO_Couleur couleurAutreJoueur)
{
    return  (OTH_plateauPlein(plateau)==0 && 
            (OTH_plusDeCoups(plateau, couleurJoueurCourant) && OTH_plusDeCoups(plateau, couleurAutreJoueur))==0);   /*Une partie est terminée lorsque le plateau est plein ou que plus personne ne peut jouer*/
}
