#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "manager_dados/parser.h"

int ler_ficheiro(FILE *file, char ***linhas) {
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int capacidade = 100000;

    *linhas = malloc(sizeof(char *) * capacidade); 
    if (*linhas == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return -1;
    }

    (*linhas)[i] = NULL;

    while ((read = getline(&(*linhas)[i], &len, file)) != -1) {
        i++;
        if (i >= capacidade) {
            capacidade *= 2;
            char **temp = realloc(*linhas, sizeof(char *) * capacidade);
            if (temp == NULL) {
                fprintf(stderr, "Erro ao realocar memória.\n");
                for (int j = 0; j < i; j++) {
                    free((*linhas)[j]);
                }
                free(*linhas);
                return -1;
            }
            *linhas = temp;
        }
        (*linhas)[i] = NULL;
    }

    if ((*linhas)[i] != NULL) {
        free((*linhas)[i]);
        (*linhas)[i] = NULL;
    }
    
    return i;
}

char *ler_linha(FILE *file) {
    char *linha = NULL;
    size_t len = 0;

    if (getline(&linha, &len, file) != -1) {
        return linha;
    } else {
        free(linha);
        linha = NULL;
        return NULL;
    }
}