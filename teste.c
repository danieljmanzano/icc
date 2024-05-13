#include <stdio.h>

void swap(int *x, int *y){
    int w;
    w = *x;
    *x = *y;
    *y = w;
    return;
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
}

//so pra lembrar