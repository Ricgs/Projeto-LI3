#ifndef QUERY1_H
#define QUERY1_H

#include <stdbool.h>
#include <stdio.h>

/**
 @brief calcula a idade com base na data de nascimento
 
 @param birth_date - A data de nascimento
 @return A idade calculada
*/
int calcular_idade(char* birth_date);

/**
 @brief função auxiliar para contar álbuns de um artista
 
 @param key - A chave do álbum
 @param value - O valor do álbum
 @param user_data - Dados do artista
*/
void aux1(gpointer key, gpointer value, gpointer user_data);

/**
 @brief executa a query 1
 
 @param numlinha - O número da linha do comando
 @param arg - O argumento da query
 @param utilizadores - Tabela hash de utilizadores
 @param artistas - Tabela hash de artistas
 @param albums - Tabela hash de álbuns
 @return O resultado da query como string
*/
char* execute_query1(int numlinha, char *arg, GHashTable *utilizadores, GHashTable *artistas, GHashTable *albums);

#endif
