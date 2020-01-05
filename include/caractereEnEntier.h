/**
 * \file caractereEnEntier.h
 * \brief Fonctions permettant de passer d'une chaine de 2 caractères à 2 entiers
 * \author IMBERT Gauthier
 * \version 1.0
 * \date 
 */

#ifndef __CARACTERE_EN_ENTIER__
#define __CARACTERE_EN_ENTIER__

/**
 * \fn  OTH_chaineValide()
 * \brief Fonction verifiant la validité d'une chaine de caractère
 * \param char* chaine  La chaine que l'on teste
 * \return int  Un booléen (1=Vrai si la chaine est valide)
 */
int OTH_chaineValide(char* chaine);

/**
 * \fn  OTH_chauneEnEntier()
 * \brief Fonction pour convertir une chaine de 2 caractères en deux entiers
 * \param char* chaine  La chaine que l'on veut convertir
 * \param int* entier1  Le premier entier
 * \param int* entier2  Le second entier 
 * \return void
 */
void OTH_chaineEnEntiers(char* chaine, int* entier1, int* entier2);

#endif
