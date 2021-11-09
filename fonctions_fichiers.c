#include <stdio.h>
#include <stdlib.h>

#include "fonctions_fichiers.h"

char** allouer_tab_2D(int n, int m){
    char** tab = (char**) malloc(sizeof(char*)*n);
    for(int i = 0; i < n; i++){
        tab[i] = (char*) malloc(sizeof(char)*m);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tab[i][j] = ' ';
        }
    }
    return tab;
}

void desallouer_tab_2D(char** tab, int n){
    for(int i = 0; i < n; i++){
        free(tab[i]);
    }
    free(tab);
}

void afficher_tab_2D(char** tab, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c",tab[i][j]);
        }
        printf("\n");
    }
}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){
    FILE* fichier = fopen(nomFichier, "r");
    char caractere;
    int col = 0;

    *nbLig = 0;
    *nbCol = 0;

    while ((caractere=fgetc(fichier)) != EOF)
    {
        if(caractere == '\n'){
            *nbLig += 1;
            if(col > *nbCol){
                *nbCol = col;
            }
            col = 0;
        }else{
            col += 1;
        }
    }
    fclose(fichier);
}

char** lire_fichier(const char* nomFichier){
    FILE* fichier = fopen(nomFichier, "r");
    char** tab;
    char caractere;
    int nbLig, nbCol, i = 0, j = 0;

    taille_fichier(nomFichier, &nbLig, &nbCol);
    
    tab = allouer_tab_2D(nbLig, nbCol);

    while((caractere = fgetc(fichier)) != EOF){
        if(caractere == '\n'){
            i += 1;
            j = 0;
        }else{
            tab[i][j] = caractere;
            j += 1;
        }
    }
    fclose(fichier);
    return tab;
}

char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tab[i][j] == ancien){
                tab[i][j] = nouveau;
            }
        }
    }
    return tab;
}

void ecrire_fichier(const char* nomFichier, char** tab, int n, int m){
    FILE* fichier = fopen(nomFichier, "w");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fputc(tab[i][j], fichier);
        }
        fputc('\n', fichier);
    }
}

