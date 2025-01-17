#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/albums.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_albums.h"
/*

void set_album(GHashTable *albums, FILE *file) {
    char **linhas = NULL;
    int n = ler_ficheiro(file, &linhas);  

    for (int i = 0; i < n; i++) {
        construir_album(linhas[i], albums);
    }

    guint tamanho = g_hash_table_size(albums);
    printf("Tamanho de álbums: %u\n", tamanho);

    for (int i = 0; i < n; i++) {
        free(linhas[i]); 
    }
    free(linhas); 
}
*/

void processa_linha_album(GHashTable *albums, char *linha) {
    construir_album(linha, albums);
}

void set_album(GHashTable *albums, FILE *file) {
    char *linha;
    while ((linha = ler_linha(file)) != NULL) {
        processa_linha_album(albums, linha);
        free(linha);
    }
}