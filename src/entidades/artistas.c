#include "entidades/artistas.h"
#include "catalogos/catalogo_artistas.h"
#include "utils/calculos.h"
#include <glib.h>
#include <stdio.h>
#include "catalogos/list.h"

struct artistas
{
    char *id;                     
    char *name;                   
    char *recipe_per_stream;      
    GArray *id_constituent;       
    char *country;                
    char *type;                   
    int discography_duration;     
    int total_duration;           
};

ARTISTA criar_artista(void)
{
    ARTISTA novo_artista = malloc(sizeof(struct artistas));
    novo_artista->id = NULL;
    novo_artista->name = NULL;
    //novo_artista->description = NULL;
    novo_artista->recipe_per_stream = NULL;
    novo_artista->id_constituent = g_array_new(FALSE, FALSE, sizeof(char *));
    novo_artista->country = NULL;
    novo_artista->type = NULL;
    novo_artista->discography_duration = 0;
    novo_artista->total_duration = 0;
    return novo_artista;
}

///nao encapsulado
void construir_artista(char *informacao, GHashTable *catalogo)
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
///nao encapsulado

//----------------ID-----------------
char *get_artista_id(ARTISTA artista)
{
    return strdup(artista->id);
}

void set_artista_id(ARTISTA artista, char *value)
{
    free(artista->id);
    artista->id = strdup(value);
}

//----------------NAME-----------------
char *get_name(ARTISTA artista)
{
    return strdup(artista->name);
}

void set_name(ARTISTA artista, char *value)
{
    free(artista->name);
    artista->name = strdup(value);
}

//----------------DESCRIPTION-----------------
/*char *get_description(ARTISTA artista)
{
    return strdup(artista->description);
}

void set_description(ARTISTA artista, char *value)
{
    free(artista->description);
    artista->description = strdup(value);
}
*/
//--------------RECIPE PER STREAM-----------------
char *get_recipe_per_stream(ARTISTA artista)
{
    return strdup(artista->recipe_per_stream);
}

void set_recipe_per_stream(ARTISTA artista, char *value)
{
    free(artista->recipe_per_stream);
    artista->recipe_per_stream = strdup(value);
}

//--------------ID CONSTITUENT-----------------
GArray *get_id_constituent(ARTISTA artista)
{
    GArray *id_constituent_copy = g_array_new(FALSE, FALSE, sizeof(char*));

    for (guint i = 0; i < artista->id_constituent->len; i++) {
        char *id = g_array_index(artista->id_constituent, char*, i);
        g_array_append_val(id_constituent_copy, id);
    }

    return id_constituent_copy;
}

void set_id_constituent(ARTISTA artista, GArray *value)
{
    if (artista->id_constituent != NULL) {
        g_array_free(artista->id_constituent, TRUE);
    }
    
    artista->id_constituent = g_array_sized_new(FALSE, FALSE, sizeof(char *), value->len);
    for (guint i = 0; i < value->len; i++) {
        char *id = g_array_index(value, char*, i);
        g_array_append_val(artista->id_constituent, id);
    }
}

//-----------------COUNTRY------------------
char *get_country_artista(ARTISTA artista)
{
    return strdup(artista->country);
}

void set_country_artista(ARTISTA artista, char *value)
{
    free(artista->country);
    artista->country = strdup(value);
}

//---------------TYPE------------------
char *get_type(ARTISTA artista)
{
    return strdup(artista->type);
}

void set_type(ARTISTA artista, char *value)
{
    free(artista->type);
    artista->type = strdup(value);
}

int get_discography_duration(ARTISTA artista) 
{
    return artista->discography_duration;
}

void set_discography_duration(ARTISTA artista, int value) 
{
    artista->discography_duration = artista->discography_duration + value;
}



void destroi_artista(gpointer data)
{
    ARTISTA artista = (ARTISTA)data;

    free(artista->id);
    free(artista->name);
    //free(artista->description);
    free(artista->recipe_per_stream);
    for (guint i = 0; i < artista->id_constituent->len; i++) {
        char *id = g_array_index(artista->id_constituent, char*, i);
        free(id);
    }
    g_array_free(artista->id_constituent, TRUE);
    free(artista->country);
    free(artista->type);
    free(artista);
}
