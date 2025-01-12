#include "fct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

int main()
{
    // Génere la grille //
    char grille[TAILLE][TAILLE];

    // Création serpent //
    struct Corps c1 = {10, 11, 'o'};
    struct Corps c2 = {10, 12, 'o'};

    struct Serpent abo = {10, 10, 3, 'v', {c1, c2}, 1, 0};
    struct Serpent * ad_abo = &abo;

    // Création fruit //
    struct Nourriture food = {rand() % TAILLE, rand() % TAILLE, '@'};
    struct Nourriture * ad_food = &food;

    // Ajout du serpent dans la grille //
    rafraichissementGrille(grille, ad_abo, ad_food);

    // Mise en place de ncurses
    WINDOW * win = initscr();			// Initialisation ncurses
	raw();				                // Empêche le programme d'interpréter les combinaisons de touches (utile quand on utilisait le CTRL+z dans la console)
	keypad(win, TRUE);		            // Active la tecture de toute les touches du clavier
	noecho();                           // Taper sur une touche ne l'affichera pas dans la console
    nodelay(win, TRUE);                 // La fonction wgetch n'attendra pas qu'une touche soie pressée

    while (1)
    {
        // Ajout du serpent dans la grille //
        rafraichissementGrille(grille, ad_abo, ad_food);

        // Affichage grille //
        afficherGrille(grille);
        usleep(100000);

        char pressed = wgetch(win);

        if (pressed == 'z') { abo.dirx = -1; abo.diry = 0; abo.apparence = '^';}
        if (pressed == 's') { abo.dirx = 1; abo.diry = 0; abo.apparence = 'v';}
        if (pressed == 'q') { abo.dirx = 0; abo.diry = -1; abo.apparence = '<';}
        if (pressed == 'd') { abo.dirx = 0; abo.diry = 1; abo.apparence = '>';}
        if (pressed == 'k') { break;}

        if (deplacementSerpent(ad_abo, ad_food))
        {
            break;
        }
    }
    endwin(); // Pour arrêter ncurses
    return 0;
}