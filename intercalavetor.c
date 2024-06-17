#include <stdio.h>
#include <stdlib.h>

//forneço o tamanho de dois vetores e intercalo os dois em outro pra printar

void aloca(int **vet, int x){
    (*vet) = malloc (sizeof(int) * x);
    for(int i = 0; i < x; i++){
        scanf(" %d", &(*vet)[i]);
    }
}

int main(void){
    int a, b, aux, aux2, *veta, *vetb, *vet;
    scanf("%d %d", &a, &b);
    aloca(&veta, a);
    aloca(&vetb, b);

    if(a > b){
        aux = a;
        aux2 = b;
    }else{
        aux = b;
        aux2 = a;
    }
    
    vet = malloc(sizeof(int) * (a + b));

    if(a > b){ //faço isso pra começar guardando no vetor final sempre o com maior tamanho (sem motivo aparente, só quis que fosse assim)
        for(int i = 0; i < 2 * aux2; i++){
            if(i % 2){
                vet[i] = vetb[(i - 1)/2];
            }else{
                vet[i] = veta[i / 2];
            }
        }
    }else{
        for(int i = 0; i < 2 * aux2; i++){
            if(i % 2){
                vet[i] = veta[(i - 1)/2];
            }else{
                vet[i] = vetb[i / 2];
            }
        }
    }
    

    if(a > b){
        for(int i = 2 * aux2; i < 2 * aux; i++){
            vet[i] = veta[i / 2];
        }
    }else{
        for(int i = 2 * aux2; i < 2 * aux; i++){
            vet[i] = vetb[i / 2];
        }
    }

    for(int i = 0; i < (a + b); i++){
        printf("%d ", vet[i]);
    }
}

//os aux e uns breguenaite a mais é pra se os tamanhos dos vetores forem diferentes
//exercicio de lista, por isso quase nao comentei nada (preguiça, desculpa)