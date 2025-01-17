#ifndef CATALOGO_LIST_H
#define CATALOGO_LIST_H

#include <stdio.h>

/**
 * @brief Estrutura para representar uma lista encadeada.
 *
 * Cada nó da lista contém um ponteiro para os dados armazenados
 * e um ponteiro para o próximo nó da lista.
 */
typedef struct list {
  void* data;          
  struct list* next;    
} List;

/**
 * @brief Cria um novo nó para a lista encadeada.
 *
 * Aloca memória para um novo nó, inicializa-o com os dados fornecidos e
 * define o ponteiro para o próximo nó como NULL.
 *
 * @param data Ponteiro para os dados que o nó irá armazenar.
 * 
 * @return Ponteiro para o nó recém-criado.
 */
List* listCreate(void* data);

/**
 * @brief Insere um novo nó após o nó especificado.
 *
 * Adiciona um novo nó contendo os dados fornecidos imediatamente após o
 * nó especificado na lista encadeada.
 *
 * @param list Ponteiro para o nó após o qual o novo nó será inserido.
 * @param data Ponteiro para os dados a serem armazenados no novo nó.
 */
void insertlist(List* list, void* data);

/**
 * @brief Insere um novo nó no final da lista especificado.
 *
 * Adiciona um novo nó contendo os dados fornecidos no final da lista encadeada.
 *
 * @param list Ponteiro para lista em qual será inserido.
 * @param data Ponteiro para os dados a serem armazenados no novo nó.
 */
void insert_list_end(List* list, void* data);

/**
 * @brief Remove todos os nós da lista e libera a memória alocada.
 *
 * Itera sobre a lista, removendo e liberando a memória de cada nó, começando
 * pelo nó seguinte ao nó base fornecido.
 *
 * @param list Ponteiro para o nó base da lista a ser destruída.
 */
void listDestroy(List *list);

#endif
