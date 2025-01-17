#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "entidades/artistas.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "queries/querier_test.h"
#include "queries/query1.h"
#include "queries/query2.h"
#include "queries/query3.h"
#include <time.h>
#include "catalogos/list.h"
#include "escrita/escritor.h"

void querier_test(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, FILE *input, double *q1, double *q2, double *q3)
{
    int count = 1;
    char linha[1024];
    while (fgets(linha, sizeof(linha), input) != NULL) 
    {
        exec_line_test(utilizadores, artistas, musicas, albums, historicos, list, linha, count, q1, q2, q3);
        count++;
    }
}

void exec_line_test(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, char *linha, int count, double *q1, double *q2, double *q3)
{
    clock_t start, end;
    linha[strcspn(linha, "\n")] = '\0';
    char *query, *args;
    query = strsep(&linha, " ");
    args = (linha != NULL) ? linha : "";
    if(strcmp(query, "1") == 0 || strcmp(query, "1S") == 0 )
    {
        start = clock();
        char *resultado = execute_query1(count, args, utilizadores, artistas, albums);
        if (strcmp(query, "1S")== 0) {
            write_result(count, 1, resultado);
        } else {
            write_result(count, 0, resultado);
        }
        end = clock();
        *q1 += ((double) (end - start)) / CLOCKS_PER_SEC;
    } 
    else if(strcmp(query, "2") == 0 || strcmp(query, "2S") == 0 )
    {
        start = clock();
        char *resultado = execute_query2(args, list);
        if (strcmp(query, "2S")== 0) {
            write_result(count, 1, resultado);
        } else {
            write_result(count, 0, resultado);
        }
        end = clock();
        *q2 += ((double) (end - start)) / CLOCKS_PER_SEC;
    }
    else if(strcmp(query, "3") == 0 || strcmp(query, "3S") == 0 )
    {
        start = clock();
        char *resultado = execute_query3(count, args, utilizadores, musicas);
        if (strcmp(query, "3S")== 0) {
            write_result(count, 1, resultado);
        } else {
            write_result(count, 0, resultado);
        }
        end = clock();
        *q3 += ((double) (end - start)) / CLOCKS_PER_SEC;
    }
}
