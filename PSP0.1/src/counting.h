#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "list.h"

char* read_line(FILE* p, char* c);
char* get_function_name(char* line);
void countLines(char* fileName);