#include <glib.h>
#include "entidades/artistas.h"
#include "catalogos/catalogo_artistas.h"

struct catalogo {
  GHashTable *artistas;
};

CATALOGO create_catalogo_artistas(){
  CATALOGO catalogo = malloc(sizeof(struct catalogo));
  catalogo->artistas= g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_artista);
  return catalogo;
}

///nao encapsulado
GHashTable* create_artistas_catalog() 
{
  GHashTable *catalogo_artistas = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_artista);
  return catalogo_artistas;
}
///nao encapsulado

void insert_artista(CATALOGO catalogo, ARTISTA artista, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo->artistas, key_dup, GINT_TO_POINTER(artista));
}

ARTISTA get_artista_by_key(CATALOGO catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo->artistas, key);
}

void update_artista(CATALOGO catalogo, char *key, ARTISTA artista)
{
  g_hash_table_replace (catalogo->artistas,key,GINT_TO_POINTER(artista));
}

void free_artista_catalog(CATALOGO catalogo) 
{
  g_hash_table_destroy(catalogo->artistas);
}

void construir_artista(char *informacao, CATALOGO catalogo)
{

    char *id;
    char *name;
    //char *description;
    char *recipe_per_stream;
    GArray *id_constituent = g_array_new(FALSE, FALSE, sizeof(char *));
    char *country;
    char *type;

    char **tokens = g_strsplit(informacao, ";", -1);

    id = g_strdup(tokens[0]);
    name = g_strdup(tokens[1]);
    //description = g_strdup(tokens[2]);
    recipe_per_stream = g_strdup(tokens[3]);
    char* id_constituent_temp = g_strdup(tokens[4]);
    parse_A_U(id_constituent, remove_aspas(id_constituent_temp));
    country = g_strdup(tokens[5]);
    
    char *newline_pos = strchr(tokens[6], '\n');
    if (newline_pos) *newline_pos = '\0';
    type = g_strdup(tokens[6]);    

    ARTISTA artista = criar_artista();

    set_artista_id(artista, remove_aspas(id));
    set_name(artista, remove_aspas(name));
    //set_description(artista, remove_aspas(description));
    set_recipe_per_stream(artista, remove_aspas(recipe_per_stream));
    set_id_constituent(artista, id_constituent);
    set_country_artista(artista, remove_aspas(country));
    set_type(artista, remove_aspas(type));

    insert_artista(catalogo, artista, artista->id);
    
    free(id);
    free(name);
    //free(description);
    free(recipe_per_stream);
    g_array_free(id_constituent,  TRUE);
    free(id_constituent_temp);
    free(country);
    free(type);
    g_strfreev(tokens); 
}