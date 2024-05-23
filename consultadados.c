#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//essa é complicadinha de deduzir o que é pra colocar de input entao tenta ver o enunciado la no runcodes que é melhor

void funcaodosprimos(int *primos){ //vou usar aqui pra fazer um vetor marcando os numeros primos (peguei do exercicio de icc rsrs)
    primos[0] = 1; //desconsiderando 0 e 1 da lista de primos
    primos[1] = 1;
    for(int i = 2; i < 8000; i++){ //aqui como usei calloc no primos, ja ta tudo como 0 (ou seja nao preciso inicializar o vetor)
        for(int j = 2; j*i < 8000; j++){
            primos[j*i] = 1;   //todos numeros nao primos sao colocados com valor 1 no vetor nas respectivas posições
        } //depois disso aqui, todos valores que ainda estão com 0 são os primos
    }
}

int divisoresprimos(int n, int *primos){ //o numero de bytes que vou usar pra alocar é baseado na soma dos primos do numero fornecido pelo usuario
    int soma = 0;
    int flag = 1;
    for(int i = 2; i <= n/2; i++){
        if(!(n%i) && !primos[i]){ //caso o numero seja divisivel pelo i e a posição dele no vetor de primo é 0 (ou seja, ele é primo)
            soma += i; //soma o numero
            flag = 0; //essa flag é pra testar se o numero n é primo 
        }
    }
    if(flag) return n; //caso n seja numero primo, a soma seria o proprio valor de n
    return soma; //senao, roda normal na ideia da soma 
} 

int *alocaint(int n){ //aloca um vetor int (vou usar pro vetor de ip)
    int *vetor;
    vetor = (int *) malloc (n * sizeof(int));
    return vetor; 
}

int *calocaint(int n){
    int *vetor;
    vetor = (int *) calloc (n, sizeof(int));
    return vetor;
}

char *alocachar(int n){ //aloca a string 
    char *vetor;
    vetor = (char *) malloc (sizeof(char) * n + 1);
    return vetor;
}

void printa(char **matriz, int *numbytes, int n){
    for(int i = 0; i < n; i++){
        printf("%s ", matriz[n - i - 1]); //esse n - i - 1 é pq percebi no final que a ordem de importancia é o contrario que pensei (aí gambiarrei)
        printf("%d\n", numbytes[n - i - 1]); //ai que buro dá zero pra ele
    }
    return;
}

char **alocamatriz(char **matriz, int n){
    matriz = (char **) calloc (sizeof(char *), n);
    return matriz;
}

int main(void){
    int n = 0, soma, ip, numbytes, *numbytes2 = NULL, *primos = NULL; //o numbytes2 eu vou usar pra deixar os bytes na ordem certa
    char **matriz = NULL; //essa matriz vai armazenar as strings que vou receber, cada linha recebe uma palavra diferente
    scanf("%d", &n);
    primos = calocaint(8000);
    if(!n){ //caso nao coloquem nada no n vai fazer issaqui
        printf("Sem produtos a serem cadastrados\n");
        return 0;
    } 
    numbytes2 = alocaint(n); //alocando geral que eu vou usar
    primos = calocaint(8000);
    matriz = alocamatriz(matriz, n);

    funcaodosprimos(primos);
    
    for(int i = 0; i < n; i++){ //for em que entram todos os scanf que vai ter no exercicio, tive que colocar na main pra puxar todas as funçoes
        scanf(" %d", &ip);
        scanf(" %d", &numbytes); //aqui eu to lendo o numero de que vou tirar a soma
        soma = divisoresprimos(numbytes, primos); 
        matriz[ip] = alocachar(soma); //guardo cada linha da matriz na posiçao certa ja
        scanf(" %s", matriz[ip]);
        numbytes2[ip] = numbytes; //ja arrumo a ordem que vou printar o numero de bytes fornecidos la no começo
    }
    printa(matriz, numbytes2, n);

    free(numbytes2);
    free(primos);
    free(matriz);
    numbytes2 = primos = matriz = NULL;
}