#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "modos_execucao/modo_interativo.h"

#include "interface/backend/inicial.h"
#include "interface/backend/ajuda.h"
#include "interface/backend/query.h"

#include "interface/frontend/menu_inicial.h"
#include "interface/frontend/menu_ajuda.h"
#include "interface/frontend/menu_query.h"

#include "manager_dados/manager_artistas.h"

#include "utils/calculos.h"

void programa_inicial(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    fundo_preto(ncols, nrows, preto);

    while(1)
    {
        menu_inicial(ncols, nrows, branco, branco_preto);

        int tecla = getch();

        switch (tecla) 
        {
            default: break;

            case 27: // esc
                endwin();
                exit(0);
                break;

            case 'i':
            case 'I':
                programa_queries(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
            break;
            
            case 'h':
            case 'H':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;
        }
    }
}
