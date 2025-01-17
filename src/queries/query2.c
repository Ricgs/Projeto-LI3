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
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "modos_execucao/modo_batch.h"
#include "utils/calculos.h"
#include "catalogos/list.h"



char* execute_query2(char *arg, List *list) {
    int N;
    char *country_filter = NULL;

    if (is_number(arg)) {
            N = atoi(arg);
    } else {
        country_filter = malloc(100);
        if (country_filter == NULL) {
            return NULL;
        }

        if (sscanf(arg, "%d \"%[^\"]\"", &N, country_filter) == 2) {} 
        else {
            printf("Failed to parse input\n");
            return NULL;
        }

    }

    if (N==0) {
        free(country_filter);
        return NULL;
    }

    char *top;
    if ( country_filter == NULL) 
        top = get_top_artists(list, N);
    else
        top = get_top_artists_country(list, N, country_filter);

    free(country_filter);
    return top;
}