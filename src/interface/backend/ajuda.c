#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "modos_execucao/modo_interativo.h"
#include "interface/backend/inicial.h"
#include "interface/backend/ajuda.h"
#include "interface/frontend/menu_inicial.h"
#include "interface/frontend/menu_ajuda.h"
#include "utils/calculos.h"
#include "manager_dados/manager_artistas.h"

void programa_ajuda(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_ajuda(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_inicial(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

            case '1':
                programa_query1(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;
            
            case '2':
                programa_query2(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

            case '3':
                programa_query3(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

            case '4':
                programa_query4(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;
            
            case '5':
                programa_query5(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

            case '6':
                programa_query6(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query1(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query1(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query2(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query2(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query3(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query3(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query4(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query4(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query5(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query5(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}

void programa_query6(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list)
{
    int x = 0, y = 0;

    fundo_preto(ncols, nrows, preto);
    while (1)
    {
        menu_query6(x, y, ncols, nrows, branco, branco_preto);
                
        int tecla = getch();
        
        switch (tecla) 
        {
            default:
            
                break;

            case 'v':
            case 'V':
                programa_ajuda(ncols, nrows, path, preto, branco, branco_preto, utilizadores, artistas, musicas, albums, historicos, command, list);
                break;

        }
    }
}
