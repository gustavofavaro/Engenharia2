#include "counting.h"

int end = 0;

char* read_line(FILE* p, char* c){
    char* buffer = calloc(200, sizeof(char));
    
    int i = 0;
    while(1){
        *c = fgetc(p);
        if(*c == EOF || *c == '\n'){
            if(*c == EOF) end = 1;
            break;
        }
        buffer[i] = *c;
        i += 1;
    }
    buffer[i + 1] = '\0';
    return buffer;
}

char* get_function_name(char* line){
    char* temp = calloc(200, sizeof(char));
    char* name = calloc(200, sizeof(char));
    int space_flag = 0, i, j = 0;

    for(i = 0; i < 200; i++){
        if(line[i] == '(') break;
        temp[i] = line[i];
    }
    temp[i + 1] = '\0';

    for(i = 0; i < 200; i++){
        if(space_flag){
            name[j] = temp[i];
            j += 1;
        }
        if(temp[i] == ' ') space_flag = 1;
    }
    name[j + 1] = '\0';
    return name;
}

void countLines(char* fileName){
    int lines_total = 0, lines_function = 0;
    char c; // local variable for fgetc operation
    char* func_name;
    FILE* code = fopen(fileName, "r");
    if(!code){
        printf("Error. Something wrong in file opening.\n");
        return;
    }
    Stack* braces_stack = stack_create();
    List* functions_list = list_create();

    printf("Code name: %s\n", fileName);

    while(!end){
        char* line = read_line(code, &c);
        for(int i = 0; line[i] != '\0'; i++){
            if(line[i] == '{'){
                stack_insert(braces_stack, '{');
                if(stack_get_size(braces_stack) == 1){
                    func_name = get_function_name(line);
                }

            }
            else if(line[i] == '}'){
                stack_remove(braces_stack);
                if(stack_get_size(braces_stack) == 0){
                    list_add(functions_list, lines_function - 1, func_name);
                    lines_function = 0;
                    func_name[0] = '\0';
                }
            }
        }
        if(strlen(line) > 1){
            if(stack_get_size(braces_stack) > 0) lines_function += 1;
            lines_total += 1;
        }
    }

    Node* aux = functions_list->first;
    while(aux){
        printf("Function name: %s | Function size: %d\n", aux->func_name, aux->lines);
        aux = aux->next;
    }
    printf("Code total size: %d\n", lines_total);
}