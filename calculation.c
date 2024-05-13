#include <stdio.h>
int main(){
    int num1, num2;
    float divrac;
    scanf("%d%d", &num1, &num2);

    printf("Soma: %d\n", num1 + num2);
    printf("Subtracao: %d\n", num1 - num2);
    printf("Multiplicacao: %d\n", num1 * num2);
    printf("Divisao Inteira: %d\n", num1 / num2);
    printf("Divisao Racional: %.3f\n", divrac = (float)num1/num2);
}