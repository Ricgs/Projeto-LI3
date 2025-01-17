#ifndef ARTISTA_H
#define ARTISTA_H

#include <glib.h>

/**
 * @brief Estrutura que representa um artista.
 *
 * Contém informações sobre o ID, nome, receita por reprodução, constituintes, país,
 * tipo, duração da discografia e duração total.
 */
typedef struct artistas
{
    char *id;                     
    char *name;                   
    char *recipe_per_stream;      
    GArray *id_constituent;       
    char *country;                
    char *type;                   
    int discography_duration;     
    int total_duration;           
} *ARTISTA;

/**
 * @brief Cria um novo artista.
 *
 * Inicializa e retorna um artista com todos os campos definidos como nulos ou valores padrão.
 *
 * @return Um ponteiro para o artista recém-criado.
 */
ARTISTA criar_artista(void);

/**
 * @brief Constrói um artista a partir de uma string de informações e insere-o no catálogo.
 *
 * Processa uma string contendo informações do artista, cria a estrutura correspondente
 * e insere-a no catálogo fornecido.
 *
 * @param informacao String contendo os dados do artista separados por ';'.
 * @param catalogo Catálogo onde o artista será inserido.
 */
void construir_artista(char *informacao, GHashTable *catalogo);

/**
 * @brief Obtém o ID do artista.
 *
 * @param artista O artista cujo ID será obtido.
 * @return Uma cópia da string representando o ID do artista.
 */
char *get_artista_id(ARTISTA artista);

/**
 * @brief Define o ID do artista.
 *
 * @param artista O artista cujo ID será definido.
 * @param value A nova string representando o ID do artista.
 */
void set_artista_id(ARTISTA artista, char *value);

/**
 * @brief Obtém o nome do artista.
 *
 * @param artista O artista cujo nome será obtido.
 * @return Uma cópia da string representando o nome do artista.
 */
char *get_name(ARTISTA artista);

/**
 * @brief Define o nome do artista.
 *
 * @param artista O artista cujo nome será definido.
 * @param value A nova string representando o nome do artista.
 */
void set_name(ARTISTA artista, char *value);

/**
 * @brief Obtém a receita por reprodução do artista.
 *
 * @param artista O artista cuja receita será obtida.
 * @return Uma cópia da string representando a receita por reprodução.
 */
char *get_recipe_per_stream(ARTISTA artista);

/**
 * @brief Define a receita por reprodução do artista.
 *
 * @param artista O artista cuja receita será definida.
 * @param value A nova string representando a receita por reprodução.
 */
void set_recipe_per_stream(ARTISTA artista, char *value);

/**
 * @brief Obtém os IDs dos constituintes do artista.
 *
 * @param artista O artista cujos constituintes serão obtidos.
 * @return Uma cópia da GArray contendo os IDs dos constituintes.
 */
GArray *get_id_constituent(ARTISTA artista);

/**
 * @brief Define os IDs dos constituintes do artista.
 *
 * @param artista O artista cujos constituintes serão definidos.
 * @param value Uma GArray contendo os novos IDs dos constituintes.
 */
void set_id_constituent(ARTISTA artista, GArray *value);

/**
 * @brief Obtém o país do artista.
 *
 * @param artista O artista cujo país será obtido.
 * @return Uma cópia da string representando o país do artista.
 */
char *get_country_artista(ARTISTA artista);

/**
 * @brief Define o país do artista.
 *
 * @param artista O artista cujo país será definido.
 * @param value A nova string representando o país do artista.
 */
void set_country_artista(ARTISTA artista, char *value);

/**
 * @brief Obtém o tipo do artista.
 *
 * @param artista O artista cujo tipo será obtido.
 * @return Uma cópia da string representando o tipo do artista.
 */
char *get_type(ARTISTA artista);

/**
 * @brief Define o tipo do artista.
 *
 * @param artista O artista cujo tipo será definido.
 * @param value A nova string representando o tipo do artista.
 */
void set_type(ARTISTA artista, char *value);

/**
 * @brief Obtém a duração da música do artista.
 *
 * @param artista O artista cuja duração será obtida.
 * @return A duração da discografia em minutos.
 */
int get_discography_duration(ARTISTA artista);

/**
 * @brief Adiciona um valor à duração da discografia do artista.
 *
 * @param artista O artista cuja duração será aumentada.
 * @param value O valor a ser adicionado à duração da discografia.
 */
void set_discography_duration(ARTISTA artista, int value);

/**
 * @brief Liberta a memória alocada para um artista.
 *
 * @param data Ponteiro para o artista a ser destruído.
 */
void destroi_artista(gpointer data);

#endif
