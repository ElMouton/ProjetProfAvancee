#include "data.h"
#include "fonctions_fichiers.h"
#include "evenement.h"

#include <stdio.h>
#include <stdbool.h>

int main()
{
    char** tab;
    char* fichier = "map_test.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);

    tab = lire_fichier(fichier);
    SDL_Event event;

    evenement_jeu(event);
    
    return 0;
}
