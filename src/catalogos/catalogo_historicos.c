#include <glib.h>
#include "entidades/historicos.h"
#include "catalogos/catalogo_historicos.h"

struct catalogo {
  GHashTable *historicos;
};

CATALOGO create_catalogo_historicos(){
  CATALOGO catalogo = malloc(sizeof(struct catalogo));
  catalogo->historicos= g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_historico);
  return catalogo;
}

///nao encapsulado
GHashTable* create_historicos_catalog() 
{
  GHashTable *catalogo_historicos = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_historico);
  return catalogo_historicos;
}
///nao encapsulado

void insert_historico(CATALOGO catalogo, HISTORICO historico, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo->historicos, key_dup, GINT_TO_POINTER(historico));
}

HISTORICO get_historico_by_key(CATALOGO catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo->historicos, key);
}

void update_historico(CATALOGO catalogo, char *key, HISTORICO historico)
{
  g_hash_table_replace (catalogo->historicos,key,GINT_TO_POINTER(historico));
}

void free_historico_catalog(CATALOGO catalogo) 
{
  g_hash_table_destroy(catalogo->historicos);
}

void construir_historico(char *informacao, CATALOGO catalogo)
{

    char *id;
    char *user_id;
    char *music_id;
    char *timestamp;
    char *duration;
    //char *platform;

    char **tokens = g_strsplit(informacao, ";", -1);

    id = g_strdup(tokens[0]);
    user_id = g_strdup(tokens[1]);
    music_id = g_strdup(tokens[2]);
    timestamp = g_strdup(tokens[3]);
    duration = g_strdup(tokens[4]);
    
    char *newline_pos = strchr(tokens[5], '\n');
    if (newline_pos) *newline_pos = '\0';
    //platform = g_strdup(tokens[5]); 

    HISTORICO historico = criar_historico();

    set_historico_id(historico, remove_aspas(id));
    set_user_id(historico, remove_aspas(user_id));
    set_h_music_id(historico, remove_aspas(music_id));
    set_timestamp(historico, remove_aspas(timestamp));
    set_h_duration(historico, remove_aspas(duration));
    //set_platform(historico, remove_aspas(platform));

    //insere_historico_utilizador(utilizadores, historico); query6

    insert_historico(catalogo, historico, historico->id);
    
    free(id);
    free(user_id);
    free(music_id);
    free(timestamp);
    free(duration);
    //free(platform);
    g_strfreev(tokens); 
}