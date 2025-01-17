#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "teste/comparacao.h"

void inicializar_stats(QueryStats *stats) {
    stats->total = 0;
    stats->corretas = 0;
    stats->erros = 0;
    stats->discrepancias = NULL;
    stats->linhas = NULL;
}

void registar_discrepancia(QueryStats *stats, int query_num, int linha) {
    stats->erros++;
    stats->discrepancias = realloc(stats->discrepancias, stats->erros * sizeof(int));
    stats->linhas = realloc(stats->linhas, stats->erros * sizeof(int));
    stats->discrepancias[stats->erros - 1] = query_num;
    stats->linhas[stats->erros - 1] = linha;
}

void imprimir_resultados(QueryStats *q1, QueryStats *q2, QueryStats *q3) {
    QueryStats *queries[] = {q1, q2, q3};
    for (int i = 0; i < 3; i++) {
        printf("Q%d: %d de %d testes ok!\n", i + 1, queries[i]->corretas, queries[i]->total);
        for (int j = 0; j < queries[i]->erros; j++) {
            printf("    Descrepância na query %d: linha %d de \"resultados/command%d_output.txt\"\n",
                   queries[i]->discrepancias[j], queries[i]->linhas[j], queries[i]->discrepancias[j]);
        }
    }
}

void comparar_arquivos(char *arquivo_res, char *arquivo_esperado, QueryStats *stats, int query_num) {
    // Tenta abrir os ficheiros
    FILE *res_file = fopen(arquivo_res, "r");
    if (!res_file) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de resultados: %s\n", arquivo_res);
        return;
    }

    FILE *esp_file = fopen(arquivo_esperado, "r");
    if (!esp_file) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo esperado: %s\n", arquivo_esperado);
        fclose(res_file); // Fecha o ficheiro já aberto
        return;
    }

    char linha_res[1024], linha_esp[1024];
    int linha = 0;
    bool correta = true; // Assume inicialmente que os ficheiros são idênticos
    stats->total++;      // Incrementa o total de comparações feitas

    // Compara linha a linha os ficheiros
    while (fgets(linha_res, sizeof(linha_res), res_file) && fgets(linha_esp, sizeof(linha_esp), esp_file)) {
        linha++;

        // Remove os caracteres de nova linha (se existirem)
        linha_res[strcspn(linha_res, "\n")] = '\0';
        linha_esp[strcspn(linha_esp, "\n")] = '\0';

        // Compara as linhas atuais
        if (strcmp(linha_res, linha_esp) != 0) {
            registar_discrepancia(stats, query_num, linha); // Regista a discrepância
            correta = false; // Marca que houve discrepância
        }
    }

    // Incrementa o contador de ficheiros corretos, se aplicável
    if (correta) stats->corretas++;

    // Fecha os ficheiros
    fclose(res_file);
    fclose(esp_file);
}

void compara(char *pasta_resultados, char *pasta_esperados, char *input) {
    QueryStats q1, q2, q3;
    inicializar_stats(&q1);
    inicializar_stats(&q2);
    inicializar_stats(&q3);

    FILE *args = fopen(input, "r");
    char tipo_query;
    int query_num = 1;
    char linha[256];

    while (fgets(linha, sizeof(linha), args) != NULL && query_num <= 75) {
        tipo_query = linha[0];
        char arquivo_res[256], arquivo_esp[256];
        snprintf(arquivo_res, sizeof(arquivo_res), "%s/command%d_output.txt", pasta_resultados, query_num);
        snprintf(arquivo_esp, sizeof(arquivo_esp), "%s/command%d_output.txt", pasta_esperados, query_num);

        if (tipo_query == '1') comparar_arquivos(arquivo_res, arquivo_esp, &q1, query_num);
        if (tipo_query == '2') comparar_arquivos(arquivo_res, arquivo_esp, &q2, query_num);
        if (tipo_query == '3') comparar_arquivos(arquivo_res, arquivo_esp, &q3, query_num);

        query_num++;
    }

    fclose(args);
    imprimir_resultados(&q1, &q2, &q3);

    free(q1.discrepancias); free(q1.linhas);
    free(q2.discrepancias); free(q2.linhas);
    free(q3.discrepancias); free(q3.linhas);
}
