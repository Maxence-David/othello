#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plateau.h"
#include "coup.h"
#include "caractereEnEntier.h"
#include <stdio.h>

void OTH_affichagePlateau(PL_Plateau plateau)
{
    int x,y;

    printf("  abcdefgh ");
    printf("\n");
    printf(" +--------+");
    printf("\n"); 
    for (y = 1; y <= 8; y++)    /*On parcourt les lignes*/
    {
        printf("%d|",y);    
        for (x = 1; x <= 8; x++)    /*Et les colonnes*/
        {
            if (PI_ObtenirEtatPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == 0)   /*On vérifie l'état du pion pour chaque position*/
            {
                printf(" ");    /*Le caractère ' ' est utilisé pour une case vide*/
            }
            else
            {
                if (PI_ObtenirCouleurPion(PL_ObtenirPion(PO_defPosition(y,x),plateau)) == NOIR) /*On vérifie la couleur du pion pour chaque position*/
                {
                    printf("o");    /*Le caractère 'o' est utilisé pour les pions NOIRs*/
                }
                else
                {
                    printf("+");    /*Le caractère '+' est utilisé pour les pions NOIRs*/
                }
            }
        }
        printf("|");
        printf("\n");   /*On saute une ligne à la fin de chaque ligne parcourue*/
    }
    printf(" ----------");
    printf("\n"); 
}


PO_Position OTH_entrerCoup(CO_Couleur couleurJoueurCourant)
{
    char coordCoup[10];	/**<On prévoit une chaine de caractère plus grande au cas où l'utilisateur entre n'importe quoi*/
	int entierColonnes, entierLignes;
    PO_Position positionDuCoup;
    char* couleurDuJoueur;

    if(couleurJoueurCourant == NOIR)
    {
        couleurDuJoueur = "Noir";
    }
    else
    {
        couleurDuJoueur = "Blanc";
    }
    

	do {
		printf("Joueur %s c'est à vous de jouer, entrez les coordonnées de votre coup svp : ", couleurDuJoueur);
		scanf("%s", coordCoup);
	}	while (!OTH_chaineValide(coordCoup));

	OTH_chaineEnEntiers(coordCoup, &entierColonnes, &entierLignes);
	
	positionDuCoup = PO_defPosition(entierLignes,entierColonnes),PI_CreerPion(couleurJoueurCourant);

    return positionDuCoup;
}

void OTH_entrerCoupTournoi(PO_Position* position, int* res){
    
}

void affichageFinPartie (CO_Couleur couleur){
    if (couleur == NOIR){
        printf("victoire des noir \n");
    }
    else {
        printf("victoire des blanc \n");
    }
}

void affichageAide()
{
    printf("Aide du programme othello \n");
    printf("Les options possibles sont : \n");
    printf("    othello JoueurVSia blanc|noir \n");
    printf("        permet de jouer contre l'ordinateur en choisissant la couleur \n");
    printf("        par defaut la profondeur d'analyse est egale a 5 \n");
    printf("    othello JoueurVSJoueur \n");
    printf("        permet de faire jouer deux joueur chacun leur tour sur la même machine \n");
    printf("    othello tournoi blanc|noir \n");
    printf("        permet de faire jouer le programme dans un mode 'tournoi' en lui donnant les blancs ou les noirs \n");
    printf("        par defaut la profondeur d'analyse est egale a 5 \n");


}