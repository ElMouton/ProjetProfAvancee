#include "data.h"
#include "fonctions_fichiers.h"
#include <stdio.h>


int main()
{
    char** tab;
    char* fichier = "map_test.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);
    printf("%d, %d\n", nbLig, nbCol);

    afficher_tab_2D(tab, nbLig, nbCol);

    sprite_t test;
    init_sprite(&test, 0, 0, 2, 1); 

    

    return 0;
}
