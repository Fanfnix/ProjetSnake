#include "fct.h"

int main()
{
    char grille[TAILLE][TAILLE];

    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = ' ';
        }
    }

    struct Corps c1 = {10, 11, 'O'};
    struct Corps c2 = {10, 12, 'O'};

    struct Serpent abo = {10, 10, 3, 'O', {c1, c2}};

    afficherGrille(grille);

    return 0;
}