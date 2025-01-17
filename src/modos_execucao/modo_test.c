#include <stdio.h>
#include <stdlib.h>

#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "entidades/artistas.h"
#include "entidades/albums.h"
#include "entidades/historicos.h"

#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/catalogo_albums.h"
#include "catalogos/catalogo_historicos.h"

#include "modos_execucao/modo_batch.h"
#include <string.h>
#include "manager_dados/parser.h"
#include "queries/querier.h"

#include "manager_dados/manager_utilizadores.h"
#include "manager_dados/manager_artistas.h"
#include "manager_dados/manager_musicas.h"
#include "manager_dados/manager_albums.h"
#include "manager_dados/manager_historicos.h"
#include "modos_execucao/modo_test.h"
#include "queries/querier_test.h"
#include "teste/comparacao.h"
#include <time.h>
#include <sys/resource.h>



void exec_test_mode(char* path, char* comandos, char* resultados_esperados)
{
    clock_t start, end;
    double cpu_time_used;
    double *q1 = malloc(sizeof(double));
    double *q2 = malloc(sizeof(double));
    double *q3 = malloc(sizeof(double));

    start = clock();

    GHashTable *utilizadores_hashtable = create_utilizadores_catalog();
    GHashTable *musicas_hashtable = create_musicas_catalog();
    GHashTable *artistas_hashtable = create_artistas_catalog();
    GHashTable *albums_hashtable = create_albums_catalog();
    GHashTable *historicos_hashtable = create_historicos_catalog();

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

    FILE *qs = fopen(comandos, "r");
    if (qs == NULL) perror("Falha");
        
    set_artista(artistas_hashtable, artistas_file);
    set_album(albums_hashtable, albums_file);
    set_musica(musicas_hashtable, musicas_file, artistas_hashtable, albums_hashtable);
    set_utilizador(utilizadores_hashtable, utilizadores_file, musicas_hashtable);
    set_historico(historicos_hashtable, utilizadores_hashtable, musicas_hashtable, historico_file);
    List *art_disc = top_artists(musicas_hashtable, artistas_hashtable);

    querier_test(utilizadores_hashtable, artistas_hashtable, musicas_hashtable, albums_hashtable, historicos_hashtable, art_disc, qs, q1, q2, q3);

    
    listDestroy(art_disc);
    free_utilizador_catalog(utilizadores_hashtable);
    free_musica_catalog(musicas_hashtable);
    free_artista_catalog(artistas_hashtable);
    free_album_catalog(albums_hashtable);
    free_historico_catalog(historicos_hashtable);


    fclose(qs);
    fclose(musicas_file);
    fclose(artistas_file);
    fclose(utilizadores_file);

    free(musicas_path);
    free(artistas_path);
    free(utilizadores_path);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);

    size_t tamanho_resultados = strlen("resultados");
    char *resultados_path = malloc(tamanho_resultados + sizeof(char) + 1);
    strcpy(resultados_path, "resultados");

    compara(resultados_path, resultados_esperados, comandos);

    printf("Memória utilizada: %.0fMB\n", r_usage.ru_maxrss / 1024.0);
    printf("Tempos de execução:\n");
    printf("    Q1: %.1f ms\n", (*q1) * 1000);
    printf("    Q2: %.1f ms\n", (*q2) * 1000);
    printf("    Q3: %.1f ms\n", (*q3) * 1000);
    printf("Tempo total: %.0fs\n", cpu_time_used);


    free(q1);
    free(q2);
    free(q3);
}