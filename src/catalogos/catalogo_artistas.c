#include <glib.h>
#include "entidades/artistas.h"
#include "catalogos/catalogo_artistas.h"


GHashTable* create_artistas_catalog() 
{
  GHashTable *catalogo_artistas = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_artista);
  return catalogo_artistas;
}

void insert_artista(GHashTable *catalogo, ARTISTA artista, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo, key_dup, GINT_TO_POINTER(artista));
}

ARTISTA get_artista_by_key(GHashTable *catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo, key);
}

void update_artista(GHashTable *catalogo, char *key, ARTISTA artista)
{
  g_hash_table_replace (catalogo,key,GINT_TO_POINTER(artista));
}

void free_artista_catalog(GHashTable *catalogo) 
{
  g_hash_table_destroy(catalogo);
}