#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//exercicio em que recebo nome, cpf, idade, saldo e credito de uma pessoa
//depois tenho que printar todos os dados certin e mostrar quem ta endividado com base no credito e saldo

typedef struct{
    char *nome, cpf[12]; //cpf pode ser estático pq sempre tem o mesmo tamanho
    int idade;
    float saldo, credito;
}pessoa; //tipo pessoa contem todos os dados que podem ser fornecidos para uma pessoa

pessoa *alocapessoa(int n){ //uso só pra alocar o ponteiro do tipo pessoa 
    pessoa *p;
    p = (pessoa*) malloc (sizeof(pessoa) * n); //o n é o tanto de pessoas que o programa vai receber
    return p;
}

char *aloca(char nome[30]){
    char *p;
    int tam = strlen(nome); //vejo o tamanho real ocupado pelo nome
    p = (char*) malloc (sizeof(char) * tam); //alocando o nome no struct
    return p;
}

void printa(pessoa p){ //uso pra printar os dados (que surpresa)
    printf("\nNome: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("Idade: %d\n", p.idade);
    printf("Saldo: %.2f\n", p.saldo);
    printf("Credito: %.2f\n", p.credito);
}

void printadiv(pessoa p, int *cont2){
    if(p.credito > p.saldo){ //caso a pessoa esteja endividada, printa isso aqui na frente
        printf("\nNome: %s\n", p.nome);
        printf("CPF: %s\n", p.cpf);
        printf("Divida: %.2f\n", p.credito - p.saldo);
        (*cont2)++; //uso o cont pra comparar la embaixo 
    }
}

int main(void){
    char nome[30]; //vou usar esse vetor estático como "auxiliar" pra ler todos os nomes e depois alocar do jeito certo cada um por vez
    int n, cont = 0, cont2 = 0;
    pessoa *galera = NULL; //ponteiro galera vai virar um vetor que guarda os dados de cada pessoa em cada posição
    scanf("%d", &n);

    galera = alocapessoa(n); //aloco o ponteiro da struct com base na quantidade de pessoas de quem vou inserir as
    
    for(int i = 0; i < n; i++){
        scanf(" %[^,], %[^,], %d, %f, %f", nome, galera[i].cpf, &galera[i].idade, &galera[i].saldo, &galera[i].credito);
        galera[i].nome = aloca(nome); //aloco a string da struct do "jeito certo"
        strcpy(galera[i].nome, nome); //copio o conteúdo do que eu li agora na string alocada dinamicamente

        if(galera[i].saldo < galera[i].credito) cont++;
    }
    
    for(int i = 0; i < n; i++){
        printf("Dados da pessoa %d:", i + 1);
        printa(galera[i]);
        printf("\n");
    }

    printf("Pessoas endividadas:");

    if(!cont){ //se passar o for inteiro e não tiver ninguem endividado, o cont chega aqui como 0
        printf("\nNenhuma pessoa endividada encontrada."); //aí eu printo
        return 0;
    }

    for(int i = 0; i < n; i++){
        printadiv(galera[i], &cont2); 
        if(cont2 == cont) return 0; //na hora que o contador da função bater o número do contador da main
    }

    free(galera); //só pa caba
    galera = NULL; //tchau galera!!!
    return 0;
}