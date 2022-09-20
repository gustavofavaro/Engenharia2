#include "list.h"

Node* node_create(int lines, char* func){
    Node* new = malloc(sizeof(Node));
    new->lines = lines;
    strcpy(new->func_name, func);
    new->next = NULL;
    new->prev = NULL;

    return new;
}

Node* node_get_next(Node* node){
    return node->next;
}

Node* node_get_previous(Node* node){
    return node->prev;
}

void node_delete(Node* node){
    free(node);
    node = NULL;
}

List* list_create(){
    List* new = malloc(sizeof(List));
    new->first = NULL;
    new->last = NULL;
    new->size = 0;

    return new;
}

int list_add(List* list, int lines, char* func_name){
    if(!list) return 0;

    Node* new = node_create(lines, func_name);

    // List is empty and the node created is the first to be added
    if(list->size == 0)
        list->first = list->last = new;

    // List already has members
    else{
        new->prev = list->last;
        list->last = list->last->next = new;
    }

    list->size += 1;
    return 1;
}

void list_delete(List* list){
    Node* node_current = list->first;
    Node* node_next = node_current->next;
    while(node_next){
        free(node_current);
        node_current = node_next;
        node_next = node_next->next;
    }
    free(node_current);
    list->first = list->last = NULL;
    free(list);
}