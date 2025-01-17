#ifndef PATH_H
#define PATH_H

#include <glib.h>

/**
 * @brief Executa o programa para definir o caminho (path).
 * 
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param preto Cor preta na interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 * @param utilizadores Hash table dos utilizadores.
 * @param artistas Hash table dos artistas.
 * @param musicas Hash table das músicas.
 * @param albums Hash table dos álbuns.
 * @param historicos Hash table dos históricos.
 * @param command Número do comando atual.
 */
void programa_path(int ncols, int nrows, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command);

/**
 * @brief Executa o programa para lidar com erros de definição do caminho.
 * 
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param preto Cor preta na interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 * @param utilizadores Hash table dos utilizadores.
 * @param artistas Hash table dos artistas.
 * @param musicas Hash table das músicas.
 * @param albums Hash table dos álbuns.
 * @param historicos Hash table dos históricos.
 * @param command Número do comando atual.
 */
void programa_erro_path(int ncols, int nrows, int preto, int branco, int branco_preto, GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, int command);

#endif
