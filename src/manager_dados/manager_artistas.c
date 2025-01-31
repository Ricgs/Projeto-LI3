#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/artistas.h"
#include "entidades/musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_artistas.h"
#include "catalogos/list.h"
#include "utils/calculos.h"

void processa_linha_artista(CATALOGO artistas, FILE *pasta_erros_artistas, char *linha) {
    if (artista_valido(linha) == 1)
        construir_artista(linha, artistas);
    else
        fprintf(pasta_erros_artistas, "%s", linha);
}

void set_artista(CATALOGO artistas, FILE *file) {
    char *erros_artistas = cria_erros("resultados/artists_errors.csv");
    FILE *pasta_erros_artistas = cria_ficheiro(erros_artistas);

    char *linha;
    while ((linha = ler_linha(file)) != NULL) {
        processa_linha_artista(artistas, pasta_erros_artistas, linha);
        free(linha);
    }
    free(erros_artistas);
    fclose(pasta_erros_artistas);
}


/*void set_artista(GHashTable *artistas, FILE *file) {
    char *erros_artistas = cria_erros("resultados/artists_errors.csv");
    FILE *pasta_erros_artistas = cria_ficheiro(erros_artistas);

    char **linhas = NULL;
    int n = ler_ficheiro(file, &linhas);

    for (int i = 0; i < n; i++) {
        if (artista_valido(linhas[i]) == 1)
            construir_artista(linhas[i], artistas);
        else
            fprintf(pasta_erros_artistas, "%s", linhas[i]);
    }

    for (int i = 0; i < n; i++) {
        free(linhas[i]);
    }

    free(linhas);
    free(erros_artistas);
    fclose(pasta_erros_artistas);
}
*/


List *merge_sorted_lists(List *a, List *b) {
    if (!a) return b;
    if (!b) return a;

    // Validate data pointers
    if (!a->data || !b->data) {
        return a ? a : b;
    }

    ARTISTA artist_a = (ARTISTA)a->data;
    ARTISTA artist_b = (ARTISTA)b->data;

    if (!artist_a || !artist_b) {
        return NULL;
    }

    List *result = NULL;

    if (get_discography_duration(artist_a) > get_discography_duration(artist_b)||
        (get_discography_duration(artist_a)== get_discography_duration(artist_b) &&
         strcmp(artist_a->id, artist_b->id) < 0)) {
        result = a;
        result->next = merge_sorted_lists(a->next, b);
    } else {
        result = b;
        result->next = merge_sorted_lists(a, b->next);
    }

    // Check result node
    if (!result || !result->data) {
        printf("Error: Result node or data is NULL\n");
    }

    return result;
}


void split_list(List *source, List **front, List **back) {
    if (!source || !source->next) {
        *front = source;
        *back = NULL;
        return;
    }

    List *slow = source;
    List *fast = source->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}



List* merge_sort(List* head) {
    if (!head || !head->next) {
        return head;
    }

    List* front = NULL;
    List* back = NULL;
    split_list(head, &front, &back);

    front = merge_sort(front);  // Recursively sort the front half

    back = merge_sort(back);    // Recursively sort the back half

    List* ola = merge_sorted_lists(front, back);  // Merge the two halves

    return ola;  // Return the merged sorted list
}





void sort_by_discography_duration(List **head) {

    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    List **list = head;
    *head = merge_sort(*list);
}

List *top_artists(GHashTable *musicas, GHashTable *artistas) {
    GHashTableIter iter;
    gpointer key, value;
    
    List *arts = listCreate(NULL);
    g_hash_table_iter_init(&iter, musicas);
    

    while (g_hash_table_iter_next(&iter, &key, &value)) {
        MUSICA musica = (MUSICA)value;
        GArray *artistas_ids = get_artist_id(musica);

        for (guint i = 0; i < artistas_ids->len; i++) {
            char *id = g_array_index(artistas_ids, char *, i);
            ARTISTA current_artist = NULL;

            // Search for the artist in the list
            List *current = arts;
            while (current) {
                if (current->data != NULL && strcmp(id, ((ARTISTA)current->data)->id) == 0) {
                    current_artist = (ARTISTA)current->data;
                    break;
                }
                current = current->next;
            }

            char *duracao = get_duration(musica);

            if (current_artist != NULL) {
                // If the artist is found, update their discography duration
                current_artist->discography_duration += convert_duracao_to_seconds(duracao);
            } else {
                // If not, create a new artist entry
                ARTISTA artist = g_hash_table_lookup(artistas, id);

                set_discography_duration(artist, convert_duracao_to_seconds(duracao));

                insertlist(arts, artist);
            }
            free(duracao);
        }
        g_array_free(artistas_ids, TRUE);
    }

    List *temp = arts;
    arts = temp->next;
    free(temp);


    sort_by_discography_duration(&arts);

    return arts;
}



char *get_top_artists(List *list, int N) {
    // Inicializa uma string para armazenar o resultado
    char *result = malloc(1024 * sizeof(char)); // Tamanho inicial arbitrário
    if (!result) {
        perror("Failed to allocate memory for result");
        return NULL;
    }
    result[0] = '\0'; // Garante que a string está vazia inicialmente

    List *current = list;
    for (int i = 0; i < N && current != NULL && current->data != NULL; i++) {
        char time[32]; // Buffer para o tempo como string
        s_to_h(get_discography_duration((ARTISTA)current->data), time);
        char *country = get_country_artista((ARTISTA)current->data);

        // Obtem os detalhes do artista
        char *name = get_name((ARTISTA)current->data);
        char *type = get_type((ARTISTA)current->data);

        // Calcula o espaço necessário para adicionar este artista à string
        size_t needed_space = strlen(result) + strlen(name) + strlen(type) + strlen(time) + strlen(country) + 5;

        // Realoca a string se necessário
        char *temp = realloc(result, needed_space);
        if (!temp) {
            perror("Failed to reallocate memory for result");
            free(name);
            free(type);
            free(result);
            free(country);
            return NULL;
        }
        result = temp;

        // Adiciona os detalhes do artista à string resultante
        strcat(result, name);
        strcat(result, ";");
        strcat(result, type);
        strcat(result, ";");
        strcat(result, time);
        strcat(result, ";");
        strcat(result, country);
        strcat(result, "\n");
        free(name);
        free(type);
        current = current->next;
        free(country);
    }

    return result;
}


char *get_top_artists_country(List *list, int N, char *country_filter) {
    // Inicializa uma string para armazenar o resultado
    size_t buffer_size = 1024;
    char *result = malloc(buffer_size);
    if (!result) {
        perror("Failed to allocate memory for result");
        return NULL;
    }
    result[0] = '\0'; // Garante que a string está vazia inicialmente
    size_t current_length = 0;

    List *current = list;
    for (int i = 0; i < N && current != NULL && current->data != NULL;) {
        char *country = get_country_artista((ARTISTA)current->data);
        if (!country) {
            continue; // Ignora artistas sem país definido
        }

        if (strcmp(country, country_filter) == 0) {

            char time[32]; // Buffer para o tempo como string
            s_to_h(get_discography_duration((ARTISTA)current->data), time);

            // Obtem os detalhes do artista
            char *name = get_name((ARTISTA)current->data);
            char *type = get_type((ARTISTA)current->data);

            if (!name || !type) {
                free(name);
                free(type);
                free(country);
                continue; // Ignora artistas com informações incompletas
            }

            // Calcula o espaço necessário
            size_t needed_space = current_length + strlen(name) + strlen(type) + strlen(time) + strlen(country) + 5;
            if (needed_space > buffer_size) {
                // Realoca a string se necessário
                char *temp = realloc(result, needed_space);
                if (!temp) {
                    perror("Failed to reallocate memory for result");
                    free(name);
                    free(type);
                    free(result);
                    free(country);
                    return NULL;
                }
                result = temp;
                buffer_size = needed_space;
            }

            // Adiciona os detalhes do artista à string resultante
            strcat(result, name);
            strcat(result, ";");
            strcat(result, type);
            strcat(result, ";");
            strcat(result, time);
            strcat(result, ";");
            strcat(result, country);
            strcat(result, "\n");

            free(name);
            free(type);
            current_length = strlen(result);
            i++;
        }

        current = current->next;
        free(country);
    }

    return result;
}
