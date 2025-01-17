#ifndef MANAGER_ALBUMS_H
#define MANAGER_ALBUMS_H

/**
 @brief adiciona álbuns a partir de um ficheiro
 
 @param albums - A tabela hash onde os álbuns serão guardados
 @param file - O ficheiro com as informações dos álbuns
*/
void set_album(GHashTable *albums, FILE *file);

#endif
