#ifndef QUERIER_H
#define QUERIER_H

#include <stdio.h>
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/list.h"

/**
 @brief executa uma linha de comando de query
 
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param musicas - Tabela hash de músicas
 @param albums - Tabela hash de álbuns
 @param historicos - Tabela hash de históricos
 @param list - Lista de artistas
 @param linha - A linha com o comando e os argumentos
 @param count - Número da linha do comando
*/
void exec_line(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, char *linha, int count);

/**
 @brief executa o processo de queries a partir de um ficheiro de entrada
 
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param musicas - Tabela hash de músicas
 @param albums - Tabela hash de álbuns
 @param historicos - Tabela hash de históricos
 @param list - Lista de artistas
 @param input - Ficheiro com os comandos das queries
*/
void querier(GHashTable *utilizadores, GHashTable *artistas, GHashTable *musicas, GHashTable *albums, GHashTable *historicos, List *list, FILE *input);

#endif
