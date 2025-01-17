#include <glib.h>
#include "entidades/musicas.h"
#include "catalogos/catalogo_musicas.h"

GHashTable *create_musicas_catalog()
{
  GHashTable *catalogo_musicas = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_musica);
  return catalogo_musicas;
}

void insert_musica(GHashTable *catalogo, MUSICA musica, char *key)
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo, key_dup, GINT_TO_POINTER(musica));
}

MUSICA get_musica_by_key(GHashTable *catalogo, char *key)
{
  return g_hash_table_lookup(catalogo, key);
}

void update_musica(GHashTable *catalogo, char *key, MUSICA musica)
{
  g_hash_table_replace(catalogo, key, GINT_TO_POINTER(musica));
}

void free_musica_catalog(GHashTable *catalogo)
{
  g_hash_table_destroy(catalogo);
}