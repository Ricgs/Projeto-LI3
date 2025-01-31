#include "entidades/semana.h"
#include "entidades/artistas.h"
#include "catalogos/catalogo_artistas.h"
#include "utils/calculos.h"
#include <glib.h>
#include <stdio.h>
#include "catalogos/list.h"

struct semana {
    char *semana;           /**< Identificação da semana. */
    ARTISTA *top_artistas[10]; /**< Array com os top 10 artistas da semana. */
};

/*
SEMANA create_semana(const char *semana_id) {
    SEMANA new_semana = malloc(sizeof(struct semana));
    if (!new_semana) return NULL;

    new_semana->semana = strdup(semana_id);
    memset(new_semana->top_artistas, 0, sizeof(new_semana->top_artistas));
    return new_semana;
}

// Getter for semana field
char *get_semana_id(SEMANA semana) {
    return semana ? semana->semana : NULL;
}

// Getter for top_artistas
ARTISTA get_top_artista(SEMANA semana, int index) {
    if (!semana || index < 0 || index >= 10) return NULL;
    return semana->top_artistas[index];
}

// Setter for top_artistas
void set_top_artista(SEMANA semana, ARTISTA artista, int index) {
    if (semana && index >= 0 && index < 10) {
        semana->top_artistas[index] = artista;
    }
}



// Helper function to insert an artist into the top 10
void insert_top_artista(SEMANA semana, ARTISTA artista, int tempo_reproducao) {
    for (int i = 0; i < 10; i++) {
        if (!semana->top_artistas[i] || semana->top_artistas[i]->tempo_reproducao < tempo_reproducao ||
            (semana->top_artistas[i]->tempo_reproducao == tempo_reproducao && strcmp(semana->top_artistas[i]->id, artista->id) > 0)) {

            memmove(&semana->top_artistas[i + 1], &semana->top_artistas[i], (9 - i) * sizeof(ARTISTA *));
            semana->top_artistas[i] = artista;
            break;
        }
    }
}
*/