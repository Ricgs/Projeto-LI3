#ifndef QUERY_H
#define QUERY_H

#include <glib.h>
#include "manager_dados/manager_artistas.h"

/**
 * @brief Executa o programa para as queries.
 * 
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param path Caminho atual do programa.
 * @param preto Cor preta na interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 * @param utilizadores Hash table dos utilizadores.
 * @param artistas Hash table dos artistas.
 * @param musicas Hash table das músicas.
 * @param albums Hash table dos álbuns.
 * @param historicos Hash table dos históricos.
 * @param command Número do comando atual.
 * @param list Lista associada à execução.
 */
void programa_queries(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para lidar com erros em queries.
 * 
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param path Caminho atual do programa.
 * @param preto Cor preta na interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 * @param utilizadores Hash table dos utilizadores.
 * @param artistas Hash table dos artistas.
 * @param musicas Hash table das músicas.
 * @param albums Hash table dos álbuns.
 * @param historicos Hash table dos históricos.
 * @param command Número do comando atual.
 * @param list Lista associada à execução.
 */
void programa_erro_query(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

#endif
