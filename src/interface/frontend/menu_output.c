#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdbool.h>
#include <glib.h>

#include "interface/frontend/menu_output.h"
#include "utils/calculos.h"

void menu_output(int x, int y, int ncols, int nrows, char *path, int preto, int branco, int branco_preto, int command, int line)
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

    
    char nomeArquivo[100];
    sprintf(nomeArquivo, "resultados/command%d_output.txt", command);
    FILE *output = fopen(nomeArquivo, "r");
    char linha[256];
    x = ncols / 15;
    y = nrows / 6;


    fseek(output, 0, SEEK_SET);
    int contagem = 0;
    int caractere;
    while ((caractere = fgetc(output)) != EOF) {
        if (caractere == '\n') {
            contagem++;
        }
    }
    rewind(output);

    for (int i = 1; i < line; ++i) {
        if (fgets(linha, sizeof(linha), output) == NULL) {
            perror("Erro ao posicionar o ponteiro de arquivo");
            fclose(output);
            return;
        }
    }

    while (fgets(linha, sizeof(linha), output) != NULL) 
    {
        char *token = strtok(linha, "\n");
        attron(COLOR_PAIR(branco_preto));
        mvprintw(y, x, "%s", token);
        attroff(COLOR_PAIR(branco_preto));
        y++;
        line++;
    }

    fclose(output);
    // Atualiza a tela
    refresh();
}
