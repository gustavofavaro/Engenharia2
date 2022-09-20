#include <stdlib.h>
#include <stdio.h>

typedef struct nodec{
    char key;
    struct nodec* next;
    struct nodec* prev;
} NodeChar;

typedef struct stack{
    int size;
    struct nodec* top;
} Stack;

NodeChar* nodec_create(char new_key);
void nodec_delete(NodeChar* node);
Stack* stack_create();
int stack_insert(Stack* stack, char new_key);
int stack_remove(Stack* stack);
int stack_is_empty(Stack* stack);
int stack_get_size(Stack* stack);
NodeChar* stack_get_top_node(Stack* stack);
char stack_get_top_key(Stack* stack);