#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//programa que printa todas as combinações de letras com um tanto m de caracteres usando função recursiva

void palavrarecursiva(int m, char *palavra, int aux){
    if(aux == 0) return;
    if(aux > m) return;
    char c = 97;
    for(int i = 0; i < 26; i++){
        palavra[aux - 1] = c + i;
        if(aux == m) printf("%s\n", palavra); //só printa quando o aux for igual ao m (ou seja, o tanto de caractere a printar é igual ao tanto que pedi pra printar)
        palavrarecursiva(m, palavra, aux + 1);
    }
    aux++;
}

int main(void){
    int m;
    scanf("%d", &m);
    char *palavra = NULL;
    palavra = (char*) calloc(sizeof(char), m + 1);
    palavrarecursiva(m, palavra, 1);
}

//não tem muito segredo no funcionamento, ent nem vou comentar muito