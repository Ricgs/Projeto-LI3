#ifndef MANAGER_MUSICAS_H
#define MANAGER_MUSICAS_H

/**
 @brief adiciona músicas a partir de um ficheiro
 
 @param musicas - A tabela hash onde as músicas serão guardadas
 @param file - O ficheiro com as informações das músicas
 @param artistas - A tabela hash de artistas
 @param albums - A tabela hash de álbuns
*/
void set_musica(GHashTable *musicas, FILE *file, GHashTable *artistas, GHashTable *albums);

#endif
