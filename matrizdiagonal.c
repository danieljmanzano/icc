#include <stdio.h>

//recebe duas matrizes, ve se sao diagonais e, caso sejam de mesma dimensao, printa o resultado da multiplicacao das duas

void scanEprint(int matriz[6][6], int a){ //le e printa a matriz
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int testa(int matriz[6][6], int a){
    int verifica = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(matriz[i][j] != 0 && i != j){
                return verifica;
            }else if(matriz[i][j] == 0 && i == j){
                return verifica;
            }else if(matriz[i][j] == 0 && i != j){
                verifica = 1;
            }
        }
    }
    return verifica; //se chegou aqui quer dizer que a matriz é diagonal e retorna 1 à funçao
}

void multiplicamatriz(int matrizresult[6][6], int matrizn[6][6], int matrizm[6][6], int n){ //vou nem falar o que a funçao faz...
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int soma = 0;
            for(int k = 0; k < n; k++){
                soma += matrizn[i][k] * matrizm[k][j];
            }
            printf("%d ", soma);
        }
        printf("\n");
    }
    return;
}

int main(void){
    int n, m, matrizn[6][6], matrizm[6][6], matrizresult[6][6];
    scanf("%d %d", &n, &m);

    printf("Matrizes:\n");
    scanEprint(matrizn, n);
    scanEprint(matrizm, m);

    if(testa(matrizn, n)){
        printf("A matriz 1 eh diagonal\n");
    }else{
        printf("A matriz 1 nao eh diagonal\n");
    }

    if(testa(matrizm, m)){
        printf("A matriz 2 eh diagonal\n");
    }else{
        printf("A matriz 2 nao eh diagonal\n");
    }

    if(n == m){
        printf("Matriz multiplicada:\n");
        multiplicamatriz(matrizresult, matrizn, matrizm, n);
    }else{
        printf("Matrizes de tamanho incompativel\n");
    }
}