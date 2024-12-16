#include "fct.h"

int main()
{
    // Génere la grille //
    char grille[TAILLE][TAILLE];

    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = ' ';
        }
    }

    // Création serpent //
    struct Corps c1 = {10, 11, 'O'};
    struct Corps c2 = {10, 12, 'O'};

    struct Serpent abo = {10, 10, 3, 'O', {c1, c2}};

    // Ajout du serpent dans la grille //
    grille[abo.y][abo.x] = abo.apparence;
    for (int t = 0; t < abo.taille - 1; t++)
    {
        grille[abo.corps[t].y][abo.corps[t].x] = abo.corps[t].apparence;
    }

    // Affichage grille //
    afficherGrille(grille);

    return 0;
}