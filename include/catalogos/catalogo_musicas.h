#ifndef CATALOGO_MUSICAS_H
#define CATALOGO_MUSICAS_H

#include <glib.h>
#include "entidades/musicas.h"

typedef struct catalogo *CATALOGO;

CATALOGO create_catalogo_musicas();

/**
 * @brief Cria um catálogo para armazenar músicas.
 *
 * Inicializa e retorna uma tabela de hash que servirá como catálogo
 * para armazenar dados de músicas.
 *
 * @return Um ponteiro para a GHashTable recém-criada, representando o catálogo de músicas.
 */
GHashTable *create_musicas_catalog();

/**
 * @brief Insere uma música no catálogo.
 *
 * Adiciona uma nova música ao catálogo especificado. A música é armazenada
 * usando uma chave (ID da música) para facilitar a recuperação.
 *
 * @param catalogo O catálogo do tipo GHashTable onde a música será inserida.
 * @param musica A música do tipo MUSICA que será adicionada.
 * @param key Uma string representando o ID único da música.
 */
void insert_musica(CATALOGO catalogo, MUSICA musica, char *key);

/**
 * @brief Obtém uma música do catálogo pela sua chave.
 *
 * Pesquisa no catálogo por uma música usando a chave especificada e a retorna.
 * Caso a chave não seja encontrada, a função retorna NULL.
 *
 * @param catalogo O catálogo do tipo GHashTable onde será feita a pesquisa.
 * @param key Uma string representando o ID único da música a ser recuperada.
 * 
 * @return A música associada à chave fornecida ou NULL se não for encontrada.
 */
MUSICA get_musica_by_key(CATALOGO catalogo, char *key);

/**
 * @brief Atualiza uma música no catálogo.
 *
 * Substitui a música associada a uma chave específica no catálogo por uma nova.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser atualizado.
 * @param key Uma string representando o ID único da música a ser atualizada.
 * @param musica A nova música do tipo MUSICA que substituirá a antiga.
 */
void update_musica(CATALOGO catalogo, char *key, MUSICA musica);

/**
 * @brief Libera o catálogo de músicas.
 *
 * Libera toda a memória alocada para o catálogo e seus conteúdos. Isso inclui
 * liberar as chaves, valores e a própria tabela de hash.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser destruído.
 */
void free_musica_catalog(CATALOGO catalogo);

void construir_musica(char *informacao, CATALOGO catalogo);

#endif
