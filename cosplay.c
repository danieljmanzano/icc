#include <stdio.h>

//resumindo o exercicio: preciso printar uma matriz que mostra "o" como lugar possível e "x" como lugar não possível
//as condições são que um lugar só é possível se não está na linha ou coluna de uma letra "c" (cosplay) e está num espaço com a letra "v" (vago)
//caso não tenha nenhum lugar possível, tenho que printar uma mensagem específica 

int testalinha(char matriz[15][15], int n, int m){ //testa se na linha tem c (se tiver, marca com 1)
    for(int i = 0; i <= m; i++){
        if(matriz[n][i] == 99){
            return 1;
        }
    }
    return 0;
}

int testacoluna(char matriz[15][15], int m, int n){ //testa se na coluna tem c (se tiver, marca com 1)
    for(int j = 0; j <= n; j++){
        if(matriz[j][m] == 99){
            return 1;
        }
    }
    return 0;
}

int testadiatriste(char matriz[15][15], int n, int m){ //testa se tem algum lugar possível (caso nao, volta 1 como valor e atende a condição de printar a mensagem)
    int verifica;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == 120){
                verifica = 1;
            }else{
                return 0;
            }
        }
    }
    return verifica;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    char matriz[15][15];
    int testelinha[15], testecoluna[15];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    for(int i = 0; i <= n; i++){
        testelinha[i] = testalinha(matriz, i, m);
    }
    for(int j = 0; j <= m; j++){
            testecoluna[j] = testacoluna(matriz, j, n);
    }

    for(int i = 0; i < n; i++){ //"arrumando" a matriz pra analisar/printar depois
        for(int j = 0; j < m; j++){
            if(testelinha[i] || testecoluna[j]){ //se tem "c" na linha ou coluna, marca "x" 
                matriz[i][j] = 'x';
            }else if(matriz[i][j] == 102){ //se tem "f" na posiçao, a matriz marca "x"
                matriz[i][j] = 'x';
            }else if(testelinha[i] == 0 && testecoluna[j] == 0 && matriz[i][j] == 118){ //se nao tem "c" na linha ou coluna e tem "v" na posiçao, marca "o"
                matriz[i][j] = 'o';
            }
        }
    } //dava pra transformar isso aqui em funçao tb mas acho que ia ser trabalho à toa

    if(testadiatriste(matriz, n, m)){ //mensagem pra printar caso não tenha lugar possivel
        printf("Eh um dia triste para os mono Yasuo\n");
    }else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
    }

}