#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faireUnePartie.h"
#include "plateau.h"
#include "couleur.h"



int  main(int argc, char** argv) {
    CO_Couleur couleurGagnante;
    CO_Couleur couleurJoueur;

/*
    couleurGagnante = OTH_faireUnePartie_J_VS_J(OTH_affichagePlateau,OTH_placerCoup );
    affichageFinPartie(couleurGagnante);*/

    if  ( (argc==3) 
        && ((strcmp(argv[1],"JoueurVSJoueur")==0)||(strcmp(argv[1],"JoueurVSia")==0)||(strcmp(argv[1],"iaVSia")==0))
        &&((strcmp(argv[2],"noir")==0) || (strcmp(argv[2],"blanc")==0) )){
            if (strcmp(argv[1],"JoueurVSJoueur")==0){
                
                couleurGagnante = OTH_faireUnePartie_J_VS_J(OTH_affichagePlateau,OTH_placerCoup );
                affichageFinPartie(couleurGagnante);
            }
            if (strcmp(argv[2],"blanc")==0){
                couleurJoueur = CO_Blanc();
            }
            else {
                couleurJoueur = CO_Noir();
            }
            if (strcmp(argv[1],"JoueurVSia")==0){
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