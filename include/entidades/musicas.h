#ifndef MUSICA_H
#define MUSICA_H

#include <glib.h>

/**
 * @brief Estrutura para armazenar os dados de uma música.
 */
typedef struct musicas *MUSICA;

/**
 * @brief Cria uma música.
 * 
 * @return A música criada.
 */
MUSICA criar_musica(void);

/**
 * @brief Constrói uma música a partir de uma string e insere no catálogo.
 * 
 * @param informacao A string com os dados da música.
 * @param catalogo O catálogo onde a música será inserida.
 */
void construir_musica(char *informacao, GHashTable *catalogo);

/**
 * @brief Obtém o ID da música.
 * 
 * @param musicas A música de onde será obtido o ID.
 * @return O ID da música.
 */
char *get_music_id(MUSICA musicas);

/**
 * @brief Define o ID da música.
 * 
 * @param musicas A música onde será definido o ID.
 * @param value O novo ID.
 */
void set_music_id(MUSICA musicas, char *value);

/**
 * @brief Obtém o título da música.
 * 
 * @param musicas A música de onde será obtido o título.
 * @return O título da música.
 */
char *get_title(MUSICA musicas);

/**
 * @brief Define o título da música.
 * 
 * @param musicas A música onde será definido o título.
 * @param value O novo título.
 */
void set_title(MUSICA musicas, char *value);

/**
 * @brief Obtém os IDs dos artistas da música.
 * 
 * @param musicas A música de onde serão obtidos os IDs dos artistas.
 * @return Os IDs dos artistas.
 */
GArray *get_artist_id(MUSICA musicas); 

/**
 * @brief Define os IDs dos artistas da música.
 * 
 * @param musicas A música onde serão definidos os IDs dos artistas.
 * @param value Os novos IDs dos artistas.
 */
void set_artist_id(MUSICA musicas, GArray *value);

/**
 * @brief Obtém o ID do álbum da música.
 * 
 * @param musicas A música de onde será obtido o ID do álbum.
 * @return O ID do álbum.
 */
char *get_m_album_id(MUSICA musicas);

/**
 * @brief Define o ID do álbum da música.
 * 
 * @param musicas A música onde será definido o ID do álbum.
 * @param value O novo ID do álbum.
 */
void set_m_album_id(MUSICA musicas, char *value);

/**
 * @brief Obtém a duração da música.
 * 
 * @param musicas A música de onde será obtida a duração.
 * @return A duração da música.
 */
char *get_duration(MUSICA musicas);

/**
 * @brief Define a duração da música.
 * 
 * @param musicas A música onde será definida a duração.
 * @param value A nova duração.
 */
void set_duration(MUSICA musicas, char *value);

/**
 * @brief Obtém o género da música.
 * 
 * @param musicas A música de onde será obtido o género.
 * @return O género da música.
 */
char *get_genre(MUSICA musicas);

/**
 * @brief Define o género da música.
 * 
 * @param musicas A música onde será definido o género.
 * @param value O novo género.
 */
void set_genre(MUSICA musicas, char *value);

/**
 * @brief Obtém o ano da música.
 * 
 * @param musicas A música de onde será obtido o ano.
 * @return O ano da música.
 */
char *get_year(MUSICA musicas);

/**
 * @brief Define o ano da música.
 * 
 * @param musicas A música onde será definido o ano.
 * @param value O novo ano.
 */
void set_year(MUSICA musicas, char *value);

/**
 * @brief Liberta a memória da música.
 * 
 * @param data A música a ser destruída.
 */
void destroi_musica(gpointer data);

#endif
