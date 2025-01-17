#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <glib.h>

/**
 * @brief Escreve o resultado de uma query num ficheiro.
 * 
 * @param numlinha Número da linha ou comando.
 * @param mode Modo de escrita (1 para substituir '|' por '=', outro valor para ';').
 * @param result String com o resultado a ser escrito.
 */
void write_result(int numlinha, int mode, char *result);

#endif
