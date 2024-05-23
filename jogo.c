#include <stdio.h>
#include <stdlib.h>

char **alocamatriz(int n, int m){ //funçao pra alocar a matriz de acordo com "n" e "m" fornecidos
    char **pont = NULL;
    pont = (char **) malloc (sizeof(char*) * n); 
    if(pont == NULL) exit (1); //se nao der pra alocar ele dá ruim
    for(int i = 0; i < n; i++){ //aqui vou alocando linha por linha
        pont[i] = (char *) malloc (sizeof(char) * m);
        if(pont[i] == NULL) exit (1); //igual em cima, se nao consegue alocar ele dá o fora
    }
    return pont;
}

void le(char **matriz, int n, int m){ //funçao pra ler a matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &matriz[i][j]); //sem segredo, só no scanf
        }
    }
    return;
}

int checalinha(char **matriz, int i, int j, int m){ //vejo se na linha tem um vizinho "X"
    int cont = 0; //o contador ve quantos "X" tem nos arredores
    if(j != 0 && matriz[i][j - 1] == 88){ //aqui e nos outros if das funçoes de checar, a primeira condiçao sempre ve se ele ta na borda da matriz
        cont++;                           //se tiver, ele nem testa ver o lado que tiver na borda (que, basicamente, nao existe mesmo)
    }
    if(j != m - 1 && matriz[i][j + 1] == 88){ //aqui o mesmo de cima
        cont++;
    }
    return cont;
}

int checacoluna(char **matriz, int i, int j, int n){  //mesma coisa que a checalinha, só que com coluna (ah é nada)
    int cont = 0; //aqui o mesmo de cima
    if(i != 0 && matriz[i - 1][j] == 88){ //aqui o mesmo de cima
        cont++;
    }
    if(i != n -1 && matriz[i + 1][j] == 88){ //aqui o mesmo de cima
        cont++;
    }
    return cont;
}

void escreve(char **matriz, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((checalinha(matriz, i, j, m) + checacoluna(matriz, i, j, n)) % 2 == 0 && matriz[i][j] != 88){
                matriz[i][j] = '*'; //no if de cima, ele testa se os "X" dos arredores formam par e se a própria posição da matriz nao é "X"
            } //continuando, caso tenham "X" pares e a propria posiçao nao é "X", ele troca por asterisco
        }
    }
}

void printa(char **matriz, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c", matriz[i][j]); //sem segredo denovo, só printa a matriz linha por linha
        }
        printf("\n");
    }
    return;
}

int main(void){
    int n, m;
    char **matriz = NULL;
    scanf("%d %d", &n, &m); //vejo as dimensoes da matriz
    matriz = alocamatriz(n, m); //aloco a matriz (aloca o primeiro ponto e dps os vetores que compoem ela)
    le(matriz, n, m); //leio a matriz
    escreve(matriz, n, m); //marco as posições que posso colocar uma peça (o asterisco)
    printa(matriz, n, m); //printo no final depois de marcar as posições
    return 0;
}
//exercicio daorinha