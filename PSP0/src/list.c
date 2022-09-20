#include "list.h"

Node* node_create(double new_value){
    Node* new = malloc(sizeof(Node));
    new->value = new_value;
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

int list_add(List* list, double new_value){
    if(!list) return 0;

    Node* new = node_create(new_value);

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

Node* list_search_linear(List* list, double value){
    if(!list) return NULL;
    if(!list->first) return NULL;

    Node* aux = list->first;
    while(aux->next){
        if(aux->value == value){
            return aux;
        }
        aux = node_get_next(aux);
    }
    return NULL;
}

int list_remove(List* list, double value){
    if(!list) return 0;

    Node* node_to_remove = list_search_linear(list, value);
    if(!node_to_remove) return 0;

    // Node to be removed is on the last position
    if(node_to_remove == list->last){
        list->last = list->last->prev;
        list->last->next = NULL;
    }

    // Node to be removed is on the first position
    else if(node_to_remove == list->first){
        list->first = list->first->next;
        list->first->prev = NULL;
    }
    
    // Node to be removed is on the middle of the list
    else{
        Node* node_behind = node_to_remove->prev;
        Node* node_in_front = node_to_remove->next;

        node_behind->next = node_to_remove->next;
        node_in_front->prev = node_to_remove->prev;
    }

    free(node_to_remove);
    list->size -= 1;
    if(!list->size){
        list->first = list->last = NULL;
    }
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