#ifndef HISTORICO_H
#define HISTORICO_H

#include <glib.h>
#include "entidades/artistas.h"

/**
 * @brief Estrutura que representa um histórico.
 *
 * Contém informações sobre o ID, id de utilizador, id de música, data e hora da reprodução e duração.
 */
typedef struct historicos *HISTORICO;

/**
 * @brief Cria um histórico.
 * 
 * @return O histórico criado.
 */
HISTORICO criar_historico(void);

/**
 * @brief Constrói um histórico a partir de uma string e insere no catálogo.
 * 
 * @param informacao A string com os dados do histórico.
 * @param catalogo O catálogo onde o histórico será inserido.
 */
void construir_historico(char *informacao, GHashTable *catalogo, GHashTable *HISTORICO);

/**
 * @brief Obtém o ID do histórico.
 * 
 * @param historico O histórico de onde será obtido o ID.
 * @return O ID do histórico.
 */
char *get_historico_id(HISTORICO historico);

/**
 * @brief Define o ID do histórico.
 * 
 * @param historico O histórico onde será definido o ID.
 * @param value O novo ID.
 */
void set_historico_id(HISTORICO historico, char *value);

/**
 * @brief Obtém o ID do utilizador associado ao histórico.
 * 
 * @param historico O histórico de onde será obtido o ID do utilizador.
 * @return O ID do utilizador.
 */
char *get_user_id(HISTORICO historico);

/**
 * @brief Define o ID do utilizador associado ao histórico.
 * 
 * @param historico O histórico onde será definido o ID do utilizador.
 * @param value O novo ID do utilizador.
 */
void set_user_id(HISTORICO historico, char *value);

/**
 * @brief Obtém o ID da música associada ao histórico.
 * 
 * @param historico O histórico de onde será obtido o ID da música.
 * @return O ID da música.
 */
char *get_h_music_id(HISTORICO historico);

/**
 * @brief Define o ID da música associada ao histórico.
 * 
 * @param historico O histórico onde será definido o ID da música.
 * @param value O novo ID da música.
 */
void set_h_music_id(HISTORICO historico, char *value);

/**
 * @brief Obtém o timestamp do histórico.
 * 
 * @param historico O histórico de onde será obtido o timestamp.
 * @return O timestamp.
 */
char *get_timestamp(HISTORICO historico);

/**
 * @brief Define o timestamp do histórico.
 * 
 * @param historico O histórico onde será definido o timestamp.
 * @param value O novo timestamp.
 */
void set_timestamp(HISTORICO historico, char *value);

/**
 * @brief Obtém a duração do histórico.
 * 
 * @param historico O histórico de onde será obtida a duração.
 * @return A duração.
 */
char *get_h_duration(HISTORICO historico);

/**
 * @brief Define a duração do histórico.
 * 
 * @param historico O histórico onde será definida a duração.
 * @param value A nova duração.
 */
void set_h_duration(HISTORICO historico, char *value);


/** query6
 brief Insere historico nal lista do utilizador.
  
 param historico O histórico que será adicionado.
 param utilizadores GHashTable onde será procurado o utilizador.
 
void insere_historico_utilizador(GHashTable *utilizadores, HISTORICO historico); 
*/

/**
 * @brief Liberta a memória do histórico.
 * 
 * @param data O histórico a ser destruído.
 */
void destroi_historico(gpointer data);

#endif
