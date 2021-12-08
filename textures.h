#include <SDL2/SDL.h>
#include "data.h"

typedef struct textures_s{
    SDL_Texture* Personnage;
}textures_t;

void init_textures(textures_t* textures, SDL_Renderer* renderer);

void clean_texture(textures_t* textures);

void apply_texture(SDL_Texture* textures, SDL_Renderer* renderer, int x, int y, int w, int h);

SDL_Rect** texture_separate(SDL_Texture* texture , int nbTextureW, int nbTextureH);

void apply_wall(SDL_Renderer* renderer, SDL_Texture* textures, char** tab);

void apply_sprite(SDL_Renderer* renderer, SDL_Texture* textures, sprite_t* sprite);

void apply_perso(SDL_Renderer* renderer, textures_t* textures, sprite_t* sprite);

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);

void stop_game(world_t* world);

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);

int init_sdl(SDL_Window* fenetre, SDL_Renderer* renderer);

void init(SDL_Window* fenetre, SDL_Renderer* renderer, world_t* world, textures_t* textures);

void clear_renderer(SDL_Renderer* renderer);

void mise_a_jour_renderer(SDL_Renderer* renderer);