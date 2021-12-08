#include <SDL2/SDL.h>
#include "data.h"

typedef struct textures_s{
    SDL_Texture* Personnage;
}textures_t;

void init_textures(textures_t* texture, SDL_Renderer* renderer);

void clean_texture(textures_t* texture);

void apply_texture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);

void apply_sprite(SDL_Renderer* renderer, SDL_Texture* texture, sprite_t* sprite);

void apply_perso(SDL_Renderer* renderer, textures_t* texture, sprite_t* sprite);

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);

void renderer_clear(SDL_Renderer* renderer);

void mise_a_jour_renderer(SDL_Renderer* renderer);