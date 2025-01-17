#ifndef QUERIER_TEST_H
#define QUERIER_TEST_H

#include <stdio.h>
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/list.h"

/**
 @brief executa uma linha de teste de query
 
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param musicas - Tabela hash de músicas
 @param albums - Tabela hash de álbuns
 @param historicos - Tabela hash de históricos
 @param list - Lista de artistas
 @param linha - A linha com o comando e os argumentos
 @param count - Número da linha do comando
 @param q1 - Tempo acumulado para queries tipo 1
 @param q2 - Tempo acumulado para queries tipo 2
 @param q3 - Tempo acumulado para queries tipo 3
*/
void exec_line_test(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, char *linha, int count, double *q1, double *q2, double *q3);

/**
 @brief executa o processo de teste para múltiplas queries
 
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param musicas - Tabela hash de músicas
 @param albums - Tabela hash de álbuns
 @param historicos - Tabela hash de históricos
 @param list - Lista de artistas
 @param input - Ficheiro com os comandos de teste
 @param q1 - Tempo acumulado para queries tipo 1
 @param q2 - Tempo acumulado para queries tipo 2
 @param q3 - Tempo acumulado para queries tipo 3
*/
void querier_test(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, FILE *input, double *q1, double *q2, double *q3);

#endif
