#ifndef FCT_H
#define FCT_H

#define TAILLE 20

struct Serpent {
    int x, y;
    int taille;
    char apparence;
};

struct Nourriture {
    int x, y;
    char apparence;
};

void afficherGrille(char grille[][TAILLE]);
void deplacementSerpent();

#endif