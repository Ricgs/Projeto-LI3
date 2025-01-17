#ifndef PARSER_H
#define PARSER_H

/**
 @brief recolhe as linhas dos ficheiros .csv
 
 @param file - O ficheiro .csv do tipo 'FILE'
 @param linhas - A lista de todas as linhas do tipo 'char***'
 
 @return i - O número de linhas do tipo 'INT'
*/
int ler_ficheiro(FILE *file, char ***linhas);
char *ler_linha(FILE *file);


#endif