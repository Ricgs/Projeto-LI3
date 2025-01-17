#ifndef MANAGER_UTILIZADORES_H
#define MANAGER_UTILIZADORES_H

/**
 @brief adiciona utilizadores a partir de um ficheiro
 
 @param utilizadores - A tabela hash onde os utilizadores serão guardados
 @param file - O ficheiro com as informações dos utilizadores
 @param musicas - A tabela hash de músicas
*/
void set_utilizador(GHashTable *utilizadores, FILE *file, GHashTable *musicas);

#endif
