#include <stdio.h>

//exercício pra jogar batalha naval, basicamente
//recebe o campo de jogo, as jogadas e os erros e acertos, além do campo no final com os acertos

void campo(char matriz[26][26], int n){ //lê o "tabuleiro" da batalha naval
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void coord(char matriz[26][26], int i){
    int coluna;
    char linha;
    for(int n = 0; n < i; n++){
        scanf(" %c%d", &linha, &coluna);
        if(matriz[linha - 65][coluna - 1] == 78){ //N é 78 na tabela ASCII
            printf("acerto!\n");
            matriz[linha - 65][coluna - 1] = 'X'; //substitui por X na posição atingida
        }else{
            printf("erro!\n");
        }
    }
}

void printa(char matriz[26][26], int n){ //pra printar a matriz com os acertos no final do codigo
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int n, i;
    char matriz[26][26];
    scanf("%d", &n);
    campo(matriz, n); //pra ler o campo
    scanf("%d", &i);
    coord(matriz, i); //pra ler as coordenadas e printar se acertou ou errou
    printa(matriz, n); //pra printar o campo com os acertos marcados
}

//A == 65 na tabela ASCII