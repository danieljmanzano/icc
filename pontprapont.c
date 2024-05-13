#include <stdio.h>
int main(){
    int n, *p1, **p2;
    scanf("%d", &n);
    p1 = &n;
    p2 = &p1;
    printf("Valor inicial da variavel: %d\n", n);
    printf("Valor do ponteiro antes do incremento: %d\n", *p1);
    *p1 += 10;
    printf("Valor do ponteiro depois do incremento: %d\n", *p1);
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **p2);
    **p2 +=10;
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **p2);
    printf("Valor final da variavel: %d\n", n);
}