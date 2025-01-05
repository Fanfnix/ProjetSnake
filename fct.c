#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "fct.h"

void afficherGrille(char grille[][TAILLE])
{
    for (int i = 0; i < TAILLE * 3 + 2; i++)
    {
        printw("#");
    }
    printw("\n");
    for (int y = 0; y < TAILLE; y++)
    {
        printw("#");
        for (int x = 0; x < TAILLE; x++)
        {
            printw(" %c ", grille[y][x]);
        }
        printw("#\n");
    }
    for (int i = 0; i < TAILLE * 3 + 2; i++)
    {
        printw("#");
    }
    printw("\n");
    refresh();
}

void deplacementSerpent(struct Serpent * ad_abo)
{
    for (int i = 0; i < (*ad_abo).taille - 1; i++)
    {
        int id = (*ad_abo).taille - 2 - i;
        if (id != 0)
        {
            (*ad_abo).corps[id].x = (*ad_abo).corps[id - 1].x;
            (*ad_abo).corps[id].y = (*ad_abo).corps[id - 1].y;
        }
        else
        {
            (*ad_abo).corps[0].x = (*ad_abo).x;
            (*ad_abo).corps[0].y = (*ad_abo).y;
        }
    }
    
    switch ((*ad_abo).direction)
    {
        case 'z': (*ad_abo).y -= 1;
        case 's': (*ad_abo).y += 1;
        case 'q': (*ad_abo).x -= 1;
        case 'd': (*ad_abo).x += 1;
    }
}

// int perdu(struct Serpent * ad_abo)
// {
//     for (int)
// }


