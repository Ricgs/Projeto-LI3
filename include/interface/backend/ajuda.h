#ifndef AJUDA_H
#define AJUDA_H

#include <glib.h>
#include "manager_dados/manager_artistas.h"

/**
 * @brief Executa o programa de ajuda.
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
void programa_ajuda(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 1.
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
void programa_query1(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 2.
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
void programa_query2(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 3.
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
void programa_query3(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 4.
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
void programa_query4(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 5.
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
void programa_query5(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

/**
 * @brief Executa o programa para a query 6.
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
void programa_query6(int ncols, int nrows, char* path, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command, List *list);

#endif
