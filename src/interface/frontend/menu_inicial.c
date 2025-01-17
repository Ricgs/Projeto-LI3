#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdbool.h>

#include "interface/frontend/menu_inicial.h"

void menu_inicial(int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no centro da tela
    const char *iniciar_query = "Iniciar Query 'I'";
    int iniciar_query_len = strlen(iniciar_query);
    int x = (ncols - iniciar_query_len) / 2;
    int y = nrows / 2;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 8, x, "%s", iniciar_query);
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 3, x, "Ajuda 'H'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y + 2, x, "Sair 'ESC'");
    attroff(COLOR_PAIR(branco_preto));

    // Atualiza a tela
    refresh();
}