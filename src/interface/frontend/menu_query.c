#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "interface/frontend/menu_query.h"

void menu_queries(int x, int y, int ncols, int nrows, int branco, int branco_preto)
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
    const char *mensagem = "Introduza o comando a executar respeitando as seguintes instruções:";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 8, x, "%s", mensagem);
    mvprintw(y - 6, x, "- o formato do comando deve ser \"<query-id>[format-flag] [arg1...argN]\"");
    mvprintw(y - 4, x, "Exemplos: \"1 <ID> \"; \"1S <ID>\"");
    mvprintw(y - 2, x, "Clique no 'W' para introduzir a query. Pressione 'Enter' quando terminar e no 'S' para avançar.");
    mvprintw(y - 1, x, "Caso se tenha enganado, clique no 'Enter' quando acabar de escrever e clique no 'W' para reescrever a query.");
    attroff(COLOR_PAIR(branco_preto));

    // Atualiza a tela
    refresh();
}

void menu_erro_query(int x, int y, int ncols, int nrows, int branco, int branco_preto)
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
    const char *mensagem = "O query introduzido não respeita o formato estipulado!";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 2, x, "%s", mensagem);
    mvprintw(y - 1, x, "Certifique-se de respeitar o formato.");
    attroff(COLOR_PAIR(branco_preto));

    // Atualiza a tela
    refresh();
}