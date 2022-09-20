#include <stdlib.h>
#include <string.h>

typedef struct node{
    double x;
    double y;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list{
    int size;
    struct node* first;
    struct node* last;
} List;

Node* node_create(double new_x, double new_y);
Node* node_get_next(Node* node);
Node* node_get_previous(Node* node);
void node_delete(Node* node);

List* list_create();
int list_add(List* list, double new_x, double new_y);
void list_delete(List* list);