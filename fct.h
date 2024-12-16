#ifndef FCT_H
#define FCT_H

#define TAILLE 20

struct Corps {
    int x, y;
    char apparence;
};

struct Serpent {
    int x, y;
    int taille;
    char apparence;
    struct Corps corps[20];
    char direction;
};

struct Nourriture {
    int x, y;
    char apparence;
};

void afficherGrille(char grille[][TAILLE]);
void deplacementSerpent(struct Serpent * ad_abo);

#endif