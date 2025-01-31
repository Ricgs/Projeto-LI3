#include <glib.h>
#include "entidades/musicas.h"
#include "catalogos/catalogo_musicas.h"

struct catalogo {
  GHashTable *musicas;
};

CATALOGO create_catalogo_musicas(){
  CATALOGO catalogo = malloc(sizeof(struct catalogo));
  catalogo->musicas= g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_musica);
  return catalogo;
}

///nao encapsulado
GHashTable *create_musicas_catalog()
{
  GHashTable *catalogo_musicas = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroi_musica);
  return catalogo_musicas;
}
///nao encapsulado


void insert_musica(CATALOGO catalogo, MUSICA musica, char *key)
{
  char *key_dup = strdup(key);
  g_hash_table_insert(catalogo->musicas, key_dup, GINT_TO_POINTER(musica));
}

MUSICA get_musica_by_key(CATALOGO catalogo, char *key)
{
  return g_hash_table_lookup(catalogo->musicas, key);
}

void update_musica(CATALOGO catalogo, char *key, MUSICA musica)
{
  g_hash_table_replace(catalogo->musicas, key, GINT_TO_POINTER(musica));
}

void free_musica_catalog(CATALOGO catalogo)
{
  g_hash_table_destroy(catalogo->musicas);
}

void construir_musica(char *informacao, CATALOGO catalogo) 
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