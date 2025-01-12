#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "fct.h"


void rafraichissementGrille(char grille[][TAILLE], struct Serpent * ad_abo, struct Nourriture * ad_food)
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = ' ';
        }
    }
    grille[(*ad_food).x][(*ad_food).y] = (*ad_food).apparence;
    grille[(*ad_abo).x][(*ad_abo).y] = (*ad_abo).apparence;
    for (int t = 0; t < (*ad_abo).taille - 1; t++)
    {
        grille[(*ad_abo).corps[t].x][(*ad_abo).corps[t].y] = (*ad_abo).corps[t].apparence;
    }
}


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


int deplacementSerpent(struct Serpent * ad_abo, struct Nourriture * ad_food)
{
    int id;
    int col = 0;
    int TempX, TempY;
    int NPosX = ((*ad_abo).x + (*ad_abo).dirx) % TAILLE; // Nouvelle position x
    int NPosY = ((*ad_abo).y + (*ad_abo).diry) % TAILLE; // Nouvelle position y

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
            if (i == 1)
            {
                TempX = (*ad_abo).corps[id].x;
                TempY = (*ad_abo).corps[id].y;
            }
        }
        if (NPosX == (*ad_abo).corps[id].x && NPosY == (*ad_abo).corps[id].y)
        {
            col = 1;
        }
    }
    (*ad_abo).x = NPosX;
    (*ad_abo).y = NPosY;

    if ((*ad_abo).x == (*ad_food).x && (*ad_abo).y == (*ad_food).y)
    {
        (*ad_abo).taille += 1;
        struct Corps NewCorps = {TempX, TempY, 'o'};
        (*ad_abo).corps[(*ad_abo).taille - 2] = NewCorps;
        (*ad_food).x = rand() % TAILLE;
        (*ad_food).y = rand() % TAILLE;
    }
    return col;
}