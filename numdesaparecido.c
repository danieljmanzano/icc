#include <stdio.h>

int pa(int n){ //função para calcular a pa de 1 ao número fornecido
    int soma = 0;
    for(int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}

int main(void){
    int n, soma = 0;
    scanf("%d", &n);
    int vetor[n - 1]; 

    for(int i = 0; i < n - 1; i++){
        scanf(" %d", &vetor[i]);
        soma += vetor[i];
    }
    printf("Numero desaparecido: %d", pa(n) - soma);
}
