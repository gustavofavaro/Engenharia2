#include <stdlib.h>

typedef struct node{
    double value;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list{
    int size;
    struct node* first;
    struct node* last;
} List;

Node* node_create(double new_value);
Node* node_get_next(Node* node);
Node* node_get_previous(Node* node);
void node_delete(Node* node);

List* list_create();
int list_add(List* list, double new_value);
Node* list_search_linear(List* list, double value);
int list_remove(List* list, double value);
void list_delete(List* list);