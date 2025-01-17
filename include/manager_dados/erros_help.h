#ifndef ERROS_HELP_H
#define ERROS_H

/**
 @brief cria um string com o nome do ficheiro de erros
 
 @param diretoria - A diretoria onde o ficheiro será criado

 @return A string com o nome do ficheiro
*/
char *cria_erros(char *diretoria);

/**
 @brief abre um ficheiro para registo de erros
 
 @param erros - O nome do ficheiro de erros

 @return O ficheiro aberto
*/
FILE *cria_ficheiro(char *erros);

#endif
