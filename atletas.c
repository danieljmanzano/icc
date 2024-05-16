#include <stdio.h>

//recebe um numero de atletas e a pontuação deles
//printa o número do atleta (de acordo com o recebido), a colocação e o número de pontos
//talvez eu tenha feito de um jeito meio paia... mas deu certo

void ordenavetor(int *vetor, int n){ //ordena o vetor
    int compara;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(vetor[j] < vetor[k]){
                compara = vetor[j];
                vetor[j] = vetor[k];
                vetor[k] = compara;
            }else if(vetor[j] == vetor[k] && j != k){
                vetor[k] = 0; //isso aqui vai servir para caso repita um número de pontos 
            }
        }
    }
    return;
}

int main(){
    int n, cont = 0;
    scanf("%d", &n);
    int pontos[n], vetor[n], matriz[n][2]; //a matriz vai servir pra guardar a colocação do atleta

    for(int i = 0; i < n; i++){
        scanf(" %d", &pontos[i]);
        vetor[i] = pontos[i];
    }
    ordenavetor(vetor, n);

    for(int a = n - 1; a >= 0; a--){
        if(vetor[a] != 0){ //guardando a colocação dos atletas que não repetem
            matriz[a][0] = vetor[a]; //pontuação guardada na primeira coluna da matriz
            matriz[a][1] = n - a - cont; //colocação na segunda
        }else if(vetor[a] == 0){
            matriz[a][1] = n - a - cont;
            cont++; //o contador ajuda a verificar se repetiu uma pontuação (vai printar mesma colocação e "pular" uma colocação pros atletas de trás)
        }
    }

    for(int l = 0; l < n; l++){
        for(int m = 1; m <= n; m++){
            if(matriz[n - m][0] == pontos[l]){
                printf("%dº Atleta, %d Pontos, %dº Colocado\n", l + 1, pontos[l], matriz[n - m][1]); //a matriz printa a colocação
                break;
            }
        }
    }
}
//deu certo Deus é maravilhoso
