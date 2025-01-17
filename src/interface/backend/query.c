#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>
#include <glib.h>

#include "interface/backend/inicial.h"
#include "interface/frontend/menu_inicial.h"
#include "interface/backend/query.h"
#include "interface/frontend/menu_query.h"
#include "interface/backend/output.h"

#include "manager_dados/manager_artistas.h"

#include "modos_execucao/modo_interativo.h"
#include "utils/calculos.h"
#include "queries/querier.h"

void programa_queries(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    // Inicializa uma string para armazenar a entrada do usuário
    char* input = (char*)malloc(sizeof(char) * 100);
    input[0] = '\0';

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_queries(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_inicial(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

            case 'w':
            case 'W': 
                fundo_preto(ncols, nrows, preto);
                menu_queries(x, y, ncols, nrows, branco, branco_preto);
                move(nrows / 2 + 2, ncols / 2 - 30);
                escreve(ncols, nrows, input, branco_preto);

                move(nrows / 2 + 6, ncols / 4);
                attron(COLOR_PAIR(branco_preto));
                printw("%s", input);
                attroff(COLOR_PAIR(branco_preto));

                //aqui o input tem o comando que vai ser processado
                break;
            
            case 's':
            case 'S':
                if (input[0] == '\0')
                {
                    programa_erro_query(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                }
                else if(verificarFormato(input) == 1)
                {
                    programa_erro_query(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                    free(input);
                }
                else
                {
                    exec_line(utilizadores, artistas, musicas, albums, historicos, list, input, command);
                    programa_output(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                    free(input);
                }
                break;
        }
    }
}

void programa_erro_query(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;
    clear();
    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_erro_query(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_queries(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}
