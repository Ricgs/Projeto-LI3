#ifndef UTILIZADOR_H
#define UTILIZADOR_H
#include "catalogos/list.h"
#include <glib.h>

/**
 * @brief Estrutura para armazenar os dados de um utilizador.
 */
typedef struct utilizadores *UTILIZADOR;

/**
 * @brief Cria um utilizador.
 * 
 * @return O utilizador criado.
 */
UTILIZADOR criar_utilizador(void);

/**
 * @brief Constrói um utilizador a partir de uma string e insere no catálogo.
 * 
 * @param informacao A string com os dados do utilizador.
 * @param catalogo O catálogo onde o utilizador será inserido.
 */
void construir_utilizador(char *informacao, GHashTable *catalogo);

/**
 * @brief Obtém o nome de utilizador.
 * 
 * @param utilizador O utilizador de onde será obtido o nome.
 * @return O nome de utilizador.
 */
char *get_username(UTILIZADOR utilizador);

/**
 * @brief Define o nome de utilizador.
 * 
 * @param utilizador O utilizador onde será definido o nome.
 * @param value O novo nome de utilizador.
 */
void set_username(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém o email do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtido o email.
 * @return O email do utilizador.
 */
char *get_email(UTILIZADOR utilizador);

/**
 * @brief Define o email do utilizador.
 * 
 * @param utilizador O utilizador onde será definido o email.
 * @param value O novo email.
 */
void set_email(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém o primeiro nome do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtido o primeiro nome.
 * @return O primeiro nome do utilizador.
 */
char *get_first_name(UTILIZADOR utilizador);

/**
 * @brief Define o primeiro nome do utilizador.
 * 
 * @param utilizador O utilizador onde será definido o primeiro nome.
 * @param value O novo primeiro nome.
 */
void set_first_name(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém o apelido do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtido o apelido.
 * @return O apelido do utilizador.
 */
char *get_last_name(UTILIZADOR utilizador);

/**
 * @brief Define o apelido do utilizador.
 * 
 * @param utilizador O utilizador onde será definido o apelido.
 * @param value O novo apelido.
 */
void set_last_name(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém a data de nascimento do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtida a data de nascimento.
 * @return A data de nascimento.
 */
char *get_birth_date(UTILIZADOR utilizador);

/**
 * @brief Define a data de nascimento do utilizador.
 * 
 * @param utilizador O utilizador onde será definida a data de nascimento.
 * @param value A nova data de nascimento.
 */
void set_birth_date(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém o país do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtido o país.
 * @return O país do utilizador.
 */
char *get_country(UTILIZADOR utilizador);

/**
 * @brief Define o país do utilizador.
 * 
 * @param utilizador O utilizador onde será definido o país.
 * @param value O novo país.
 */
void set_country(UTILIZADOR utilizador, char *value);

/**
 * @brief Obtém a lista de músicas com "like" do utilizador.
 * 
 * @param utilizador O utilizador de onde será obtida a lista.
 * @return A lista de IDs de músicas.
 */
GArray *get_liked_musics_id(UTILIZADOR utilizador);

/**
 * @brief Define a lista de músicas com "like" do utilizador.
 * 
 * @param utilizador O utilizador onde será definida a lista.
 * @param value A nova lista de IDs de músicas.
 */
void set_liked_musics_id(UTILIZADOR utilizador, GArray *value);

/**
 brief Obtém a lista de historicos do utilizador.
  
 param utilizador O utilizador de onde será obtida a lista.

List *get_historico(UTILIZADOR utilizador);


 brief Define a lista de historicos do utilizador.
  
 param utilizador O utilizador onde será definida a lista.
 param historico A nova lista de historicos do utilizador.
 
void set_historico_utilizador(UTILIZADOR utilizador, List *historico);
*/
/**
 * @brief Liberta a memória do utilizador.
 * 
 * @param data O utilizador a ser destruído.
 */
void destroi_utilizador(gpointer data);



#endif