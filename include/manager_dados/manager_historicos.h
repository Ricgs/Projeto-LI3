#ifndef MANAGER_HISTORICOS_H
#define MANAGER_HISTORICOS_H

/**
 @brief adiciona históricos a partir de um ficheiro
 
 @param historicos - A tabela hash onde os históricos serão guardados
 @param utilizadores - A tabela hash de utilizadores
 @param musicas - A tabela hash de músicas
 @param file - O ficheiro com as informações dos históricos
*/
void set_historico(GHashTable *historicos, GHashTable *utilizadores, GHashTable *musicas, FILE *file);



// char *historico_anual(char *user_id, GHashTable *utilizadores, GHashTable *album, GHashTable *artistas, GHashTable *musicas, char *year, int N); query6


#endif
