#ifndef CATALOGO_ARTISTAS_H
#define CATALOGO_ARTISTAS_H

#include <glib.h>
#include "entidades/artistas.h"

/**
 * @brief Cria um catálogo para armazenar artistas.
 *
 * Inicializa e retorna uma tabela de hash que servirá como catálogo
 * para armazenar dados de artistas.
 *
 * @return Um ponteiro para a GHashTable recém-criada, representando o catálogo de artistas.
 */
GHashTable* create_artistas_catalog();

/**
 * @brief Insere um artista no catálogo.
 *
 * Adiciona um novo artista ao catálogo especificado. O artista é armazenado
 * usando uma chave (ID do artista) para facilitar a recuperação.
 *
 * @param catalogo O catálogo do tipo GHashTable onde o artista será inserido.
 * @param artista O artista do tipo ARTISTA que será adicionado.
 * @param key Uma string representando o ID único do artista.
 */
void insert_artista(GHashTable *catalogo, ARTISTA artista, char *key);

/**
 * @brief Obtém um artista do catálogo pela sua chave.
 *
 * Pesquisa no catálogo por um artista usando a chave especificada e o retorna.
 * Caso a chave não seja encontrada, a função retorna NULL.
 *
 * @param catalogo O catálogo do tipo GHashTable onde será feita a pesquisa.
 * @param key Uma string representando o ID único do artista a ser recuperado.
 * 
 * @return O artista associado à chave fornecida ou NULL se não for encontrado.
 */
ARTISTA get_artista_by_key(GHashTable *catalogo, char *key);

/**
 * @brief Atualiza um artista no catálogo.
 *
 * Substitui o artista associado a uma chave específica no catálogo por um novo.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser atualizado.
 * @param key Uma string representando o ID único do artista a ser atualizado.
 * @param artista O novo artista do tipo ARTISTA que substituirá o antigo.
 */
void update_artista(GHashTable *catalogo, char *key, ARTISTA artista);

/**
 * @brief Libera o catálogo de artistas.
 *
 * Libera toda a memória alocada para o catálogo e seus conteúdos. Isso inclui
 * liberar as chaves, valores e a própria tabela de hash.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser destruído.
 */
void free_artista_catalog(GHashTable *catalogo);

#endif
