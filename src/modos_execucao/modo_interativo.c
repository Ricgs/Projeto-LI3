#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#include"entidades/albums.h"
#include"entidades/artistas.h"
#include"entidades/historicos.h"
#include"entidades/musicas.h"
#include"entidades/utilizadores.h"

#include"catalogos/catalogo_albums.h"
#include"catalogos/catalogo_artistas.h"
#include"catalogos/catalogo_historicos.h"
#include"catalogos/catalogo_musicas.h"
#include"catalogos/catalogo_utilizadores.h"

#include "manager_dados/manager_utilizadores.h"
#include "manager_dados/manager_artistas.h"
#include "manager_dados/manager_musicas.h"
#include "manager_dados/manager_albums.h"
#include "manager_dados/manager_historicos.h"

#include "modos_execucao/modo_interativo.h"
#include "interface/backend/path.h"
#include "interface/frontend/menu_path.h"

//SECÇÃO HASHTABLES
void criar_hashtables(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, char* path)
{
    //PARA LER O USERS.CSV
    size_t tamanho_utilizadores = strlen(path) + strlen("users.csv");
    char *utilizadores_path = malloc(tamanho_utilizadores + sizeof(char) + 1);
    if (utilizadores_path == NULL) printf("Falha\n");
    strcpy(utilizadores_path, path);
    strcat(utilizadores_path, "/users.csv");
    FILE *utilizadores_file = fopen(utilizadores_path, "r"); 
    if (utilizadores_file == NULL) perror("Falha");

    //PARA LER O ARTISTS.CSV
    size_t tamanho_artistas = strlen(path) + strlen("artists.csv");
    char *artistas_path = malloc(tamanho_artistas + sizeof(char) + 1);
    if (artistas_path == NULL) printf("Falha\n");
    strcpy(artistas_path, path);
    strcat(artistas_path, "/artists.csv");
    FILE *artistas_file = fopen(artistas_path, "r"); 
    if (artistas_file == NULL) perror("Falha");

    //PARA LER O MUSICS.CSV
    size_t tamanho_musicas = strlen(path) + strlen("musics.csv");
    char *musicas_path = malloc(tamanho_musicas + sizeof(char) + 1);
    if (musicas_path == NULL) printf("Falha\n");
    strcpy(musicas_path, path);
    strcat(musicas_path, "/musics.csv");
    FILE *musicas_file = fopen(musicas_path, "r"); 
    if (musicas_file == NULL) perror("Falha");

    //PARA LER O ALBUMS.CSV
    size_t tamanho_albums = strlen(path) + strlen("albums.csv");
    char *albums_path = malloc(tamanho_albums + sizeof(char) + 1);
    if (albums_path == NULL) printf("Falha\n");
    strcpy(albums_path, path);
    strcat(albums_path, "/albums.csv");
    FILE *albums_file = fopen(albums_path, "r"); 
    if (albums_file == NULL) perror("Falha");

    //PARA LER O HISTORY.CSV
    size_t tamanho_historico = strlen(path) + strlen("history.csv");
    char *historico_path = malloc(tamanho_historico + sizeof(char) + 1);
    if (historico_path == NULL) printf("Falha\n");
    strcpy(historico_path, path);
    strcat(historico_path, "/history.csv");
    FILE *historico_file = fopen(historico_path, "r"); 
    if (historico_file == NULL) perror("Falha");

    set_artista(artistas, artistas_file);
    set_album(albums, albums_file);
    set_musica(musicas, musicas_file, artistas, albums);
    set_utilizador(utilizadores, utilizadores_file, musicas);
    set_historico(historicos, utilizadores, musicas, historico_file);
}

void escreve(int ncols, int nrows, char* input, int branco_preto)
{
    input[0] = '\0';
    bool loop = true;
    while(loop)
    {
        int tecla = getch();
        char tecla_str[2];
        sprintf(tecla_str, "%c", tecla);
        strcat(input, tecla_str);
        attron(COLOR_PAIR(branco_preto));
        printw("%c", tecla);
        attroff(COLOR_PAIR(branco_preto));

        switch (tecla) 
        {
            default: 
                
                break;

            case 13: // enter
                input[strlen(input)-1] = '\0';
                loop = false;
                break;
        }
    }
}

void exec_interactive_mode()
{
    //////////////////////MENU DE INTERAÇÃO/////////////////////////////////

    WINDOW *wnd = initscr();
    int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

    //ATIVAÇÃO DE NCURSES
    start_color(); // habilita o uso de cores
	cbreak(); // lê uma tecla sem ter de pressionar Enter
	noecho(); // não exibe os caracteres lidos pelo programa
	nonl(); // faz o enter agir como qualquer outra tecla
	intrflush(stdscr, false); // desativa a captura da tecla de interrupção pelo programa
	keypad(stdscr, true); // ativa a captura de teclas especiais
	curs_set(0); // desativa o piscar do cursor

    //PALETE DE CORES (nome, R, G, B)
    init_color(99, 500, 500, 500); //cinzento
    init_color(98, 200, 200, 200); //cinzento-escuro
    init_color(97, 0, 0, 0); //preto
    init_color(96, 92, 51, 23); //castanho-escuro
    init_color(95, 205, 133, 63); //castanho
    init_color(94, 1000, 1000, 0); //amarelo
	
    //PAR DE CORES (nome, cor da letra, cor de fundo)
    init_pair(1, 97, 97); //fundo do ecra
    init_pair(2, COLOR_WHITE, COLOR_WHITE); //bordas do ecra
    init_pair(3, COLOR_WHITE, 97); //letra->branca    fundo->preto

    //Criação das Hastables
    GHashTable *utilizadores_hashtable = create_utilizadores_catalog();
    GHashTable *musicas_hashtable = create_musicas_catalog();
    GHashTable *artistas_hashtable = create_artistas_catalog();
    GHashTable *albums_hashtable = create_albums_catalog();
    GHashTable *historicos_hashtable = create_historicos_catalog();

    int command = 1; //número do primeiro input

    programa_path(ncols, nrows, 1, 2, 3, utilizadores_hashtable, artistas_hashtable, musicas_hashtable, albums_hashtable, historicos_hashtable, command);
}
