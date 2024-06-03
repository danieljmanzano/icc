#include <stdio.h>

//treinando parte de typedef e struct
//exercicio pra inserir duas frações, somar as duas e printar o resultado (fiz questão de simplificar ainda pra ficar chique rsrs)

typedef struct{
    int denom; //denominador
    int numer; //numerador
}fracao;

fracao soma(fracao n1, fracao n2){ 
    int aux;
    fracao result;

    result.numer = n1.numer * n2.denom + n2.numer * n1.denom;
    result.denom = n1.denom * n2.denom;

    if(result.numer > result.denom) aux = result.denom; //vou usar o aux logo ali embaixo pra simplificação
    else aux = result.numer;

    for(int i = aux; i > 0; i--){ //esse negocio funciona pra simplificar a fração resultante
        if(!(result.numer % i) && !(result.denom % i)){
            result.numer /= i;
            result.denom /= i;
        }
    }

    return result;
}

int main(void){
    fracao n1, n2;
    scanf("%d %d %d %d", &n1.numer, &n1.denom, &n2.numer, &n2.denom);
    fracao result = soma(n1, n2);
    printf("%d / %d", result.numer, result.denom);

    return 0;
}