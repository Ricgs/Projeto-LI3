#ifndef MENU_PATH_H
#define MENU_PATH_H

/**
 * @brief Mostra o menu para definir o caminho do dataset.
 * 
 * Apresenta instruções para o utilizador inserir o caminho do dataset.
 * 
 * @param x Coordenada horizontal inicial.
 * @param y Coordenada vertical inicial.
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 */
void menu_path(int x, int y, int ncols, int nrows, int branco, int branco_preto);

/**
 * @brief Mostra o menu de erro para o caminho do dataset.
 * 
 * Apresenta uma mensagem de erro caso o caminho inserido não seja válido.
 * 
 * @param x Coordenada horizontal inicial.
 * @param y Coordenada vertical inicial.
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 */
void menu_erro_path(int x, int y, int ncols, int nrows, int branco, int branco_preto);

#endif
