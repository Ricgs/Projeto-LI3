#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "entidades/artistas.h"
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "queries/query2.h"
#include "manager_dados/manager_artistas.h"
#include "manager_dados/manager_musicas.h"
#include "manager_dados/manager_historicos.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "modos_execucao/modo_batch.h"
#include "utils/calculos.h"
#include "catalogos/list.h"
/*
char *execute_query6(char *args, GHashTable *utilizadores, GHashTable *album, GHashTable *artistas, GHashTable *musicas) {
    char *user_id = NULL; // Para armazenar o user_id
    char *year = NULL;    // Para armazenar o ano
    int N = 0;            // Para armazenar o número opcional de artistas (se fornecido)
    char *result = NULL;  // Para armazenar o resultado da consulta
    
    // Parsing dos argumentos
    char *arg = strtok(args, " "); // Pega o primeiro argumento (user_id)
    if (arg) {
        user_id = strdup(arg); // Aloca e copia o user_id
    }

    arg = strtok(NULL, " "); // Pega o segundo argumento (year)
    if (arg) {
        year = strdup(arg); // Aloca e copia o ano
    }

    arg = strtok(NULL, " "); // Pega o terceiro argumento (N)
    if (arg) {
        // Caso o argumento seja um número, converte e atribui a N
        if (isdigit(arg[0])) {
            N = atoi(arg); // Converte de string para int
        }
    }

    // Verificar se temos todos os dados necessários
    if (user_id == NULL || year == NULL) {
        return NULL; // Se user_id ou year estiverem ausentes, retorna NULL (erro ou falta de dados)
    }

    // Agora chamamos a função da query6 passando os parâmetros extraídos
    result = historico_anual(user_id, utilizadores, album, artistas, musicas, year, N);
    free(user_id);
    free(year);

    return result;
}
*/