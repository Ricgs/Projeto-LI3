#include "entidades/albums.h"
#include "catalogos/catalogo_albums.h"
#include "utils/calculos.h"
#include <glib.h>
#include <stdio.h>

struct albums
{
    char *id;
    char *title;
    GArray *artists_id;
    char *year;
    //GArray *producers;
};

ALBUM criar_album(void)
{
    ALBUM novo_album = malloc(sizeof(struct albums));
    novo_album->id = NULL;
    novo_album->title = NULL;
    novo_album->artists_id = g_array_new(FALSE, FALSE, sizeof(char *));
    novo_album->year = NULL;
    //novo_album->producers = g_array_new(FALSE, FALSE, sizeof(char *));
    
    return novo_album;
}

///nao encaplsulado
void construir_album(char *informacao, GHashTable *catalogo)
{

    char *id;
    char *title;
    GArray *artists_id = g_array_new(FALSE, FALSE, sizeof(char *));
    char *year;
    //GArray *producers = g_array_new(FALSE, FALSE, sizeof(char *));

    char **tokens = g_strsplit(informacao, ";", -1);

    id = g_strdup(tokens[0]);
    title = g_strdup(tokens[1]);
    char* artists_id_temp = g_strdup(tokens[2]);
    parse_A_U(artists_id, remove_aspas(artists_id_temp));
    year = g_strdup(tokens[3]);
    
    char *newline_pos = strchr(tokens[4], '\n');
    if (newline_pos) *newline_pos = '\0';
    //char* producers_temp = g_strdup(tokens[4]);
    //parse_A_U(producers, remove_aspas(producers_temp));   

    ALBUM album = criar_album();

    set_album_id(album, remove_aspas(id));
    set_al_title(album, remove_aspas(title));
    set_artists_id(album, artists_id);
    set_al_year(album, remove_aspas(year));
    //set_producers(album, producers);

    insert_album(catalogo, album, album->id);
    
    free(id);
    free(title);
    g_array_free(artists_id,  TRUE);
    free(artists_id_temp);
    free(year);
    //g_array_free(producers,  TRUE);
    //free(producers_temp);
    g_strfreev(tokens); 
}
///nao encapsulado

//----------------ID-----------------
char *get_album_id(ALBUM album)
{
    return strdup(album->id);
}

void set_album_id(ALBUM album, char *value)
{
    free(album->id);
    album->id = strdup(value);
}

//----------------TITLE-----------------
char *get_al_title(ALBUM album)
{
    return strdup(album->title);
}

void set_al_title(ALBUM album, char *value)
{
    free(album->title);
    album->title = strdup(value);
}

//--------------ARTISTS ID-----------------
GArray *get_artists_id(ALBUM album)
{
    GArray *artists_id_copy = g_array_new(FALSE, FALSE, sizeof(char*));

    for (guint i = 0; i < album->artists_id->len; i++) {
        char *id = g_array_index(album->artists_id, char*, i);
        g_array_append_val(artists_id_copy, id);
    }

    return artists_id_copy;
}

void set_artists_id(ALBUM album, GArray *value)
{
    if (album->artists_id != NULL) {
        g_array_free(album->artists_id, TRUE);
    }
    
    album->artists_id = g_array_sized_new(FALSE, FALSE, sizeof(char *), value->len);
    for (guint i = 0; i < value->len; i++) {
        char *id = g_array_index(value, char*, i);
        g_array_append_val(album->artists_id, id);
    }
}

//--------------YEAR-----------------
char *get_al_year(ALBUM album)
{
    return strdup(album->year);
}

void set_al_year(ALBUM album, char *value)
{
    free(album->year);
    album->year = strdup(value);
}

//--------------PRODUCERS-----------------
/*GArray *get_producers(ALBUM album)
{
    GArray *producers_copy = g_array_new(FALSE, FALSE, sizeof(char*));

    for (guint i = 0; i < album->producers->len; i++) {
        char *id = g_array_index(album->producers, char*, i);
        g_array_append_val(producers_copy, id);
    }

    return producers_copy;
}

void set_producers(ALBUM album, GArray *value)
{
    if (album->producers != NULL) {
        g_array_free(album->producers, TRUE);
    }
    
    album->producers = g_array_sized_new(FALSE, FALSE, sizeof(char *), value->len);
    for (guint i = 0; i < value->len; i++) {
        char *id = g_array_index(value, char*, i);
        g_array_append_val(album->producers, id);
    }
}
*/
void destroi_album(gpointer data)
{
    ALBUM album = (ALBUM)data;

    free(album->id);
    free(album->title);
    for (guint i = 0; i < album->artists_id->len; i++) {
        char *id = g_array_index(album->artists_id, char*, i);
        free(id);
    }
    g_array_free(album->artists_id, TRUE);
    free(album->year);
    /*for (guint i = 0; i < album->producers->len; i++) {
        char *id = g_array_index(album->producers, char*, i);
        free(id);
    }
    g_array_free(album->producers, TRUE);
    */
    free(album);
}
