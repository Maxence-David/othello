#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faireUnePartie.h"

int  main(int argc, char** argv) {
    CO_Couleur couleurGagnante;
    CO_Couleur couleurJoueur;
    PL_Plateau pl;
/*
    couleurGagnante = OTH_faireUnePartie_J_VS_J(OTH_affichagePlateau,OTH_placerCoup );
    affichageFinPartie(couleurGagnante);*/

    if  ( (argc==3) 
        && ((strcmp(argv[1],"JoueurVSJoueur"))||(strcmp(argv[1],"JoueurVSia"))||(strcmp(argv[1],"iaVSia")))
        &&((strcmp(argv[2],"noir")) || (strcmp(argv[2],"blanc")) )){
            if (strcmp(argv[1],"JoueurVSJoueur")){
                printf("ok \n");
                couleurGagnante = OTH_faireUnePartie_J_VS_J(OTH_affichagePlateau,OTH_placerCoup );
                affichageFinPartie(couleurGagnante);
            }
            if (strcmp(argv[2],"blanc")){
                couleurJoueur = CO_Blanc();
            }
            else {
                couleurJoueur = CO_Noir();
            }
            if (strcmp(argv[1],"JoueurVSia")){
                couleurGagnante = OTH_faireUnePartie_J_VS_IA(OTH_affichagePlateau,OTH_placerCoup,IA_CoupIA);
                affichageFinPartie(couleurGagnante);
            }
            else
            {
                couleurGagnante = OTH_Tournoi(OTH_entrerCoupTournoi,IA_CoupIA,couleurJoueur);
                affichageFinPartie(couleurGagnante);
            }
            
        }



	return EXIT_SUCCESS;

}