#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "entidades/artistas.h"
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_musicas.h"
#include "queries/query3.h"
#include "queries/query1.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "modos_execucao/modo_batch.h"

void aux(gpointer key, gpointer value, gpointer user_data) {
    gpointer *data = (gpointer *)user_data;
    UTILIZADOR utilizador = (UTILIZADOR)value;
    GHashTable *musicas = (GHashTable *)data[1];
    int *limites = (int *)data[0];
    int idade_min = limites[0];
    int idade_max = limites[1];

    int idade_utilizador = calcular_idade(utilizador->birth_date);

    if (idade_utilizador >= idade_min && idade_utilizador <= idade_max) {
        GArray *likes = utilizador->liked_musics_id;

        for (guint i = 0; i < likes->len; i++) {
            char *id = g_array_index(likes, char *, i);
            MUSICA musica = get_musica_by_key(musicas, id);
            if (!musica) continue;

            char *genre = get_genre(musica);

            if (strcmp(genre, "Blues") == 0) limites[2]++;
            else if (strcmp(genre, "Electronic") == 0) limites[3]++;
            else if (strcmp(genre, "Jazz") == 0) limites[4]++;
            else if (strcmp(genre, "Reggae") == 0) limites[5]++;
            else if (strcmp(genre, "Rock") == 0) limites[6]++;
            else if (strcmp(genre, "Pop") == 0) limites[7]++;
            else if (strcmp(genre, "Classical") == 0) limites[8]++;
            else if (strcmp(genre, "Hip Hop") == 0) limites[9]++;
            else if (strcmp(genre, "Metal") == 0) limites[10]++;
            else if (strcmp(genre, "Country") == 0) limites[11]++;
            free(genre);
        }
    }
}

char *escrever_generos_ordenados(int objetivos[]) {

    char *result = malloc(10); // Tamanho inicial arbitrário
    if (!result) {
        perror("Failed to allocate memory for result");
        return NULL;
    }
    result[0] = '\0'; // Garante que a string está vazia inicialmente

    if (objetivos[2] != 0) {
        const char *generos[] = {
            "Blues", "Electronic", "Jazz", "Reggae",
            "Rock", "Pop", "Classical", "Hip Hop",
            "Metal", "Country"
        };

        int num_generos = 10;
        int *valores = malloc(num_generos * sizeof(int));
        for (int i = 0; i < num_generos; i++) {
            valores[i] = objetivos[i + 2];
        }

        // Ordenação dos géneros por popularidade
        for (int i = 0; i < num_generos - 1; i++) {
            for (int j = 0; j < num_generos - i - 1; j++) {
                if (valores[j] < valores[j + 1]) {
                    int temp_valor = valores[j];
                    valores[j] = valores[j + 1];
                    valores[j + 1] = temp_valor;

                    const char *temp_genero = generos[j];
                    generos[j] = generos[j + 1];
                    generos[j + 1] = temp_genero;
                }
            }
        }

        // Construção da string de saída
        for (int i = 0; i < num_generos; i++) {
            if (valores[i] > 0) {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "%s;%d\n", generos[i], valores[i]);

                size_t needed_space = strlen(result) + strlen(buffer) + 1;

                char *temp = realloc(result, needed_space);
                if (!temp) {
                    perror("Failed to reallocate memory for result");
                    free(valores);
                    free(result);
                    return NULL;
                }
                result = temp;

                strcat(result, buffer);
            }
        }
        free(valores);
    }
    return result;
}

char* execute_query3(int numlinha, char *arg, GHashTable *utilizadores, GHashTable *musicas) {
    // Inicializa uma string para armazenar o resultado
    char *result; 
    int idade_min, idade_max;
    sscanf(arg, "%d %d", &idade_min, &idade_max);

    int objetivos[12] = {idade_min, idade_max, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gpointer data[2] = {objetivos, musicas};

    g_hash_table_foreach(utilizadores, aux, data);

    if (objetivos[2] != 0) {
        result = escrever_generos_ordenados(objetivos);
    } else {
        return NULL;
    }

    return result;
}
