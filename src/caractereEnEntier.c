#include <string.h>
#include "caractereEnEntier.h"

int OTH_chaineValide(char* chaine)
{
    int entier1, entier2;

    if (strlen(chaine) > 2)
    {
        return 0;
    }
    else
    {
        if((chaine[0] < 97) || (chaine[0] > 105))   /*Le caractère 'a' est codé 97 en ASCII et le 'i' 105*/
        {
            return 0;
        }
        else
        {
            if((chaine[1] < 48) || (chaine[1] > 56))    /*Le caractère '0' est codé 48 en ASCII et le '8' 56*/
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        
    }
}

void OTH_chaineEnEntiers(char* chaine, int* entier1, int* entier2)
{
    *entier1 = chaine[0] - 97;    /*Dans la table ASCII  le caractère a est codé par '97' donc pour obtenir la valeur en entier d'un caractère il suffit de lui soustraire 97 ; on considère que a=0, b=1 ... , i=8*/
    *entier2 = chaine[1] - 48;   /*Dans la table ASCII  le caractère 0 est codé par '48' donc pour obtenir la valeur en entier d'un caractère il suffit de lui soustraire 48 ; ceci ne fonctionne que pour les entiers compris entre 0 et 9*/
}
