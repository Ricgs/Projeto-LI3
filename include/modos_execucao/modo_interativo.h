#ifndef MODO_INTERATIVO_H
#define MODO_INTERATIVO_H

#include <glib.h>

/**
 @brief cria as hashtables para o modo interativo
 
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param musicas - Tabela hash de músicas
 @param albums - Tabela hash de álbuns
 @param historicos - Tabela hash de históricos
 @param path - O caminho para os ficheiros .csv
*/
void criar_hashtables(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, char* path);

/**
 @brief escreve no ecrã com cores definidas
 
 @param ncols - Número de colunas
 @param nrows - Número de linhas
 @param input - String de entrada
 @param branco_preto - Configuração de cor
*/
void escreve(int ncols, int nrows, char* input, int branco_preto);

/**
 @brief executa o modo interativo
*/
void exec_interactive_mode();

#endif
