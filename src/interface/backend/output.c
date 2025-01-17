#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "modos_execucao/modo_interativo.h"

#include "interface/backend/inicial.h"
#include "interface/backend/ajuda.h"
#include "interface/backend/output.h"

#include "interface/frontend/menu_inicial.h"
#include "interface/frontend/menu_ajuda.h"
#include "interface/frontend/menu_output.h"

#include "manager_dados/manager_artistas.h"

#include "utils/calculos.h"

void programa_output(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;
    int line = 1;
    fundo_preto(ncols, nrows, preto);

    while(1)
    {
        menu_output(x, y, ncols, nrows, path, preto, branco, branco_preto, command, line);

        int tecla = getch();

        switch (tecla) 
        {
            default: break;
            
            case 'v':
            case 'V':
                command++;
                programa_inicial(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;
        }
    }
}
