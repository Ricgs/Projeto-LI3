#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/artistas.h"
#include "entidades/musicas.h"
#include "entidades/historicos.h"
#include "entidades/utilizadores.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_historicos.h"
#include "catalogos/list.h"
#include "utils/calculos.h"
#include <stdbool.h>

/*
void set_historico(GHashTable *historicos, GHashTable *utilizadores, GHashTable *musicas, FILE *file) {
    char *erros_historicos = cria_erros("resultados/history_errors.csv");
    FILE *pasta_erros_historicos = cria_ficheiro(erros_historicos);

    char **linhas = NULL;
    int n = ler_ficheiro(file, &linhas);  

    for (int i = 0; i < n; i++) {
        if (historico_valido(linhas[i], utilizadores, musicas) == 1)
            construir_historico(linhas[i], historicos);
        else
            fprintf(pasta_erros_historicos, "%s", linhas[i]);
    }

    guint tamanho = g_hash_table_size(historicos);
    printf("Tamanho de historico: %u\n", tamanho);

    for (int i = 0; i < n; i++) {
        free(linhas[i]); 
    }
    free(linhas); 
    free(erros_historicos); 
    fclose(pasta_erros_historicos); 
}
*/
void processa_linha_historico(GHashTable *historicos, GHashTable *utilizadores, GHashTable *musicas, FILE *pasta_erros_historicos, char *linha) {
    if (historico_valido(linha, utilizadores, musicas) == 1)
        construir_historico(linha, historicos,utilizadores);
    else
        fprintf(pasta_erros_historicos, "%s", linha);
}

void set_historico(GHashTable *historicos, GHashTable *utilizadores, GHashTable *musicas, FILE *file) {
    char *erros_historicos = cria_erros("resultados/history_errors.csv");
    FILE *pasta_erros_historicos = cria_ficheiro(erros_historicos);

    char *linha;
    while ((linha = ler_linha(file)) != NULL) {
        processa_linha_historico(historicos, utilizadores, musicas, pasta_erros_historicos, linha);
        free(linha);
    }
    free(erros_historicos);
    fclose(pasta_erros_historicos);
}


/* Query 6 funções
// Funções auxiliares que você pode precisar implementar, como parsing de timestamp, 
// comparação de strings, e cálculo de tempo no formato hh:mm:ss, estão incluídas.

typedef struct {
    char *artist_id;
    char *artist_name;
    int num_songs;
    int total_listening_time;
} ArtistStat;

// Verifica se uma data (formato "YYYY-MM-DD") pertence a um determinado ano
bool same_year(const char *date, const char *year) {
    // Os primeiros 4 caracteres da data representam o ano
    return strncmp(date, year, 4) == 0;
}


int parse_duration_to_seconds(const char *duration) {
    int hours, minutes, seconds;
    sscanf(duration, "%d:%d:%d", &hours, &minutes, &seconds);
    return (hours * 3600) + (minutes * 60) + seconds;
}

char *extract_day_from_date(const char *date) {
    // Pula os primeiros 8 caracteres ("YYYY-MM-") para obter o dia
    return strdup(date + 8);
}

int extract_hour_from_date(const char *timestamp) {
    // A hora começa no 12º caractere do timestamp
    char hour_str[3];
    strncpy(hour_str, timestamp + 11, 2);
    hour_str[2] = '\0';
    return atoi(hour_str);
}

void collect_artist_stats(gpointer key, gpointer value, gpointer user_data) {
    GPtrArray *artist_array = (GPtrArray *)user_data;
    ArtistStat *stat = (ArtistStat *)value;

    ArtistStat *copy = malloc(sizeof(ArtistStat));
    *copy = *stat; // Copiar os valores
    g_ptr_array_add(artist_array, copy);
}

char *generate_result_string(int total_listening_time, int unique_song_count, char *most_listened_artist, 
                             char *most_active_day, char *most_listened_genre, char *favorite_album, 
                             int favorite_hour, GPtrArray *artist_array, int N) {
    char *result = malloc(1024); // Buffer inicial para a string resultante
    snprintf(result, 1024, "%02d:%02d:%02d;%d;%s;%s;%s;%s;%02d",
             total_listening_time / 3600, (total_listening_time % 3600) / 60, total_listening_time % 60,
             unique_song_count,
             most_listened_artist ? most_listened_artist : "",
             most_active_day ? most_active_day : "",
             most_listened_genre ? most_listened_genre : "",
             favorite_album ? favorite_album : "",
             favorite_hour);

    for (int i = 0; i < N && i < artist_array->len; i++) {
        ArtistStat *stat = (ArtistStat *)g_ptr_array_index(artist_array, i);
        char artist_line[256];
        snprintf(artist_line, 256, "\n%s;%d;%02d:%02d:%02d",
                 stat->artist_name, stat->num_songs,
                 stat->total_listening_time / 3600, 
                 (stat->total_listening_time % 3600) / 60, 
                 stat->total_listening_time % 60);
        result = realloc(result, strlen(result) + strlen(artist_line) + 1);
        strcat(result, artist_line);
    }

    return result;
}

// Função auxiliar para comparar artistas pelo tempo e id
int compare_artist_stat(const void *a, const void *b) {
    ArtistStat *artistA = *(ArtistStat **)a; 
    ArtistStat *artistB = *(ArtistStat **)b;

    if (!artistA || !artistB) return 0; 

    if (artistA->total_listening_time != artistB->total_listening_time) {
        return artistB->total_listening_time - artistA->total_listening_time;
    }
    return strcmp(artistA->artist_id, artistB->artist_id);
}

void free_hash_element(gpointer key, gpointer value, gpointer user_data) {
        g_free(key);   // Libera a chave, se foi alocada dinamicamente
        g_free(value); // Libera o valor, se foi alocado dinamicamente
    }



char *historico_anual(char *user_id, GHashTable *utilizadores, GHashTable *album, GHashTable *artistas, GHashTable *musicas, char *year, int N) {
    UTILIZADOR user = g_hash_table_lookup(utilizadores, user_id);
    if (!user) return strdup("\n");
    printf("\n 1");
    fflush(stdout);
    List *historico = user->historico;
    if (!historico) return strdup("\n");
    printf("\n 2");
    fflush(stdout);

    // Variáveis para acumular estatísticas
    int total_listening_time = 0;
    GHashTable *unique_songs = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable *genre_time = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable *album_time = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable *hour_time = g_hash_table_new(g_int_hash, g_int_equal);
    printf("\n 3");
    fflush(stdout);

    GHashTable *artist_stats = g_hash_table_new(g_str_hash, g_str_equal);

    GHashTable *daily_song_count = g_hash_table_new(g_str_hash, g_str_equal);

    char *most_listened_artist = NULL;
    int most_listened_artist_time = 0;

    char *most_active_day = NULL;
    int most_active_day_songs = 0;

    char *most_listened_genre = NULL;
    int most_listened_genre_time = 0;

    char *favorite_album = NULL;
    int favorite_album_time = 0;

    int favorite_hour = 0;
    int favorite_hour_time = 0;

    printf("\n 4");
    fflush(stdout);

    while (historico != NULL) {

        printf("\n 5");
        fflush(stdout);
        HISTORICO entry = historico->data;
        char *date = get_timestamp(entry);
        char *music_id = get_h_music_id(entry);
        char *duration = get_h_duration(entry);

        if (same_year(date, year)) {

            printf("\n 6");
            fflush(stdout);
            int duration_sec = parse_duration_to_seconds(duration);
            total_listening_time += duration_sec;

            // Contabilizar música única
            if (!g_hash_table_contains(unique_songs, music_id)) {
                g_hash_table_insert(unique_songs, g_strdup(music_id), GINT_TO_POINTER(1));
            }

            printf("\n 7");
            fflush(stdout);

            // Processar dados da música
            MUSICA music = g_hash_table_lookup(musicas, music_id);
            if (music) {
                // Processar género
                if (music->genre) {
                    int genre_time_current = GPOINTER_TO_INT(g_hash_table_lookup(genre_time, music->genre));
                    genre_time_current += duration_sec;
                    g_hash_table_insert(genre_time, g_strdup(music->genre), GINT_TO_POINTER(genre_time_current));
                    if (genre_time_current > most_listened_genre_time ||
                        (genre_time_current == most_listened_genre_time &&
                         strcmp(music->genre, most_listened_genre) < 0)) {
                        most_listened_genre = music->genre;
                        most_listened_genre_time = genre_time_current;
                    }
                }

                printf("\n 8");
                fflush(stdout);

                // Processar álbum
                if (music->album_id) {
                    int album_time_current = GPOINTER_TO_INT(g_hash_table_lookup(album_time, music->album_id));
                    album_time_current += duration_sec;
                    g_hash_table_insert(album_time, g_strdup(music->album_id), GINT_TO_POINTER(album_time_current));
                    if (album_time_current > favorite_album_time ||
                        (album_time_current == favorite_album_time &&
                         strcmp(music->album_id, favorite_album) < 0)) {
                        favorite_album = music->album_id;
                        favorite_album_time = album_time_current;
                    }
                }

                // Processar artistas
                for (int i = 0; i < music->artist_id->len; i++) {

                    printf("\n 9");
                    fflush(stdout);
                    char *artist_id = g_array_index(music->artist_id, char *, i);
                    ARTISTA artist = g_hash_table_lookup(artistas, artist_id);
                    if (artist) {
                        ArtistStat *stat = g_hash_table_lookup(artist_stats, artist_id);
                        if (!stat) {
                            stat = malloc(sizeof(ArtistStat));
                            stat->artist_id = artist_id;
                            stat->artist_name = artist->name;
                            stat->num_songs = 0;
                            stat->total_listening_time = 0;
                            g_hash_table_insert(artist_stats, g_strdup(artist_id), stat);
                        }
                        stat->num_songs++;
                        stat->total_listening_time += duration_sec;
                        if (stat->total_listening_time > most_listened_artist_time) {
                            most_listened_artist = artist->name;
                            most_listened_artist_time = stat->total_listening_time;
                        }
                    }
                }
            }

            printf("\n 10");
            fflush(stdout);

            // Processar dia mais ativo
            char *day = extract_day_from_date(date);
            int daily_songs = GPOINTER_TO_INT(g_hash_table_lookup(daily_song_count, day));
            daily_songs++;
            g_hash_table_insert(daily_song_count, g_strdup(day), GINT_TO_POINTER(daily_songs));
            if (daily_songs > most_active_day_songs ||
                (daily_songs == most_active_day_songs && strcmp(day, most_active_day) > 0)) {
                
                most_active_day = day;
                most_active_day_songs = daily_songs;
            } 

            printf("\n 11");
            fflush(stdout);

            // Processar hora mais ativa
            int hour = extract_hour_from_date(date);
            int hour_listening_time = GPOINTER_TO_INT(g_hash_table_lookup(hour_time, &hour));
            hour_listening_time += duration_sec;
            g_hash_table_insert(hour_time, &hour, GINT_TO_POINTER(hour_listening_time));
            if (hour_listening_time > favorite_hour_time ||
                (hour_listening_time == favorite_hour_time && hour < favorite_hour)) {
                favorite_hour = hour;
                favorite_hour_time = hour_listening_time;
            }
        }
        free(music_id);
        free(duration);
        free(date);
        historico = historico->next;
    }

    printf("\n 12");
    fflush(stdout);
    // Gerar estatísticas no formato esperado
    GPtrArray *artist_array = g_ptr_array_new_with_free_func(free);
    g_hash_table_foreach(artist_stats, collect_artist_stats, artist_array);
    g_ptr_array_sort(artist_array, compare_artist_stat);

    char *result = generate_result_string(total_listening_time, g_hash_table_size(unique_songs), most_listened_artist, 
                                          most_active_day, most_listened_genre, favorite_album, favorite_hour, artist_array, N);
                    

    printf("\n 13");
    fflush(stdout);


    g_hash_table_foreach(unique_songs, free_hash_element, NULL);
    g_hash_table_destroy(unique_songs);

    // Libera genre_time
    g_hash_table_foreach(genre_time, free_hash_element, NULL);
    g_hash_table_destroy(genre_time);

    // Libera album_time
    g_hash_table_foreach(album_time, free_hash_element, NULL);
    g_hash_table_destroy(album_time);

    // Libera hour_time
    g_hash_table_foreach(hour_time, free_hash_element, NULL);
    g_hash_table_destroy(hour_time);

    // Libera artist_stats
    g_hash_table_foreach(artist_stats, free_hash_element, NULL);
    g_hash_table_destroy(artist_stats);

    // Libera daily_song_count
    g_hash_table_foreach(daily_song_count, free_hash_element, NULL);
    g_hash_table_destroy(daily_song_count);

    // Libera elementos do array de artistas e o array em si
    for (guint i = 0; i < artist_array->len; i++) {
        g_free(g_ptr_array_index(artist_array, i)); // Libera cada elemento
    }
    g_ptr_array_unref(artist_array);

    printf("\n %s", result);
    fflush(stdout);

    return result;
}
*/