#include "data.h"

#include <stdio.h>
#include <stdlib.h>

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

void print_sprite(sprite_t *sprite){
    printf("x = %d, y = %d, w = %d, h = %d\n", sprite->x, sprite->y, sprite->w, sprite->h);
}

int collision(sprite_t *sprite, char tab[]){
    if(tab[sprite->x][sprite->y] == '1' && tab[sprite->x + sprite->w][sprite->y + sprite->h] == '1'){
        return 1;
    }
    return 0;
}