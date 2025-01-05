#include "fct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

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

    initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();
    timeout(0);

    while (run)
    {
        // Ajout du serpent dans la grille //
        grille[abo.y][abo.x] = abo.apparence;
        for (int t = 0; t < abo.taille - 1; t++)
        {
            grille[abo.corps[t].y][abo.corps[t].x] = abo.corps[t].apparence;
        }

        // Affichage grille //
        afficherGrille(grille);
        usleep(500000);

        char car = getch();
        if (car == 'z' || car == 'q' || car == 's'|| car == 'd')
        {
            abo.direction = car;
        }
        else if (car == 'k')
        {
            break;
        }

        deplacementSerpent(&abo);

        // if (perdu(&abo))
        // {
        //     run = 0;
        // }
    }
    endwin();
    printf("Perdu noob ^^\n");
    return 0;
}