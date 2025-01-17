#ifndef CALCULOS_H
#define CALCULOS_H

/**
 @brief converte duração no formato HH:MM:SS para segundos
 
 @param duracao - A string com a duração
 @return O tempo em segundos
*/
int convert_duracao_to_seconds(const char *duracao);

/**
 @brief verifica se a string representa um número
 
 @param str - A string a ser verificada
 @return 1 se for número, 0 caso contrário
*/
int is_number(const char *str);

/**
 @brief converte segundos para o formato HH:MM:SS
 
 @param seg - O tempo em segundos
 @param buffer - O buffer para guardar o resultado
*/
void s_to_h(int seg, char *buffer);

/**
 @brief remove aspas de uma string
 
 @param str - A string com aspas
 @return A string sem aspas
*/
char *remove_aspas(char *str);

/**
 @brief parse de uma string para um array
 
 @param array - O array onde os valores serão armazenados
 @param str - A string a ser processada
*/
void parse_A_U(GArray *array, char *str);

/**
 @brief parse de IDs de artistas para um array
 
 @param array - O array onde os IDs serão armazenados
 @param str - A string com os IDs
*/
void parse_artist_id(GArray *array, char *str);

/**
 @brief limpa o ecrã com fundo preto
 
 @param ncols - Número de colunas
 @param nrows - Número de linhas
 @param preto - Cor do fundo
*/
void fundo_preto(int ncols, int nrows, int preto);

/**
 @brief verifica o formato das queries
 
 @param input - A query a ser verificada
 @return 0 se válido, 1 caso contrário
*/
int verificarFormato(char *input);

#endif
