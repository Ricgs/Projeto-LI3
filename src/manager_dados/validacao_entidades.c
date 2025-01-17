#include <stdio.h>
#include "entidades/utilizadores.h"
#include "entidades/artistas.h"
#include "entidades/musicas.h"
#include "utils/calculos.h"
#include "manager_dados/validacao_entidades.h"
#include <ctype.h>

int verifica_data(char *data)
{
    int ano, mes, dia;
    if (strlen(data) == 10 && data[4] == '/' && data[7] == '/') {
        if (sscanf(data, "%4d/%2d/%2d", &ano, &mes, &dia) == 3)
        {
            if (ano >= 0 && ano <= 2024 && dia <= 31 && dia >= 1 && mes >= 1 && mes <= 12){
                if (ano == 2024 && mes > 9){
                    return 0;
                } else if (ano == 2024 && mes == 9 && dia > 9){
                    return 0;
                }
                return 1;
            }
        }
    }
    return 0;
}

int verifica_duration(char *duration)
{
    int hora, min, seg;

    if (strlen(duration) == 8 && duration[2] == ':' && duration[5] == ':') 
    {
        if (isdigit(duration[0]) && isdigit(duration[1]) && isdigit(duration[3]) && isdigit(duration[4]) && isdigit(duration[6]) && isdigit(duration[7])) 
        {
            if (sscanf(duration, "%2d:%2d:%2d", &hora, &min, &seg) == 3) 
            {
                if (hora >= 0 && hora <= 99 && min >= 0 && min <= 59 && seg >= 0 && seg <= 59) 
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int verifica_email(char *email)
{
    char username[100], domain[50], tld[20];
    if ((sscanf(email, "%99[a-z0-9]@%49[a-z].%49[a-zA-Z]", username, domain, tld) == 3))
    {
        if (strlen(username) >= 1 && strlen(domain) >= 1 && (strlen(tld) == 2 || strlen(tld) == 3)){
            return 1;
        }
    }
    return 0;
}

int verifica_subscription_type(char *subscription_type) 
{
    if (strcasecmp(subscription_type, "normal") == 0 || strcasecmp(subscription_type, "premium") == 0)
        return 1;
    return 0;
}

int verifica_delimitadores(char *lista)
{
    if (lista == NULL) return 0; //listas nulas ou vazias não são válidas
    size_t len = strlen(lista);
    if (len == 0) return 0;

    if (lista[0] == '[' && lista[len - 1] == ']') return 1; // Verificar delimitadores. return 1 se válido
    else return 0;
}

int verifica_platform(char *platform)
{
    if (strcasecmp(platform, "mobile") == 0 || strcasecmp(platform, "desktop") == 0)
        return 1;
    return 0;
}

int verifica_type(char *type)
{
    if (strcasecmp(type, "individual") == 0 || strcasecmp(type, "group") == 0)
        return 1;
    return 0;
}

int verifica_id_constituent(GArray* id_constituent, char* type)
{
    if (strcmp(type, "individual") == 0 && id_constituent->len != 0) return 0;
    if (strcmp(type, "group") == 0 && id_constituent->len == 0) return 0;
    if (strcmp(type, "type") == 0) return 0;
    else return 1;
}

int verifica_artist_id(GArray* artist_id, GHashTable *artistas)
{
    if (artist_id == NULL) return 0;
    for (guint i = 0; i < artist_id->len; i++) {
        char *id = g_array_index(artist_id, char *, i);
        if (!g_hash_table_contains(artistas, id)) return 0;
    }

    return 1;
}

int verifica_liked_musics_id(GArray* liked_musics_id, GHashTable *musicas)
{
    for (int i = 0; i < liked_musics_id->len; i++) 
    {
        char *id = g_array_index(liked_musics_id, char *, i);

        if (!g_hash_table_contains(musicas, id)) {
            return 0;
        }
    }
    return 1;
}

int verifica_album(char *album, GHashTable *albums)
{
    if (g_hash_table_contains(albums, album)) return 1;
    return 0; 
}

int verifica_timestamp(char *timestamp)
{
    int valid = 1;
    // Divide o timestamp em duas partes: data e hora
    char **tokens = g_strsplit(timestamp, " ", 2);
    if (!tokens[0] || !tokens[1]) {
        g_strfreev(tokens); // Libera a memória caso falte alguma parte
        return 0; // Inválido
    }

    // Verifica a validade da data e da duração
    if (verifica_data(tokens[0]) == 0 || verifica_duration(tokens[1]) == 0) valid = 0;

    g_strfreev(tokens); // Libera a memória alocada pela g_strsplit
    return valid;
}

int verifica_user_id(char *user_id, GHashTable *utilizadores)
{
    if (!g_hash_table_contains(utilizadores, user_id)) return 0;
    return 1;
}

int verifica_music_id(char *music_id, GHashTable *musicas)
{
    if (!g_hash_table_contains(musicas, music_id)) return 0;
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int artista_valido(char *informacao)
{
    GArray *id_constituent = g_array_new(FALSE, FALSE, sizeof(char *));
    char *type;

    char **tokens = g_strsplit(informacao, ";", -1);

    char* id_constituent_temp = g_strdup(tokens[4]);
    parse_A_U(id_constituent, remove_aspas(id_constituent_temp));
    
    char *newline_pos = strchr(tokens[6], '\n');
    if (newline_pos) *newline_pos = '\0';
    type = g_strdup(tokens[6]);

    int check = 1;

    if (verifica_delimitadores(remove_aspas(id_constituent_temp)) == 0)
        check = 0;
    else if (verifica_id_constituent(id_constituent, remove_aspas(type)) == 0) 
        check = 0;
    
    for (guint i = 0; i < id_constituent->len; i++) {
        char *id = g_array_index(id_constituent, char*, i);
        free(id);
    }
    g_array_free(id_constituent,  TRUE);
    free(id_constituent_temp);
    free(type);
    g_strfreev(tokens);

    return check;
}

int utilizador_valido(char *informacao, GHashTable *musicas)
{
    char *email;
    char *birth_date;
    char *subscription_type;
    GArray *liked_musics_id  = g_array_new(FALSE, FALSE, sizeof(char *));

    char **tokens = g_strsplit(informacao, ";", -1);

    email = g_strdup(tokens[1]);
    birth_date = g_strdup(tokens[4]);
    subscription_type = g_strdup(tokens[6]);
    
    char *newline_pos = strchr(tokens[7], '\n');
    if (newline_pos) *newline_pos = '\0';
    char* liked_musics_id_temp = g_strdup(tokens[7]);
    parse_A_U(liked_musics_id, remove_aspas(liked_musics_id_temp));

    int check = 1;

    if (verifica_delimitadores(remove_aspas(liked_musics_id_temp)) == 0)
        check = 0;
    else if (verifica_data(remove_aspas(birth_date)) == 0)
        check = 0;
    else if (verifica_email(remove_aspas(email)) == 0)
        check = 0;
    else if (verifica_subscription_type(remove_aspas(subscription_type)) == 0)
        check = 0;
    else if (verifica_liked_musics_id(liked_musics_id, musicas) == 0)
        check = 0;

    free(email);
    free(birth_date);
    free(subscription_type);
    for (guint i = 0; i < liked_musics_id->len; i++) {
        char *id = g_array_index(liked_musics_id, char*, i);
        free(id);
    }
    g_array_free(liked_musics_id, TRUE);
    free(liked_musics_id_temp);
    g_strfreev(tokens); 

    return check;
}

int musica_valida(char *informacao, GHashTable *artistas, GHashTable *albums)
{

    GArray *artist_id  = g_array_new(FALSE, FALSE, sizeof(char *));
    char *album_id;
    char *duration;

    char **tokens = g_strsplit(informacao, ";", -1);

    char* artist_id_temp = g_strdup(tokens[2]);
    parse_artist_id(artist_id, remove_aspas(artist_id_temp));
    album_id = g_strdup(tokens[3]);
    duration = g_strdup(tokens[4]);
    
    char *newline_pos = strchr(tokens[7], '\n');
    if (newline_pos) *newline_pos = '\0';

    int check = 1;

    if (verifica_delimitadores(remove_aspas(artist_id_temp)) == 0)
        check = 0;
    else if (verifica_duration(remove_aspas(duration)) == 0)
        check = 0;
    else if (verifica_artist_id(artist_id, artistas) == 0)
        check = 0;
    else if (verifica_album(remove_aspas(album_id), albums) == 0)
        check = 0;

    for (guint i = 0; i < artist_id->len; i++) {
        char *id = g_array_index(artist_id, char*, i);
        free(id);
    }
    g_array_free(artist_id, TRUE);
    free(album_id);
    free(artist_id_temp);
    free(duration);
    g_strfreev(tokens);

    return check;
}

int historico_valido(char *informacao, GHashTable *utilizadores, GHashTable *musicas)
{
    char *user_id;
    char *music_id;
    char *timestamp;
    char *duration;
    char *platform;

    char **tokens = g_strsplit(informacao, ";", -1);

    user_id = g_strdup(tokens[1]);
    music_id = g_strdup(tokens[2]);
    timestamp = g_strdup(tokens[3]);
    duration = g_strdup(tokens[4]);
    
    char *newline_pos = strchr(tokens[5], '\n');
    if (newline_pos) *newline_pos = '\0';
    platform = g_strdup(tokens[5]);

    int check = 1;
    if (verifica_platform(remove_aspas(platform)) == 0)
        check = 0;
    else if (verifica_duration(remove_aspas(duration)) == 0)
        check = 0;
    else if (verifica_timestamp(remove_aspas(timestamp)) == 0)
        check = 0;
    else if (verifica_user_id(remove_aspas(user_id), utilizadores) == 0)
        check = 0;
    else if (verifica_music_id(remove_aspas(music_id), musicas) == 0)
        check = 0;

    //printf("%d, %d, %d\n", verifica_platform(remove_aspas(platform)), verifica_duration(remove_aspas(duration)), verifica_data(remove_aspas(timestamp)));

    free(user_id);
    free(music_id);
    free(timestamp);
    free(duration);
    free(platform);
    g_strfreev(tokens);

    return check;
}