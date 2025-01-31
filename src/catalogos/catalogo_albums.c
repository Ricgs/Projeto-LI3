#include <glib.h>
#include "entidades/albums.h"
#include "catalogos/catalogo_albums.h"

struct catalogo {
  GHashTable *albums;
};

CATALOGO create_catalogo_albums(){
  CATALOGO catalogo = malloc(sizeof(struct catalogo));
  catalogo->albums= g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_album);
  return catalogo;
}


///nao encapsulado
GHashTable* create_albums_catalog() 
{
  GHashTable *catalogo_albums = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_album);
  return catalogo_albums;
}
///nao encapsulado


void insert_album(CATALOGO catalogo, ALBUM album, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo->albums, key_dup, GINT_TO_POINTER(album));
}

ALBUM get_album_by_key(CATALOGO catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo->albums, key);
}

void update_album(CATALOGO catalogo, char *key, ALBUM album)
{
  g_hash_table_replace (catalogo->albums,key,GINT_TO_POINTER(album));
}

void free_album_catalog(CATALOGO catalogo) 
{
  g_hash_table_destroy(catalogo->albums);
}

void construir_album(char *informacao, CATALOGO catalogo)
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