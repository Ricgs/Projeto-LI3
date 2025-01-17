#ifndef QUERY2_H
#define QUERY2_H

#include <stdbool.h>
#include <stdio.h>
#include "catalogos/list.h"

/**
 @brief executa a query 2
 
 @param arg - O argumento da query
 @param list - A lista de artistas
 @return O resultado da query como string
*/
char* execute_query2(char *arg, List *list);

#endif
