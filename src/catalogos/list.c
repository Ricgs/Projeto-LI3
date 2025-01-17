#include <stdio.h>
#include <stdlib.h>
#include "catalogos/list.h"


List* listCreate(void* data) {
    List* new = malloc(sizeof(List));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed for list\n");
        exit(EXIT_FAILURE);
    }
    new->data = data;
    new->next = NULL;
    return new;
}

void insertlist(List* list, void* data) {
    List* new = listCreate(data);
    new->next = list->next;
    list->next = new;
}

void insert_list_end(List* list, void* data) {
    List* new = listCreate(data);
    if (list==NULL) {
        list= new;
    }
    while (list->next!=NULL) {
        list= list->next;
    }
    list->next = new;
}

void listDestroy(List* list) {
    if (list == NULL) return;
    List* current = list->next;
    while (current != NULL) {
        List* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
