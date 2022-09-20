#include <stdlib.h>
#include <string.h>

typedef struct node{
    int lines;
    char func_name[100];
    struct node* next;
    struct node* prev;
} Node;

typedef struct list{
    int size;
    struct node* first;
    struct node* last;
} List;

Node* node_create(int lines, char* func);
Node* node_get_next(Node* node);
Node* node_get_previous(Node* node);
void node_delete(Node* node);

List* list_create();
int list_add(List* list, int lines, char* func_name);
void list_delete(List* list);