#include "fct.h"
#include <conio.h>

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
    struct Corps c1 = {10, 11, 'o'};
    struct Corps c2 = {10, 12, 'o'};

    struct Serpent abo = {10, 10, 3, 'O', {c1, c2}, 'z'};

    // Ajout du serpent dans la grille //
    grille[abo.y][abo.x] = abo.apparence;
    for (int t = 0; t < abo.taille - 1; t++)
    {
        grille[abo.corps[t].y][abo.corps[t].x] = abo.corps[t].apparence;
    }

    int run = 1;

    while (run)
    {
        // Affichage grille //
        afficherGrille(grille);
        system("sleep 0.5");

        if (kbhit())
        {
            char car = getch();
            if (car == 'z' || car == 'q' || car == 's'|| car == 'd')
            {
                (*ad_abo).direction = car;
            }
        }

        deplacementSerpent(&abo);
    }
    return 0;
}