#ifndef MENU_OUTPUT_H
#define MENU_OUTPUT_H

#include <stdbool.h>

/**
 * @brief Mostra o menu para apresentação do output.
 * 
 * Apresenta os resultados de um comando executado, com opções para navegar pelos dados.
 * 
 * @param x Coordenada horizontal inicial.
 * @param y Coordenada vertical inicial.
 * @param ncols Número de colunas da interface.
 * @param nrows Número de linhas da interface.
 * @param path Caminho do ficheiro de output.
 * @param preto Cor preta na interface.
 * @param branco Cor branca na interface.
 * @param branco_preto Estilo branco com fundo preto.
 * @param command Número do comando executado.
 * @param line Linha inicial do ficheiro a ser apresentada.
 */
void menu_output(int x, int y, int ncols, int nrows, char *path, int preto, int branco, int branco_preto, int command, int line);

#endif
