#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "modos_execucao/modo_interativo.h"

#include "interface/backend/inicial.h"
#include "interface/backend/ajuda.h"
#include "interface/backend/path.h"

#include "interface/frontend/menu_inicial.h"
#include "interface/frontend/menu_ajuda.h"
#include "interface/frontend/menu_path.h"

#include "manager_dados/manager_artistas.h"

#include "utils/calculos.h"

void programa_path(int ncols, int nrows, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command)
{
    int x = 0, y = 0;

    // Inicializa uma string para armazenar a entrada do usuário
    char* input = (char*)malloc(sizeof(char) * 100);
    input[0] = '\0';

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_path(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 27: // esc
                endwin();
                exit(0);
                break;

            case 'w':
            case 'W': 
                fundo_preto(ncols, nrows, preto);
                menu_path(x, y, ncols, nrows, branco, branco_preto);
                move(nrows / 2 + 2, ncols / 2 - 30);
                escreve(ncols, nrows, input, branco_preto);

                /*move(nrows / 2 + 6, ncols / 4);
                attron(COLOR_PAIR(branco_preto));
                printw("Aguarde...");
                attroff(COLOR_PAIR(branco_preto));*/

                //aqui o input tem o path que vai ser seguido
                break;
            
            case 's':
            case 'S':
            
                move(nrows / 2 + 6, ncols / 2);
                attron(COLOR_PAIR(branco_preto));
                printw("Aguarde...");
                attroff(COLOR_PAIR(branco_preto));
                
                refresh();
                
                if (input[0] == '\0'){
                    strcpy(input, "dataset-errors");
                    criar_hashtables(utilizadores, artistas, musicas, albums, historicos, input);
                    List *art_disc = top_artists(musicas, artistas);
                    programa_inicial(ncols, nrows, input, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, art_disc);
                }
                else {
                    DIR *testar = opendir(input); 
                    if (testar == NULL)
                    {
                        programa_erro_path(ncols, nrows, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command);
                        free(input);
                    }
                    else
                    {
                        criar_hashtables(utilizadores, artistas, musicas, albums, historicos, input);
                        List *art_disc = top_artists(musicas, artistas);
                        programa_inicial(ncols, nrows, input, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, art_disc);
                        free(input);
                    }
                }
                break;
        }
    }
}

void programa_erro_path(int ncols, int nrows, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command)
{
    int x = 0, y = 0;
    clear();
    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_erro_path(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_path(ncols, nrows, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command);
                break;

        }
    }
}
