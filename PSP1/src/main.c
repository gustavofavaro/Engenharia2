#include <stdio.h>
#include "linear_reg.h"

int main(){
    List* data = list_create();
    double data_input1, data_input2, xk;
    int data_size;

    scanf("%d", &data_size);
    for(int i = 0; i < data_size; i++){
        scanf("%lf" "%lf", &data_input1, &data_input2);
        list_add(data, data_input1, data_input2);
    }
    scanf("%lf", &xk);

    double* results = lr_calc(data, xk);

    printf("b0 = %.4lf\nb1 = %.4lf\nr(x,y) = %.4lf\nr^2 = %.4lf\nyf = %.4lf\n", results[0], results[1], results[2], results[3], results[4]);
}