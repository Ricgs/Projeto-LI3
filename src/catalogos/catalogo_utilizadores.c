#include <glib.h>
#include "entidades/utilizadores.h"
#include "catalogos/catalogo_utilizadores.h"


GHashTable* create_utilizadores_catalog() 
{
  GHashTable *catalogo_utilizadores = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_utilizador);
  return catalogo_utilizadores;
}

void insert_utilizador(GHashTable *catalogo, UTILIZADOR utilizador, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo, key_dup, GINT_TO_POINTER(utilizador));
}

UTILIZADOR get_utilizador_by_key(GHashTable *catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo, key);
}

void update_utilizador(GHashTable *catalogo, char *key, UTILIZADOR utilizador)
{
  g_hash_table_replace (catalogo,key,GINT_TO_POINTER(utilizador));
}

void free_utilizador_catalog(GHashTable *catalogo) 
{
  g_hash_table_destroy(catalogo);
}