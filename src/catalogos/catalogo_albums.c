#include <glib.h>
#include "entidades/albums.h"
#include "catalogos/catalogo_albums.h"


GHashTable* create_albums_catalog() 
{
  GHashTable *catalogo_albums = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_album);
  return catalogo_albums;
}

void insert_album(GHashTable *catalogo, ALBUM album, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo, key_dup, GINT_TO_POINTER(album));
}

ALBUM get_album_by_key(GHashTable *catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo, key);
}

void update_album(GHashTable *catalogo, char *key, ALBUM album)
{
  g_hash_table_replace (catalogo,key,GINT_TO_POINTER(album));
}

void free_album_catalog(GHashTable *catalogo) 
{
  g_hash_table_destroy(catalogo);
}