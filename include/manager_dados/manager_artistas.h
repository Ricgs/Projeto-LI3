#ifndef MANAGER_ARTISTAS_H
#define MANAGER_ARTISTAS_H

#include "catalogos/list.h"

/**
 @brief adiciona artistas a partir de um ficheiro
 
 @param artistas - A tabela hash onde os artistas serão guardados
 @param file - O ficheiro com as informações dos artistas
*/
void set_artista(GHashTable *artistas, FILE *file);

/**
 @brief junta duas listas ordenadas
 
 @param a - A primeira lista
 @param b - A segunda lista
 @return A lista ordenada
*/
List *merge_sorted_lists(List *a, List *b);

/**
 @brief divide uma lista em duas
 
 @param source - A lista a ser dividida
 @param front - A primeira parte da lista
 @param back - A segunda parte da lista
*/
void split_list(List *source, List **front, List **back);

/**
 @brief ordena uma lista usando merge sort
 
 @param head - A lista a ser ordenada
 @return A lista ordenada
*/
List *merge_sort(List *head);

/**
 @brief ordena uma lista por duração da discografia
 
 @param head - A lista a ser ordenada
*/
void sort_by_discography_duration(List **head);

/**
 @brief encontra os artistas principais
 
 @param musicas - A tabela hash de músicas
 @param artistas - A tabela hash de artistas
 @return Uma lista dos artistas principais
*/
List *top_artists(GHashTable *musicas, GHashTable *artistas);

/**
 @brief obtém os principais artistas
 
 @param list - A lista de artistas
 @param N - O número de artistas a obter
 @return Uma string com os artistas principais
*/
char *get_top_artists(List *list, int N);

/**
 @brief obtém os principais artistas de um país
 
 @param list - A lista de artistas
 @param N - O número de artistas a obter
 @param country_filter - O país dos artistas
 @return Uma string com os artistas principais do país
*/
char *get_top_artists_country(List *list, int N, char *country_filter);

#endif
