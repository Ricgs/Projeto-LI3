#include <glib.h>
#include "entidades/historicos.h"
#include "catalogos/catalogo_historicos.h"


GHashTable* create_historicos_catalog() 
{
  GHashTable *catalogo_historicos = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_historico);
  return catalogo_historicos;
}

void insert_historico(GHashTable *catalogo, HISTORICO historico, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo, key_dup, GINT_TO_POINTER(historico));
}

HISTORICO get_historico_by_key(GHashTable *catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo, key);
}

void update_historico(GHashTable *catalogo, char *key, HISTORICO historico)
{
  g_hash_table_replace (catalogo,key,GINT_TO_POINTER(historico));
}

void free_historico_catalog(GHashTable *catalogo) 
{
  g_hash_table_destroy(catalogo);
}