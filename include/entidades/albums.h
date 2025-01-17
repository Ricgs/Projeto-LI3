#include <glib.h>

#ifndef ALBUM_H
#define ALBUM_H

/**
 * @brief Estrutura que representa um album.
 *
 * Contém informações sobre o ID, título, artistas que lançaram o album e ano.
 */
typedef struct albums
{
    char *id;
    char *title;
    GArray *artists_id;
    char *year;
    //GArray *producers;
} *ALBUM;

/**
 @brief Vai buscar o id do album
 
 @param album - O album do tipo 'ALBUM'
 
 @return id - O id do album do tipo 'char*'
*/
char *get_album_id(ALBUM album);
/**
 @brief Coloca o id do album
 
 @param album - O album do tipo 'ALBUM'
 @param value - O id do album do tipo 'char*'
*/
void set_album_id(ALBUM album, char *value);

/**
 @brief Vai buscar o título do album
 
 @param album - O album do tipo 'ALBUM'
 
 @return título - O título do album do tipo 'char*'
*/
char *get_al_title(ALBUM album);
/**
 @brief Coloca o titulo do album
 
 @param album - O album do tipo 'ALBUM'
 @param value - O id do album do tipo 'char*'
*/
void set_al_title(ALBUM album, char *value);

/**
 @brief Vai buscar os ids dos artistas do album
 
 @param album - O album do tipo 'ALBUM'
 
 @return artists_id - Os ids dos artistas do album do tipo 'GArray*'
*/
GArray *get_artists_id(ALBUM album);
/**
 @brief Coloca o id do artista do album
 
 @param album - O album do tipo 'ALBUM'
 @param value - O id do album do tipo 'GArray*'
*/
void set_artists_id(ALBUM album, GArray *value);

/**
 @brief Vai buscar o ano do album
 
 @param album - O album do tipo 'ALBUM'
 
 @return year - O ano do album do tipo 'char*'
*/
char *get_al_year(ALBUM album);
/**
 @brief Coloca o ano do album
 
 @param album - O album do tipo 'ALBUM'
 @param value - O id do album do tipo 'char*'
*/
void set_al_year(ALBUM album, char *value);

/**
 @brief Vai buscar os producers do album
 
 @param album - O album do tipo 'ALBUM'
 
 @return producers - Os producers do album do tipo 'GArray*'
*/
//GArray *get_producers(ALBUM album);
/**
 @brief Coloca os producers do album
 
 @param album - O album do tipo 'ALBUM'
 @param value - O id do album do tipo 'GArray*'
*/
//void set_producers(ALBUM album, GArray *value);

ALBUM criar_album(void);

void construir_album(char *informacao, GHashTable *catalogo);

void destroi_album(gpointer data);

#endif