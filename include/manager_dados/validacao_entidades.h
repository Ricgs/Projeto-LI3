#ifndef VALIDACAO_H
#define VALIDACAO_H

/**
 @brief verifica se a data é válida
 @param data - A data a ser verificada
 @return 1 se válida, 0 caso contrário
*/
int verifica_data(char *data);

/**
 @brief verifica se a duração é válida
 @param duration - A duração a ser verificada
 @return 1 se válida, 0 caso contrário
*/
int verifica_duration(char *duration);

/**
 @brief verifica se o email é válido
 @param email - O email a ser verificado
 @return 1 se válido, 0 caso contrário
*/
int verifica_email(char *email);

/**
 @brief verifica se o tipo de subscrição é válido
 @param subscription_type - O tipo de subscrição a ser verificado
 @return 1 se válido, 0 caso contrário
*/
int verifica_subscription_type(char *subscription_type);

/**
 @brief verifica se os delimitadores estão corretos
 @param lista - A lista a ser verificada
 @return 1 se válida, 0 caso contrário
*/
int verifica_delimitadores(char *lista);

/**
 @brief verifica se a plataforma é válida
 @param platform - A plataforma a ser verificada
 @return 1 se válida, 0 caso contrário
*/
int verifica_platform(char *platform);

/**
 @brief verifica se o tipo é válido
 @param type - O tipo a ser verificado
 @return 1 se válido, 0 caso contrário
*/
int verifica_type(char *type);

/**
 @brief verifica se o timestamp é válido
 @param timestamp - O timestamp a ser verificado
 @return 1 se válido, 0 caso contrário
*/
int verifica_timestamp(char *timestamp);

/**
 @brief verifica o id de constituinte
 @param id_constituent - O id de constituinte a ser verificado
 @param type - O tipo a ser usado na verificação
 @return 1 se válido, 0 caso contrário
*/
int verifica_id_constituent(GArray* id_constituent, char* type);

/**
 @brief verifica se o id do artista é válido
 @param artist_id - O id do artista a ser verificado
 @param artistas - A tabela de artistas
 @return 1 se válido, 0 caso contrário
*/
int verifica_artist_id(GArray* artist_id, GHashTable *artistas);

/**
 @brief verifica os ids das músicas curtidas
 @param liked_musics_id - Os ids das músicas curtidas
 @param musicas - A tabela de músicas
 @return 1 se válido, 0 caso contrário
*/
int verifica_liked_musics_id(GArray* liked_musics_id, GHashTable *musicas);

/**
 @brief verifica se o álbum é válido
 @param album - O id do álbum a ser verificado
 @param albums - A tabela de álbuns
 @return 1 se válido, 0 caso contrário
*/
int verifica_album(char *album, GHashTable *albums);

/**
 @brief verifica se o id do utilizador é válido
 @param user_id - O id do utilizador
 @param utilizadores - A tabela de utilizadores
 @return 1 se válido, 0 caso contrário
*/
int verifica_user_id(char *user_id, GHashTable *utilizadores);

/**
 @brief verifica se o id da música é válido
 @param music_id - O id da música
 @param musicas - A tabela de músicas
 @return 1 se válido, 0 caso contrário
*/
int verifica_music_id(char *music_id, GHashTable *musicas);

/**
 @brief verifica se o artista é válido
 @param informacao - A informação do artista
 @return 1 se válido, 0 caso contrário
*/
int artista_valido(char *informacao);

/**
 @brief verifica se o utilizador é válido
 @param informacao - A informação do utilizador
 @param musicas - A tabela de músicas
 @return 1 se válido, 0 caso contrário
*/
int utilizador_valido(char *informacao, GHashTable *musicas);

/**
 @brief verifica se a música é válida
 @param informacao - A informação da música
 @param artistas - A tabela de artistas
 @param albums - A tabela de álbuns
 @return 1 se válida, 0 caso contrário
*/
int musica_valida(char *informacao, GHashTable *artistas, GHashTable *albums);

/**
 @brief verifica se o histórico é válido
 @param informacao - A informação do histórico
 @param utilizadores - A tabela de utilizadores
 @param musicas - A tabela de músicas
 @return 1 se válido, 0 caso contrário
*/
int historico_valido(char *informacao, GHashTable *utilizadores, GHashTable *musicas);

#endif
