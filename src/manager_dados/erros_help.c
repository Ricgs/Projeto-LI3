#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/artistas.h"
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"

char *cria_erros(char *diretoria)
{
    char *erros = strdup(diretoria);
    return erros;
}

FILE *cria_ficheiro(char *erros)
{
   FILE *ficheiro = fopen(erros, "a");
    if (ficheiro == NULL)
    {
        perror("Erro ao abrir o arquivo de erros");
    }
    return ficheiro;
}