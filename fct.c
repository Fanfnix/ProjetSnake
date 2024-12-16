#include <stdio.h>
#include <stdlib.h>

#include "fct.h"

void afficherGrille(char grille[][TAILLE])
{
    system("clear");
    for (int i = 0; i < TAILLE * 3 + 2; i++)
    {
        printf("#");
    }
    printf("\n");
    for (int y = 0; y < TAILLE; y++)
    {
        printf("#");
        for (int x = 0; x < TAILLE; x++)
        {
            printf(" %c ", grille[y][x]);
        }
        printf("#\n");
    }
    for (int i = 0; i < TAILLE * 3 + 2; i++)
    {
        printf("#");
    }
    printf("\n");
}

void deplacementSerpent()
{
    
}