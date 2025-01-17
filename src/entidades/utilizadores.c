#include <stdio.h>
#include "entidades/utilizadores.h"
#include "catalogos/catalogo_utilizadores.h"
#include "utils/calculos.h"
#include <glib.h>

UTILIZADOR criar_utilizador(void)
{
    UTILIZADOR novo_utilizador = malloc(sizeof(struct utilizadores));
    novo_utilizador->username = NULL;
    novo_utilizador->email = NULL;
    novo_utilizador->first_name = NULL;
    novo_utilizador->last_name = NULL;
    novo_utilizador->birth_date = NULL;
    novo_utilizador->country = NULL;
    //novo_utilizador->subscription_type = NULL;
    novo_utilizador->liked_musics_id = g_array_new(FALSE, FALSE, sizeof(char *));
    //novo_utilizador->historico = NULL; <- para ajudar na query6 
    return novo_utilizador;
}

void construir_utilizador(char *informacao, GHashTable *catalogo)
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

//----------------USERNAME-----------------
char *get_username(UTILIZADOR utilizador)
{
    return strdup(utilizador->username);
}

void set_username(UTILIZADOR utilizador, char *value)
{
    free(utilizador->username);
    utilizador->username = strdup(value);
}

//----------------EMAIL-----------------
char *get_email(UTILIZADOR utilizador)
{
    return strdup(utilizador->email);
}

void set_email(UTILIZADOR utilizador, char *value)
{
    free(utilizador->email);
    utilizador->email = strdup(value);
}

//----------------FIRST NAME-----------------
char *get_first_name(UTILIZADOR utilizador)
{
    return strdup(utilizador->first_name);
}

void set_first_name(UTILIZADOR utilizador, char *value)
{
    free(utilizador->first_name);
    utilizador->first_name = strdup(value);
}

//--------------LAST NAME-----------------
char *get_last_name(UTILIZADOR utilizador)
{
    return strdup(utilizador->last_name);
}

void set_last_name(UTILIZADOR utilizador, char *value)
{
    free(utilizador->last_name);
    utilizador->last_name = strdup(value);
}

//--------------BIRTH DATE-----------------
char *get_birth_date(UTILIZADOR utilizador)
{
    return strdup(utilizador->birth_date);
}

void set_birth_date(UTILIZADOR utilizador, char *value)
{
    free(utilizador->birth_date);
    utilizador->birth_date = strdup(value);
}

//-----------------COUNTRY------------------
char *get_country(UTILIZADOR utilizador)
{
    return strdup(utilizador->country);
}

void set_country(UTILIZADOR utilizador, char *value)
{
    free(utilizador->country);
    utilizador->country = strdup(value);
}

//---------------SUBSCRIPTION TYPE------------------
/*char *get_subscription_type(UTILIZADOR utilizador)
{
    return strdup(utilizador->subscription_type);
}

void set_subscription_type(UTILIZADOR utilizador, char *value)
{
    free(utilizador->subscription_type);
    utilizador->subscription_type = strdup(value);
}
*/
//--------------LISTA DE MÚSICAS COM LIKE------------

GArray *get_liked_musics_id(UTILIZADOR utilizador)
{
    GArray *likes_copy = g_array_new(FALSE, FALSE, sizeof(char*));

    for (guint i = 0; i < utilizador->liked_musics_id->len; i++) {
        char *id = g_array_index(utilizador->liked_musics_id, char*, i);
        g_array_append_val(likes_copy, id);
    }

    return likes_copy;
}

void set_liked_musics_id(UTILIZADOR utilizador, GArray *value)
{
    if (utilizador->liked_musics_id != NULL) {
        g_array_free(utilizador->liked_musics_id, TRUE);
    }
    
    utilizador->liked_musics_id = g_array_sized_new(FALSE, FALSE, sizeof(char *), value->len);
    for (guint i = 0; i < value->len; i++) {
        char *id = g_array_index(value, char*, i);
        g_array_append_val(utilizador->liked_musics_id, id);
    }
}

/* query6
List *get_historico(UTILIZADOR utilizador) {
    return utilizador->historico;
}

void set_historico_utilizador(UTILIZADOR utilizador, List *historico) {
    utilizador->historico = historico;
}
*/

void destroi_utilizador(gpointer data)
{
    UTILIZADOR utilizador = (UTILIZADOR)data;

    free(utilizador->username);
    free(utilizador->email);
    free(utilizador->first_name);
    free(utilizador->last_name);
    free(utilizador->birth_date);
    free(utilizador->country);
    //free(utilizador->subscription_type);
    for (guint i = 0; i < utilizador->liked_musics_id->len; i++) {
        char *id = g_array_index(utilizador->liked_musics_id, char*, i);
        free(id);
    }
    g_array_free(utilizador->liked_musics_id, TRUE);
    //listDestroy(utilizador->historico); query 6

    free(utilizador);
}
