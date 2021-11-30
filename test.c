#include "data.h"
#include "fonctions_fichiers.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char** tab;
    char* fichier = "map_test.txt";
    int nbLig, nbCol;

    taille_fichier(fichier, &nbLig, &nbCol);

    tab = lire_fichier(fichier);

    

    sprite_t perso;
    init_sprite(&perso, 2, 2, 1, 2);

    int caractere = 0;
    ecrire_sprite_tab(&perso, tab);
    afficher_tab_2D(tab, nbLig, nbCol);

    while (1)
    {
        while (caractere == 0)
        {
            scanf("%d", &caractere);
        }
        
        
        if(caractere == 5){
            if(!collision_haut(&perso, tab)){
                perso.y -= 1;
            }

        }
        if(caractere == 1){
            if(!collision_gauche(&perso, tab)){
                perso.x -= 1;
            }
            
        }
        if(caractere == 2){
            if(!collision_bas(&perso, tab)){
                perso.y += 1;
            }
            
        }
        if(caractere == 3){
            if(!collision_droit(&perso, tab)){
                perso.x += 1;
            }
        }

        caractere = 0;
        ecrire_sprite_tab(&perso, tab);
        afficher_tab_2D(tab, nbLig, nbCol);
    }
    

    

    return 0;
}
