#include "fct.h"

int main()
{
    char grille[TAILLE][TAILLE];

    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = '#';
        }
    }

    return 0;
}