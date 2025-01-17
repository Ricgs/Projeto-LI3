#ifndef COMPARACAO_H
#define COMPARACAO_H

typedef struct {
    int total; /**< Total de queries comparadas */
    int corretas; /**< Número de queries corretas */
    int erros; /**< Número de queries com discrepâncias */
    int *discrepancias; /**< Lista de queries com discrepâncias */
    int *linhas; /**< Linhas com discrepâncias */
} QueryStats;

/**
 @brief inicializa a estrutura de estatísticas de comparação
 
 @param stats - A estrutura a ser inicializada
*/
void inicializar_stats(QueryStats *stats);

/**
 @brief regista uma discrepância entre os resultados e os esperados
 
 @param stats - A estrutura de estatísticas
 @param query_num - O número da query
 @param linha - A linha onde ocorreu a discrepância
*/
void registar_discrepancia(QueryStats *stats, int query_num, int linha);

/**
 @brief imprime os resultados das comparações
 
 @param q1 - Estatísticas da query 1
 @param q2 - Estatísticas da query 2
 @param q3 - Estatísticas da query 3
*/
void imprimir_resultados(QueryStats *q1, QueryStats *q2, QueryStats *q3);

/**
 @brief compara os conteúdos de dois ficheiros
 
 @param arquivo_res - Caminho para o ficheiro de resultados
 @param arquivo_esperado - Caminho para o ficheiro esperado
 @param stats - Estrutura para registar as estatísticas
 @param query_num - Número da query
*/
void comparar_arquivos(char *arquivo_res, char *arquivo_esperado, QueryStats *stats, int query_num);

/**
 @brief realiza a comparação entre os resultados e os esperados
 
 @param pasta_resultados - Caminho para a pasta de resultados
 @param pasta_esperados - Caminho para a pasta de resultados esperados
 @param input - Ficheiro com os comandos das queries
*/
void compara(char *pasta_resultados, char *pasta_esperados, char *input);

#endif
