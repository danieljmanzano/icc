#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//exercicio pra alocar, ler e printar uma matriz

int **alocamatriz(int n){ //aloca o ponteiro que vai ser a primeira posição da matriz (nao min diga)
    int **pont;
    pont = (int **) calloc (sizeof(int *), n);
    if(pont == NULL){
        printf("não foi possível alocar a matriz\n");
        exit (1);
    }
    for(int i = 0; i < n; i++){
        pont[i] = (int *) calloc (sizeof(int), n);
        if(pont == NULL){
            printf("não foi possível alocar a matriz\n");
            exit (1);
        }  
    }
    return pont;
}

void le(int **matriz, int n){ //le os numeros que vão pra dentro da matriz (ah é nada???)
    for(int i = 0; i < sqrt(n); i++){
        for(int j = 0; j < sqrt(n); j++){
            scanf(" %d", &matriz[i][j]);
        }
    }
    return; 
}

void printa(int **matriz, int n){ //printa a matriz (nao acredito!!!)
    for(int i = 0; i < sqrt(n); i++){
        for(int j = 0; j < sqrt(n); j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(void){
    int n, **matriz;
    scanf("%d", &n); //scan do tanto de numero que tem na matriz
    matriz = alocamatriz(sqrt(n));
    le(matriz, n);
    printa(matriz, n);
}