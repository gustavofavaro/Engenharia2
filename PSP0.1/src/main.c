#include <stdio.h>
#include "counting.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Error. Need code name at argument 2.\n");
        return 0;
    }

    countLines(argv[1]);
}