#ifndef QUERY3_H
#define QUERY3_H

#include <glib.h>

/**
 @brief função auxiliar para processar utilizadores e géneros musicais
 
 @param key - A chave do utilizador
 @param value - O valor do utilizador
 @param user_data - Dados adicionais (ex.: tabela de músicas e limites de idade)
*/
void aux(gpointer key, gpointer value, gpointer user_data);

/**
 @brief escreve os géneros musicais ordenados por popularidade
 
 @param result - A string onde os géneros serão escritos
 @param objetivos - Array com os géneros e suas contagens
*/
char *escrever_generos_ordenados(int objetivos[]);

/**
 @brief executa a query 3
 
 @param numlinha - O número da linha do comando
 @param arg - O argumento da query (idades mínimas e máximas)
 @param utilizadores - Tabela hash de utilizadores
 @param musicas - Tabela hash de músicas
 @return O resultado da query como string
*/
char* execute_query3(int numlinha, char *arg, GHashTable *utilizadores, GHashTable *musicas);

#endif
