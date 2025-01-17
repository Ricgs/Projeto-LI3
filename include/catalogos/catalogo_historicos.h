#ifndef CATALOGO_HISTORICOS_H
#define CATALOGO_HISTORICOS_H

#include <glib.h>
#include "entidades/historicos.h"

/**
 * @brief Cria um catálogo para armazenar históricos.
 *
 * Inicializa e retorna uma tabela de hash que servirá como catálogo
 * para armazenar dados de históricos.
 *
 * @return Um ponteiro para a GHashTable recém-criada, representando o catálogo de históricos.
 */
GHashTable* create_historicos_catalog();

/**
 * @brief Insere um histórico no catálogo.
 *
 * Adiciona um novo histórico ao catálogo especificado. O histórico é armazenado
 * usando uma chave (ID do histórico) para facilitar a recuperação.
 *
 * @param catalogo O catálogo do tipo GHashTable onde o histórico será inserido.
 * @param historico O histórico do tipo HISTORICO que será adicionado.
 * @param key Uma string representando o ID único do histórico.
 */
void insert_historico(GHashTable *catalogo, HISTORICO historico, char *key);

/**
 * @brief Obtém um histórico do catálogo pela sua chave.
 *
 * Pesquisa no catálogo por um histórico usando a chave especificada e o retorna.
 * Caso a chave não seja encontrada, a função retorna NULL.
 *
 * @param catalogo O catálogo do tipo GHashTable onde será feita a pesquisa.
 * @param key Uma string representando o ID único do histórico a ser recuperado.
 * 
 * @return O histórico associado à chave fornecida ou NULL se não for encontrado.
 */
HISTORICO get_historico_by_key(GHashTable *catalogo, char *key);

/**
 * @brief Atualiza um histórico no catálogo.
 *
 * Substitui o histórico associado a uma chave específica no catálogo por um novo.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser atualizado.
 * @param key Uma string representando o ID único do histórico a ser atualizado.
 * @param historico O novo histórico do tipo HISTORICO que substituirá o antigo.
 */
void update_historico(GHashTable *catalogo, char *key, HISTORICO historico);

/**
 * @brief Libera o catálogo de históricos.
 *
 * Libera toda a memória alocada para o catálogo e seus conteúdos. Isso inclui
 * liberar as chaves, valores e a própria tabela de hash.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser destruído.
 */
void free_historico_catalog(GHashTable *catalogo);

#endif
