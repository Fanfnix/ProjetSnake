#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "fct.h"

void afficherGrille(char grille[][TAILLE])
{
    erase();
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
}

int deplacementSerpent(struct Serpent * ad_abo)
{
    int id;
    int col = 0;
    int PosX = ((*ad_abo).x + (*ad_abo).dirx) % TAILLE;
    int PosY = ((*ad_abo).y + (*ad_abo).diry) % TAILLE;

    for (int i = 1; i < (*ad_abo).taille; i++)
    {
        id = (*ad_abo).taille - 1 - i;
        if (id == 0)
        {
            (*ad_abo).corps[id].x = (*ad_abo).x;
            (*ad_abo).corps[id].y = (*ad_abo).y;
        }
        else
        {
            (*ad_abo).corps[id].x = (*ad_abo).corps[id-1].x;
            (*ad_abo).corps[id].y = (*ad_abo).corps[id-1].y;
        }
        if (PosX == (*ad_abo).corps[id].x && PosY == (*ad_abo).corps[id].y)
        {
            col = 1;
        }
    }
    (*ad_abo).x = PosX;
    (*ad_abo).y = PosY;
    return col;
}