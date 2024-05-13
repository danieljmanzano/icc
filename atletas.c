#include <stdio.h>

void ordenavetor(int *vetor, int n){ //ordena o vetor
    int compara;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(vetor[j] < vetor[k]){
                compara = vetor[j];
                vetor[j] = vetor[k];
                vetor[k] = compara;
            }else if(vetor[j] == vetor[k] && j != k){
                vetor[k] = 0;
            }
        }
    }
    return;
}

int main(){
    int n, cont = 0;
    scanf("%d", &n);
    int pontos[n], vetor[n], matriz[n][2];

    for(int i = 0; i < n; i++){
        scanf(" %d", &pontos[i]);
        vetor[i] = pontos[i];
    }
    ordenavetor(vetor, n);

    for(int a = n - 1; a >= 0; a--){
        if(vetor[a] != 0){
            matriz[a][0] = vetor[a];
            matriz[a][1] = n - a - cont;
        }else if(vetor[a] == 0){
            matriz[a][1] = n - a - cont;
            cont++;
        }
    }

    for(int l = 0; l < n; l++){
        for(int m = 1; m <= n; m++){
            if(matriz[n - m][0] == pontos[l]){
                printf("%dº Atleta, %d Pontos, %dº Colocado\n", l + 1, pontos[l], matriz[n - m][1]);
                break;
            }
        }
    }
}
//deu certo Deus é maravilhoso
