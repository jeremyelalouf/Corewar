#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *tab[40][60];
    FILE *pt=NULL; /// declaration du pointeur de fichier
    pt=fopen("Obstacles.txt","r"); /// ouverture du fichier
    if(pt==NULL) /// test douverture
        printf("erreur d'ouverture"); /// message d'erreur
    if(pt!=NULL){ /// si le fichier s'ouvre bien
        for(int i = 0; i < 40; i++)
        {
            fgets(tab[i], 120, pt);
            printf(" %s", tab[i]);
        }
    }
    return 0;
}