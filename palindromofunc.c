#include <stdio.h>
#include <string.h>

int testapalindromo(char *palavra, int cont){
    char *pont;
    int verifica;
    pont = &palavra[cont - 1];

    for(int i = 0; i < cont; i++){
        if(*pont == palavra[i]){
            verifica = 1;
        }else{
            verifica = 0;
        }
        pont--;
    }
    return verifica;
}

int main(void){
    int n, cont, verifica;
    char palavra[20];
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", palavra);
        cont = strlen(palavra);
        verifica = testapalindromo(palavra, cont);

        if(verifica){
            printf("%s eh um palindromo\n", palavra);
        }else{
            printf("%s nao eh um palindromo\n", palavra);
        }
        cont = 0;
    }
}