#include <stdio.h>

//testa se um numero é primo do jeito "otimizado"

int main(){
    int vetorzao[150000], num, q;

    for(int z = 0; z < 150000; z++){
        vetorzao[z] = 0;  //vetor com todos numeros de 0 a 1500000 marcados com 0
    }

    for(int i = 2; i < 150000; i++){
        if(vetorzao[i] == 0){
            for(int j = 2; j*i < 150000; j++){
                vetorzao[j*i] = 1;   //todos numeros nao primos sao colocados com valor 1 no vetor nas respectivas posições
            }
        }
    }

    scanf(" %d", &q);
    for(int k = 0; k < q; k++){
        scanf(" %d", &num);
        if(vetorzao[num] == 0){   //numeros primos (com valor igual a 0) entram no if e printa "sim"
            printf("Sim\n");
        }else{
            printf("Nao\n");
        }
    }
}

//atualizei tirando um zero do numerozaço do vetor ali, tinha rodado no runcodes mas nao rodava aqui
//agora aqui ta funcionando