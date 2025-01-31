#ifndef CATALOGO_UTILIZADORES_H
#define CATALOGO_UTILIZADORES_H

#include <glib.h>
#include "entidades/utilizadores.h"

typedef struct catalogo *CATALOGO;

CATALOGO create_catalogo_utilizadores();

/**
 * @brief Cria um catálogo para armazenar utilizadores.
 *
 * Inicializa e retorna uma tabela de hash que servirá como catálogo
 * para armazenar dados de utilizadores.
 *
 * @return Um ponteiro para a GHashTable recém-criada, representando o catálogo de utilizadores.
 */
GHashTable* create_utilizadores_catalog();

/**
 * @brief Insere um utilizador no catálogo.
 *
 * Adiciona um novo utilizador ao catálogo especificado. O utilizador é armazenado
 * usando uma chave (ID do utilizador) para facilitar a recuperação.
 *
 * @param catalogo O catálogo do tipo GHashTable onde o utilizador será inserido.
 * @param utilizador O utilizador do tipo UTILIZADOR que será adicionado.
 * @param key Uma string representando o ID único do utilizador.
 */
void insert_utilizador(CATALOGO catalogo, UTILIZADOR utilizador, char *key);

/**
 * @brief Obtém um utilizador do catálogo pela sua chave.
 *
 * Pesquisa no catálogo por um utilizador usando a chave especificada e o retorna.
 * Caso a chave não seja encontrada, a função retorna NULL.
 *
 * @param catalogo O catálogo do tipo GHashTable onde será feita a pesquisa.
 * @param key Uma string representando o ID único do utilizador a ser recuperado.
 * 
 * @return O utilizador associado à chave fornecida ou NULL se não for encontrado.
 */
UTILIZADOR get_utilizador_by_key(CATALOGO catalogo, char *key);

/**
 * @brief Atualiza um utilizador no catálogo.
 *
 * Substitui o utilizador associado a uma chave específica no catálogo por um novo.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser atualizado.
 * @param key Uma string representando o ID único do utilizador a ser atualizado.
 * @param utilizador O novo utilizador do tipo UTILIZADOR que substituirá o antigo.
 */
void update_utilizador(CATALOGO catalogo, char *key, UTILIZADOR utilizador);

/**
 * @brief Libera o catálogo de utilizadores.
 *
 * Libera toda a memória alocada para o catálogo e seus conteúdos. Isso inclui
 * liberar as chaves, valores e a própria tabela de hash.
 *
 * @param catalogo O catálogo do tipo GHashTable a ser destruído.
 */
void free_utilizador_catalog(CATALOGO catalogo);

void construir_utilizador(char *informacao, CATALOGO catalogo);

#endif
