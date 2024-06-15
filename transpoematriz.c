#include <stdio.h>
#include <stdlib.h>

//insere dimensoes m e n de uma matriz MxN, pega os numeros de cada posição e dps tranpõe ela (e printa)

int **alocamatriz(int n, int m){
    int **matriz;
    matriz = (int**) malloc (sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        matriz[i] = (int*) malloc (sizeof(int) * m);
    }
    return matriz;
}

void lematriz(int **matriz, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }
}

void transpoe(int **matriz, int **matriz2, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matriz2[j][i] = matriz[i][j];
        }
    }
}

void printa(int **matriz2, int n, int m){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int n, m, **matriz = NULL, **matriz2 = NULL;
    scanf("%d %d", &m, &n);
    matriz = alocamatriz(n, m);
    matriz2 = alocamatriz(m, n);
    lematriz(matriz, n, m);
    transpoe(matriz, matriz2, n, m);
    printa(matriz2, n, m);

    free(matriz);
    free(matriz2);
    matriz = matriz2 = NULL;
}
//exercicio de lista, bem legalzin