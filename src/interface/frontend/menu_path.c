#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "interface/frontend/menu_path.h"

void menu_path(int x, int y, int ncols, int nrows, int branco, int branco_preto)
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

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Sair 'ESC'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Clique no 'W' para introduzir o path do dataset que o programa deve seguir.";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 2, x, "%s", mensagem);
    mvprintw(y - 1, x, "Pressione 'Enter' quando terminar e no 'S' para avançar.");
    mvprintw(y, x, "Caso se tenha enganado, clique no 'Enter' quando acabar de escrever e clique no 'W' para reescrever o path.");
    mvprintw(y + 1, x, "Se não quiser introduzir o path, clique no 'S'.");
    attroff(COLOR_PAIR(branco_preto));

    // Atualiza a tela
    refresh();
}

void menu_erro_path(int x, int y, int ncols, int nrows, int branco, int branco_preto)
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

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Não foi encontrado o que procurou! Verifique a sua existência e";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 2, x, "%s", mensagem);
    mvprintw(y - 1, x, "certifique-se que introduziu o path correto!");
    attroff(COLOR_PAIR(branco_preto));

    // Atualiza a tela
    refresh();
}
