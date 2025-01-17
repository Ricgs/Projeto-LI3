#ifndef MENU_QUERY_H
#define MENU_QUERY_H

/**
 * @brief Mostra o menu para introduzir queries.
 * 
 * Apresenta instruções para o utilizador introduzir e executar queries no programa.
 * 
 * @param x Coordenada horizontal inicial.
 * @param y Coordenada vertical inicial.
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 */
void menu_queries(int x, int y, int ncols, int nrows, int branco, int branco_preto);

/**
 * @brief Mostra o menu de erro para queries.
 * 
 * Apresenta uma mensagem de erro caso o formato da query não seja respeitado.
 * 
 * @param x Coordenada horizontal inicial.
 * @param y Coordenada vertical inicial.
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 */
void menu_erro_query(int x, int y, int ncols, int nrows, int branco, int branco_preto);

#endif
