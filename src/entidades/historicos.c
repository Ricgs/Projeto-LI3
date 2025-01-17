#include "entidades/historicos.h"
#include "catalogos/catalogo_historicos.h"
#include "utils/calculos.h"
#include <glib.h>
#include "catalogos/list.h"
#include "entidades/utilizadores.h"
#include <stdio.h>


HISTORICO criar_historico(void)
{
    HISTORICO novo_historico = malloc(sizeof(struct historicos));
    novo_historico->id = NULL;
    novo_historico->user_id = NULL;
    novo_historico->music_id = NULL;
    novo_historico->timestamp = NULL;
    novo_historico->duration = NULL;
    //novo_historico->platform = NULL; //retirar
    
    return novo_historico;
}

void construir_historico(char *informacao, GHashTable *catalogo, GHashTable *utilizadores)
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

//----------------ID-----------------
char *get_historico_id(HISTORICO historico)
{
    return strdup(historico->id);
}

void set_historico_id(HISTORICO historico, char *value)
{
    free(historico->id);
    historico->id = strdup(value);
}

//----------------USER ID-----------------
char *get_user_id(HISTORICO historico)
{
    return strdup(historico->user_id);
}

void set_user_id(HISTORICO historico, char *value)
{
    free(historico->user_id);
    historico->user_id = strdup(value);
}

//--------------MUSIC ID-----------------
char *get_h_music_id(HISTORICO historico)
{
    return strdup(historico->music_id);
}

void set_h_music_id(HISTORICO historico, char *value)
{
    free(historico->music_id);
    historico->music_id = strdup(value);
}

//--------------TIMESTAMP-----------------
char *get_timestamp(HISTORICO historico)
{
    return strdup(historico->timestamp);
}

void set_timestamp(HISTORICO historico, char *value)
{
    free(historico->timestamp);
    historico->timestamp = strdup(value);
}

//--------------DURATION-----------------
char *get_h_duration(HISTORICO historico)
{
    return strdup(historico->duration);
}

void set_h_duration(HISTORICO historico, char *value)
{
    free(historico->duration);
    historico->duration = strdup(value);
}

//--------------PLATFORM-----------------
/*char *get_platform(HISTORICO historico)
{
    return strdup(historico->platform);
}

void set_platform(HISTORICO historico, char *value)
{
    free(historico->platform);
    historico->platform = strdup(value);
}
*/

/* query6
void insere_historico_utilizador(GHashTable *utilizadores, HISTORICO historico) {
    
    char *user_id = historico->user_id;

    UTILIZADOR utilizador = g_hash_table_lookup(utilizadores, user_id);

    if (get_historico(utilizador) == NULL) {
        List *lista = listCreate(historico);
        set_historico_utilizador(utilizador, lista);
    } else {
        insert_list_end(get_historico(utilizador), historico);
    }


}
*/


void destroi_historico(gpointer data)
{
    HISTORICO historico = (HISTORICO)data;
    free(historico->id);
    free(historico->user_id);
    free(historico->music_id);
    free(historico->timestamp);
    free(historico->duration);
    //free(historico->platform);

    free(historico);
}
