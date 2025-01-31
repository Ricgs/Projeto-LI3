#include <glib.h>
#include "entidades/albums.h"

#ifndef CATALOGO_ALBUMS_H
#define CATALOGO_ALBUMS_H

typedef struct catalogo *CATALOGO;

CATALOGO create_catalogo_albums();

/**
 @brief Cria o catálogo para os albums
 
 @param 
 
 @return Dá return do catálogo dos albums
*/
GHashTable* create_albums_catalog();

/**
 @brief Insere um album no catálogo
 
 @param catalogo - O catalogo do tipo 'GHashTable'
 @param album - O album do tipo 'ALBUM'
 @param key - O id do tipo 'cha'
 
 @return 
*/
void insert_album(CATALOGO catalogo, ALBUM album, char *key);

/**
 @brief Vai buscar o album ao catálogo
 
 @param catalogo - O catalogo do tipo 'GHashTable'
 @param key - O id do tipo 'cha'
 
 @return album pretendido
*/
ALBUM get_album_by_key(CATALOGO catalogo, char *key);

/**
 @brief atualiza o album na tabela na key especificada
 
 @param catalogo - O catalogo do tipo 'GHashTable'
 @param album - O album do tipo 'ALBUM'
 @param key - O id do tipo 'cha'
 
 @return 
*/
void update_album(CATALOGO catalogo, char *key, ALBUM album);

/**
 @brief destrói a hash table
 
 @param catalogo - O catalogo do tipo 'GHashTable'
 
 @return 
*/
void free_album_catalog(CATALOGO catalogo);

void construir_album(char *informacao, CATALOGO catalogo);

#endif