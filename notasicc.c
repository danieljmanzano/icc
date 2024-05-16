#include <stdio.h>

//recebo a quantidade de linhas e colunas de uma matriz (n = linha = notas de um aluno/ m = colunas = notas de um exercicio especifico)
//vou printar a media de cada aluno, se foi aprovado ou reprovado e as medias de cada exercicio em ordem decrescente

float medialinha(float matriz[100][25], int a, int m){ //calcula a media de notas na linha (de cada aluno)
    float soma = 0;
    for(int j = 0; j < m; j++){
        soma += matriz[a - 1][j];
    }
    return soma / m;
}

float mediacoluna(float matriz[100][25], int b, int n){ //calcula a media de notas na coluna (de cada exercicio)
    float soma = 0;
    for(int i = 0; i < n; i++){
        soma += matriz[i][b - 1];
    }
    return soma / n;
}

void ordenador(float vetor[25], int m){ //ordena as medias dos exercicios pra printar (exigencia do exercicio)
    float compara;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(vetor[i] < vetor[j]){
                compara = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = compara;
            }
        }
    }
    return;
}

int main(void){
    int n, m;
    float matriz[100][25], vetorord[25];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    for(int x = 1; x <= n; x++){ //printa media de aluno usando a funçao medialinha
        printf("Media do aluno %d = %.2f : ", x, medialinha(matriz, x, m));
        if(medialinha(matriz, x, m) >= 5){
            printf("Aprovado\n");
        }else{
            printf("Reprovado\n");
        }
    }

    printf("\n");

    for(int y = 1; y <= m; y++){ //coloca os valores das medias das colunas num vetor
        vetorord[y - 1] = mediacoluna(matriz, y, n);
    }
    
    ordenador(vetorord, m); //ordena o vetor com as notas dos exercicios

    for(int g = m - 1; g >= 0; g--){ //printa as notas dos exercicios em ordem decrescente
        printf("%.2f ", vetorord[g]);
    }
}