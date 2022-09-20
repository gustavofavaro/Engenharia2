#include <stdio.h>

int sum(int a, int b){
    return (a + b);
}

int sub(int a, int b){
    return (a - b);
}

int mult(int a, int b){
    return (a * b);
}

float div(int a, int b){
    return (float) a / b;
}

int main(){
    int x, y;
    printf("a = ");
    scanf("%d", &x);
    printf("b = ");
    scanf("%d", &y);
    printf("a + b = %d\n", sum(x, y));
    printf("a - b = %d\n", sub(x, y));
    printf("a * b = %d\n", mult(x, y));
    if(y == 0){
        printf("Can't divide by 0.\n");
        return 0;
    }
    printf("a : b = %.2f\n", div(x,y));
}