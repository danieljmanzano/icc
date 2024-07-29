#include <stdio.h>

//programa para resolver um problema das torres de hanoi de acordo com a quantidade de discos que me é fornecido
//não fiz isso, copiei pq é muito nada ve

void hanoi(int n, char pilhaA, char pilhaC, char pilhaB){
    if(n == 0) return;

    hanoi(n - 1, pilhaA, pilhaB, pilhaC);
    printf("Move disco %d da pilha %c para a pilha %c\n", n, pilhaA, pilhaC);
    hanoi(n - 1, pilhaB, pilhaC, pilhaA);
} //eu nao entendi como funciona entao nao vou comentar

int main(void){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}