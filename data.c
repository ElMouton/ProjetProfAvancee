#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

void print_sprite(sprite_t *sprite){
    printf("x = %d, y = %d, w = %d, h = %d\n", sprite->x, sprite->y, sprite->w, sprite->h);
}

void ecrire_sprite_tab(sprite_t* sprite, char** tab){
    for (int i = 0; i < sprite->h; i++)
    {
        for(int j = 0; j < sprite->w; j++){
            tab[sprite->y + i][sprite->x + j] = '2';
        }
    }
}

bool collision_haut(sprite_t *sprite, char** tab){
    bool coll = false;
    for (int i = 0; i < sprite->w; i++)
    {
        if(tab[sprite->y-1][sprite->x + i] == '1'){
            coll = true;
        }
    }
    return coll;
}

bool collision_bas(sprite_t *sprite, char** tab){
    bool coll = false;
    for(int j = 0; j < sprite->w; j++){
        if(tab[sprite->y + sprite->h][sprite->x + j] == '1'){
            coll = true;
        }
    }
    return coll;
}

bool collision_droit(sprite_t *sprite, char** tab){
    bool coll = false;
    for (int i = 0; i < sprite->h; i++)
    {
        if(tab[sprite->y + i][sprite->x + sprite->w] == '1'){
            coll = true;
        }
    }
    return coll;
}

bool collision_gauche(sprite_t *sprite, char** tab){
    bool coll = false;
    for (int i = 0; i < sprite->h; i++)
    {
        if(tab[sprite->y + i][sprite->x - 1] == '1'){
            coll = true;
        }
    }
    return coll;
}