#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/musicas.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_musicas.h"

/*
void set_musica(GHashTable *musicas, FILE *file, GHashTable *musica, GHashTable *albums) {
    char *erros_musicas = cria_erros("resultados/musics_errors.csv");
    FILE *pasta_erros_musicas = cria_ficheiro(erros_musicas);

    char **linhas = NULL;
    int n = ler_ficheiro(file, &linhas);  

    for (int i = 0; i < n; i++) {
        if (musica_valida(linhas[i], musica, albums) == 1)
            construir_musica(linhas[i], musicas);
        else
            fprintf(pasta_erros_musicas, "%s", linhas[i]);
    }

    guint tamanho = g_hash_table_size(musicas);
    printf("Tamanho de músicas: %u\n", tamanho);

    for (int i = 0; i < n; i++) {
        free(linhas[i]); 
    }
    free(linhas); 
    free(erros_musicas); 
    fclose(pasta_erros_musicas); 
}

*/


void processa_linha_musica(GHashTable *musicas, GHashTable *musica, GHashTable *albums, FILE *pasta_erros_musicas, char *linha) {
    if (musica_valida(linha, musica, albums) == 1)
        construir_musica(linha, musicas);
    else
        fprintf(pasta_erros_musicas, "%s", linha);
}

void set_musica(GHashTable *musicas, FILE *file, GHashTable *musica, GHashTable *albums) {
    char *erros_musicas = cria_erros("resultados/musics_errors.csv");
    FILE *pasta_erros_musicas = cria_ficheiro(erros_musicas);

    char *linha;
    while ((linha = ler_linha(file)) != NULL) {
        processa_linha_musica(musicas, musica, albums, pasta_erros_musicas, linha);
        free(linha);
    }
    free(erros_musicas);
    fclose(pasta_erros_musicas);
}

