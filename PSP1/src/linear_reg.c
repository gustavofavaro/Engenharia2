#include "linear_reg.h"
#include <stdio.h>

double* lr_calc(List* param, double xk){
    double sum_x_y = 0, sum_x = 0, sum_y = 0, sum_x_pow2 = 0, sum_y_pow2 = 0;
    double b0 = 0, b1 = 0, x_avg = 0, y_avg = 0, rxy = 0, yk = 0, r_pow2 = 0, n = param->size;
    Node* aux = param->first;
    
    // loop for summation attribution
    for(int i = 0; i < n; i++){
        sum_x += aux->x;
        sum_y += aux->y;
        sum_x_y += aux->x * aux->y;
        sum_x_pow2 += pow(aux->x, 2);
        sum_y_pow2 += pow(aux->y, 2);
        aux = aux->next;
    }

    x_avg = sum_x / n;
    y_avg = sum_y / n;

    b1 = ((sum_x_y - (n * x_avg * y_avg)) / (sum_x_pow2 - (n * pow(x_avg, 2))));
    b0 = y_avg - (b1 * x_avg);

    rxy = ((n * sum_x_y) - (sum_x * sum_y)) / sqrt(((n * sum_x_pow2) - pow(sum_x, 2)) * ((n * sum_y_pow2) - pow(sum_y, 2)));

    yk = b0 + (b1 * xk);

    double* v_ans = calloc(5, sizeof(double));
    v_ans[0] = b0;
    v_ans[1] = b1;
    v_ans[2] = rxy;
    v_ans[3] = rxy * rxy;
    v_ans[4] = yk;

    return v_ans;
}