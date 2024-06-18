#include <stdio.h>

int somarecursiva(int n){
    if(n == 1){
        return 1;
    }else if(!n){
        return 0;
    }
    return somarecursiva(n - 1) + 1;
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", somarecursiva(a) + somarecursiva(b));
}

//printa a soma entre dois numeros inseridos calulcando por recursão (ideia de girico)