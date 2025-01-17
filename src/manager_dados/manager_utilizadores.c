#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/utilizadores.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_utilizadores.h"

/*
void set_utilizador(GHashTable *utilizadores, FILE *file, GHashTable *musicas) {
    char *erros_utilizadores = cria_erros("resultados/users_errors.csv");
    FILE *pasta_erros_utilizadores = cria_ficheiro(erros_utilizadores);

    char **linhas = NULL;
    int n = ler_ficheiro(file, &linhas);  

    for (int i = 0; i < n; i++) {
        if (utilizador_valido(linhas[i], musicas) == 1)
            construir_utilizador(linhas[i], utilizadores);
        else
            fprintf(pasta_erros_utilizadores, "%s", linhas[i]);
    }

    for (int i = 0; i < n; i++) {
        free(linhas[i]);  
    }
    free(linhas);  
    free(erros_utilizadores); 
    fclose(pasta_erros_utilizadores);  
}
*/

void processa_linha_utilizador(GHashTable *utilizadores, GHashTable *musicas, FILE *pasta_erros_utilizadores, char *linha) {
    if (utilizador_valido(linha, musicas) == 1)
        construir_utilizador(linha, utilizadores);
    else
        fprintf(pasta_erros_utilizadores, "%s", linha);
}

void set_utilizador(GHashTable *utilizadores, FILE *file, GHashTable *musicas) {
    char *erros_utilizadors = cria_erros("resultados/users_errors.csv");
    FILE *pasta_erros_utilizadors = cria_ficheiro(erros_utilizadors);

    char *linha;
    while ((linha = ler_linha(file)) != NULL) {
        processa_linha_utilizador(utilizadores, musicas, pasta_erros_utilizadors, linha);
        free(linha);
    }
    free(erros_utilizadors);
    fclose(pasta_erros_utilizadors);
}



