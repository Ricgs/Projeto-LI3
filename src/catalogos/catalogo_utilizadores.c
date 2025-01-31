#include <glib.h>
#include "entidades/utilizadores.h"
#include "catalogos/catalogo_utilizadores.h"

struct catalogo {
  GHashTable *utilizadores;
};

CATALOGO create_catalogo_utilizadores(){
  CATALOGO catalogo = malloc(sizeof(struct catalogo));
  catalogo->utilizadores= g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_utilizador);
  return catalogo;
}

///nao encapsulado
GHashTable* create_utilizadores_catalog() 
{
  GHashTable *catalogo_utilizadores = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_utilizador);
  return catalogo_utilizadores;
}
///nao encapsulado

void insert_utilizador(CATALOGO catalogo, UTILIZADOR utilizador, char *key) 
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo->utilizadores, key_dup, GINT_TO_POINTER(utilizador));
}

UTILIZADOR get_utilizador_by_key(CATALOGO catalogo, char *key) 
{
  return g_hash_table_lookup(catalogo->utilizadores, key);
}

void update_utilizador(CATALOGO catalogo, char *key, UTILIZADOR utilizador)
{
  g_hash_table_replace (catalogo->utilizadores,key,GINT_TO_POINTER(utilizador));
}

void free_utilizador_catalog(CATALOGO catalogo) 
{
  g_hash_table_destroy(catalogo->utilizadores);
}

void construir_utilizador(char *informacao, CATALOGO catalogo)
{
    char *username;
    char *email;
    char *first_name;
    char *last_name;
    char *birth_date;
    char *country;
    //char *subscription_type;
    GArray *liked_musics_id  = g_array_new(FALSE, FALSE, sizeof(char *));

    char **tokens = g_strsplit(informacao, ";", -1);
    
    username = g_strdup(tokens[0]);
    email = g_strdup(tokens[1]);
    first_name = g_strdup(tokens[2]);
    last_name = g_strdup(tokens[3]);
    birth_date = g_strdup(tokens[4]);
    country = g_strdup(tokens[5]);
    //subscription_type = g_strdup(tokens[6]);
    
    char *newline_pos = strchr(tokens[7], '\n');
    if (newline_pos) *newline_pos = '\0';
    char* liked_musics_id_temp = g_strdup(tokens[7]);
    parse_A_U(liked_musics_id, remove_aspas(liked_musics_id_temp));

    UTILIZADOR utilizador = criar_utilizador();
    
    set_username(utilizador, remove_aspas(username));
    set_email(utilizador, remove_aspas(email));
    set_first_name(utilizador, remove_aspas(first_name));
    set_last_name(utilizador, remove_aspas(last_name));
    set_birth_date(utilizador, remove_aspas(birth_date));
    set_country(utilizador, remove_aspas(country));
    //set_subscription_type(utilizador, remove_aspas(subscription_type));
    set_liked_musics_id(utilizador, liked_musics_id);

    insert_utilizador(catalogo, utilizador, utilizador->username);

    free(username);
    free(email);
    free(first_name);
    free(last_name);
    free(birth_date);
    free(country);
    //free(subscription_type);
    g_array_free(liked_musics_id, TRUE);
    free(liked_musics_id_temp);
    g_strfreev(tokens); 
}