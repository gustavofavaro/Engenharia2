#include "stack.h"

NodeChar* nodec_create(char new_key){
    NodeChar* new = malloc(sizeof(NodeChar));
    new->key = new_key;
    new->next = new->prev = NULL;

    return new;
}

void nodec_delete(NodeChar* node){
    node->next = node->prev = NULL;
    free(node);
    node = NULL;
}

Stack* stack_create(){
    Stack* new = malloc(sizeof(Stack));
    new->size = 0;
    new->top = NULL;

    return new;
}

int stack_insert(Stack* stack, char new_key){
    if(!stack) return 0;

    NodeChar* new = nodec_create(new_key);

    if(stack->size == 0){
        stack->top = new;
    }
    else{
        new->prev = stack->top;
        stack->top->next = new;
        stack->top = new;
    }

    stack->size += 1;
    return 1;
}

int stack_remove(Stack* stack){
    if(!stack) return 0;

    if(stack->size == 1){
        nodec_delete(stack->top);
    }
    else{
        NodeChar* new_top = stack->top->prev;
        new_top->next = NULL;
        nodec_delete(stack->top);
        stack->top = new_top;
    }

    stack->size -= 1;
    return 1;
}

int stack_is_empty(Stack* stack){
    return stack->top == NULL ? 1 : 0;
}

int stack_get_size(Stack* stack){
    return stack->size;
}

NodeChar* stack_get_top_node(Stack* stack){
    return stack->top;
}

char stack_get_top_key(Stack* stack){
    return stack->top->key;
}