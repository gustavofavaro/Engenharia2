#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meansd.h"

int main(){
    int size;
    double input, mean, sd;
    printf("Insert an amount of values for calculation: ");
    scanf("%d", &size);

    List* values = list_create();

    printf("Insert the values you wish to use.\n");
    for(int i = 0; i < size; i++){
        printf("Value %d: ", i + 1);
        scanf("%lf", &input);
        list_add(values, input);
    }

    mean = mean_calculation(values);
    sd = sd_calculation(values);

    printf("Results:\nMean: %.2f\nStandard Deviation: %.2f\n", mean, sd);
}