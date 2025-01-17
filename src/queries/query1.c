#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "entidades/artistas.h"
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "entidades/albums.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "queries/query1.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "modos_execucao/modo_batch.h"

int calcular_idade(char* birth_date)
{
    int ano, mes, dia, idade;
    sscanf(birth_date, "%4d/%2d/%2d", &ano, &mes, &dia);
    
    int ano_atual = 2024, mes_atual = 9, dia_atual = 9;
    
    idade = ano_atual - ano;

    if (mes > mes_atual || (mes == mes_atual && dia > dia_atual)) {
        idade--;
    }

    return idade;
}

void aux1(gpointer key, gpointer value, gpointer user_data) {
    gpointer *data = (gpointer *)user_data;
    int *num_albums = (int *)data[0];
    char *artist_id = (char *)data[1];
    ALBUM album = (ALBUM)value;

    GArray *id_objetivo = album->artists_id;

    for (guint i = 0; i < id_objetivo->len; i++) {
        char *id = g_array_index(id_objetivo, char *, i);

        if (strcmp(id, artist_id) == 0) {
            (*num_albums)++;
        }
    }
}


char* execute_query1(int numlinha, char *arg, GHashTable *utilizadores, GHashTable *artistas, GHashTable *albums)
{
    /*//---------------------ESCREVER FICHEIRO---------------------
    char query1_path[60];
    char numero[10];
    sprintf(numero, "%d", numlinha);
    strcpy(query1_path, "resultados/command");
    strcat(query1_path, numero);
    strcat(query1_path, "_output.txt");

    char *query1_ficheiro = strdup(query1_path);
    FILE *ficheiro = fopen(query1_ficheiro, "w");
    if (ficheiro == NULL)
    {
        perror("Erro ao abrir o arquivo de erros");
        free(query1_ficheiro);
    }
    */

    // Inicializa uma string para armazenar o resultado
    char *result = malloc(1024 * sizeof(char)); // Tamanho inicial arbitrário
    if (!result) {
        perror("Failed to allocate memory for result");
        return NULL;
    }
    result[0] = '\0'; // Garante que a string está vazia inicialmente

    if(arg[0] == 'U'){
        UTILIZADOR utilizador_novo = get_utilizador_by_key(utilizadores, arg);
        if (utilizador_novo != NULL)
        {
            char *email = get_email(utilizador_novo);
            char *first_name = get_first_name(utilizador_novo);
            char *last_name = get_last_name(utilizador_novo);
            char *birth_date = get_birth_date(utilizador_novo);
            char *country = get_country(utilizador_novo);

            int age = calcular_idade(birth_date);

            char age_str[12]; // Buffer suficiente para armazenar um número inteiro como string
            snprintf(age_str, sizeof(age_str), "%d", age);

            size_t needed_space = strlen(result) + strlen(email) + strlen(first_name) + strlen(last_name) + strlen(age_str) + strlen(country) + 6;

            // Realoca a string se necessário
            char *temp = realloc(result, needed_space);
            if (!temp) {
                perror("Failed to reallocate memory for result");
                free(email);
                free(first_name);
                free(last_name);
                free(birth_date);
                free(country);
                free(result);
                return NULL;
            }
            result = temp;

            strcat(result, email);
            strcat(result, ";");
            strcat(result, first_name);
            strcat(result, ";");
            strcat(result, last_name);
            strcat(result, ";");
            strcat(result, age_str);
            strcat(result, ";");
            strcat(result, country);
            strcat(result, "\n");           
                
            free(email);
            free(first_name);
            free(last_name);
            free(birth_date);
            free(country);

            return result;
        } 
        else 
        {
            free(result);
        }    
    }
    else {
        ARTISTA artista_novo = get_artista_by_key(artistas, arg);
        if (artista_novo != NULL)
        {
            char *artist_id = get_artista_id(artista_novo);
            char *name = get_name(artista_novo);
            char *type = get_type(artista_novo);
            char *country = get_country_artista(artista_novo);
            
            int num_albums = 0;

            gpointer data[2] = {&num_albums, artist_id};

            g_hash_table_foreach(albums, aux1, data);

            char num_albums_str[12]; // Buffer suficiente para armazenar um número inteiro como string
            snprintf(num_albums_str, sizeof(num_albums_str), "%d", num_albums);

            size_t needed_space = strlen(result) + strlen(name) + strlen(type) + strlen(country) + strlen(num_albums_str) + 6;

            // Realoca a string se necessário
            char *temp = realloc(result, needed_space);
            if (!temp) {
                perror("Failed to reallocate memory for result");
                free(artist_id);
                free(name);
                free(type);
                free(country);
                free(result);
                return NULL;
            }
            result = temp;

            strcat(result, name);
            strcat(result, ";");
            strcat(result, type);
            strcat(result, ";");
            strcat(result, country);
            strcat(result, ";");
            strcat(result, num_albums_str);
            strcat(result, ";");
            strcat(result, "\n");        
            
            free(name);
            free(type);
            free(country);
            free(artist_id);

            return result;
            
        } 
        else 
        {
            free(result);
        }    
    }
    return NULL;
}