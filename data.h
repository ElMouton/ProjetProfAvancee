typedef struct sprite_s
{
    int x;
    int y;
    int w;
    int h;
}sprite_t;


typedef struct world_s
{
    sprite_t Personnage;


    int vitesse;
}world_t;

void init_sprite(sprite_t *sprite, int x, int y, int w, int h);
void print_sprite(sprite_t *sprite);

int collision(sprite_t *sprite, char tab[]);