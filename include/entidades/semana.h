#ifndef SEMANA_H
#define SEMANA_H

#include "entidades/artistas.h"
#include <glib.h>

/**
 * @brief Estrutura para armazenar os dados de uma semana.
 */
typedef struct semana {
    char *semana;           /**< Identificação da semana. */
    ARTISTA *top_artistas[10]; /**< Array com os top 10 artistas da semana. */
} *SEMANA;

/**
 * @brief Cria uma nova semana.
 * 
 * @param semana_id A identificação da semana.
 * @return A nova semana criada.
 */
SEMANA create_semana(const char *semana_id);

/**
 * @brief Obtém a identificação da semana.
 * 
 * @param semana A semana de onde será obtida a identificação.
 * @return A identificação da semana.
 */
char *get_semana_id(SEMANA semana);

/**
 * @brief Obtém um artista do top 10 da semana.
 * 
 * @param semana A semana de onde será obtido o artista.
 * @param index O índice do artista no top 10 (0-9).
 * @return O artista no índice especificado.
 */
ARTISTA get_top_artista(SEMANA semana, int index);

/**
 * @brief Define um artista no top 10 da semana.
 * 
 * @param semana A semana onde será definido o artista.
 * @param artista O artista a ser definido.
 * @param index O índice onde o artista será colocado (0-9).
 */
void set_top_artista(SEMANA semana, ARTISTA artista, int index);

/**
 * @brief Insere um artista no top 10 da semana com base no tempo de reprodução.
 * 
 * @param semana A semana onde o artista será inserido.
 * @param artista O artista a ser inserido.
 * @param tempo_reproducao O tempo de reprodução do artista.
 */
void insert_top_artista(SEMANA semana, ARTISTA artista, int tempo_reproducao);

#endif
