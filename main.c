#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "modos_execucao/modo_batch.h"
#include "modos_execucao/modo_test.h"
#include "modos_execucao/modo_interativo.h"

int main(int argc, char **argv)
{

    if (argc==1) exec_interactive_mode();
    else
    {
        if (argc==3) exec_batch_mode(argv[1],argv[2]);
        else
        {
            if (argc==4) exec_test_mode(argv[1],argv[2],argv[3]);
            else
            {
                printf("Argumentos insuficientes(ou excessivos)");
                return 1;
            }
        }
    }
    
    //char *path = "dataset-errors";
    //char *queries = "input.txt";
    //char *res_esp = "resultados-esperados";

    //exec_test_mode(path, queries, res_esp);

    //exec_interactive_mode();

    return 0;
}
