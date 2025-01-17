#include "entidades/musicas.h"
#include "catalogos/catalogo_musicas.h"
#include "utils/calculos.h"
#include <glib.h>
#include <stdio.h>

MUSICA criar_musica(void) {

  MUSICA nova_musica = malloc(sizeof(struct musicas));
  
  nova_musica->id = NULL;
  nova_musica->title = NULL;
  nova_musica->artist_id = g_array_new(FALSE, FALSE, sizeof(char *));
  nova_musica->album_id = NULL;
  nova_musica->duration = NULL;
  nova_musica->genre = NULL;
  nova_musica->year = NULL; 
  //nova_musica->lyrics = NULL; //retirar

  return nova_musica;
}

void construir_musica(char *informacao, GHashTable *catalogo) 
{
    char *id;
    char *title;
    GArray *artist_id  = g_array_new(FALSE, FALSE, sizeof(char *));
    char *album_id;
    char *duration;
    char *genre;
    char *year;
    //char *lyrics;

    char **tokens = g_strsplit(informacao, ";", -1);

    id = g_strdup(tokens[0]);
    title = g_strdup(tokens[1]);
    char* artist_id_temp = g_strdup(tokens[2]);
    parse_artist_id(artist_id, remove_aspas(artist_id_temp));
    album_id = g_strdup(tokens[3]);
    duration = g_strdup(tokens[4]);
    genre = g_strdup(tokens[5]);
    year = g_strdup(tokens[6]);
    
    char *newline_pos = strchr(tokens[7], '\n');
    if (newline_pos) *newline_pos = '\0';
    //lyrics = g_strdup(tokens[7]);    
    
    MUSICA musica = criar_musica();

    set_music_id(musica, remove_aspas(id));
    set_title(musica, remove_aspas(title));
    set_artist_id(musica, artist_id);
    set_m_album_id(musica, remove_aspas(album_id));
    set_duration(musica, remove_aspas(duration));
    set_genre(musica, remove_aspas(genre));
    set_year(musica, remove_aspas(year));
    //set_lyrics(musica, remove_aspas(lyrics));

    insert_musica(catalogo, musica, musica->id);

    free(id);
    free(title);
    g_array_free(artist_id, TRUE);
    free(artist_id_temp);
    free(album_id);
    free(duration);
    free(genre);
    free(year);
    //free(lyrics);
    g_strfreev(tokens);
}

//----------------ID-----------------
char *get_music_id(MUSICA musica) 
{
    return strdup(musica->id);
}

void set_music_id(MUSICA musica, char *value) 
{
    free(musica->id);
    musica->id = strdup(value);
}

//----------------TITLE-----------------
char *get_title(MUSICA musica) 
{
    return strdup(musica->title);
}

void set_title(MUSICA musica, char *value) 
{
    free(musica->title);
    musica->title = strdup(value);
}

//----------------ARTIST ID-----------------
GArray *get_artist_id(MUSICA musica) 
{
    GArray *artist_id_copy = g_array_new(FALSE, FALSE, sizeof(char*));

    for (guint i = 0; i < musica->artist_id->len; i++) {
        char *id = g_array_index(musica->artist_id, char*, i);
        g_array_append_val(artist_id_copy, id);
    }

    return artist_id_copy;
}

void set_artist_id(MUSICA musica, GArray *value) 
{
    if (musica->artist_id != NULL) {
        g_array_free(musica->artist_id, TRUE);
    }
    
    musica->artist_id = g_array_sized_new(FALSE, FALSE, sizeof(char *), value->len);
    for (guint i = 0; i < value->len; i++) {
        char *id = g_array_index(value, char*, i);
        g_array_append_val(musica->artist_id, id);
    }
}

//--------------ALBUM ID-----------------
char *get_m_album_id(MUSICA musica) 
{
    return strdup(musica->album_id);
}

void set_m_album_id(MUSICA musica, char *value) 
{
    free(musica->album_id);
    musica->album_id = strdup(value);
}

//--------------DURATION-----------------
char *get_duration(MUSICA musica) 
{
    return strdup(musica->duration);
}

void set_duration(MUSICA musica, char *value) 
{
    free(musica->duration);
    musica->duration = strdup(value);
}

//--------------GENRE-----------------
char *get_genre(MUSICA musica) 
{
    return strdup(musica->genre);
}

void set_genre(MUSICA musica, char *value) 
{
    free(musica->genre);
    musica->genre = strdup(value);
}

//-----------------YEAR------------------
char *get_year(MUSICA musica) 
{
    return strdup(musica->year);
}

void set_year(MUSICA musica, char *value) 
{
    free(musica->year);
    musica->year = strdup(value);
}

//---------------LYRICS------------------
/*
char *get_lyrics(MUSICA musica) 
{
    return strdup(musica->lyrics);
}

void set_lyrics(MUSICA musica, char *value) 
{
    free(musica->lyrics);
    musica->lyrics = strdup(value);
}
*/
void destroi_musica(gpointer data)
{
  MUSICA musica = (MUSICA)data;

  free(musica->id);
  free(musica->title);
  for (guint i = 0; i < musica->artist_id->len; i++) {
    char *id = g_array_index(musica->artist_id, char*, i);
    free(id);
  }
  g_array_free(musica->artist_id, TRUE);
  free(musica->album_id);
  free(musica->duration);
  free(musica->genre);
  free(musica->year);
  //free(musica->lyrics);
  free(musica);
}
