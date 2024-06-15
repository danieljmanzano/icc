#include <stdio.h>

//treinando parte de typedef e struct
//exercicio pra inserir duas frações, somar, subtrair, multiplicar e dividir as duas e printar o resultado (fiz questão de simplificar ainda pra ficar chique rsrs)
//tambem tem o lance de que se dá 0 no denominador eu printo que nao é possivel

typedef struct{
    int denom; //denominador
    int numer; //numerador
}fracao;

void soma(fracao n1, fracao n2){ 
    int aux;
    fracao result;

    result.numer = n1.numer * n2.denom + n2.numer * n1.denom;
    result.denom = n1.denom * n2.denom;

    if(result.numer > result.denom) aux = result.denom; //vou usar o aux logo ali embaixo pra simplificação (coloco em aux o valor maior na fraçao)
    else aux = result.numer;

    for(int i = aux; i > 0; i--){ //esse negocio funciona pra simplificar a fração resultante
        if(!(result.numer % i) && !(result.denom % i)){
            result.numer /= i;
            result.denom /= i;
        }
    }

    if(!result.denom){ //caso o denominador seja 0, tenho que printar algo como uma mensagem de erro (nao pode divisao por 0 né)
        printf("soma nao possivel\n");
        return;
    }    

    if(!result.numer){ //caso o resultado seja 0, printo só o 0 sem a forma de fração (nao precisava necessariamente mas achei legal)
        printf("0 (soma)\n");
        return;
    }

    printf("%d / %d (soma)\n", result.numer, result.denom);
}

void subt(fracao n1, fracao n2){
    int aux;
    fracao result;

    result.numer = n1.numer * n2.denom - n2.numer * n1.denom;
    result.denom = n1.denom * n2.denom;

    if(result.numer > result.denom) aux = result.denom; //mesma logica da funçao de cima, faço simplificação
    else aux = result.numer;

    for(int i = aux; i > 0; i--){ 
        if(!(result.numer % i) && !(result.denom % i)){
            result.numer /= i;
            result.denom /= i;
        }
    }

    if(!result.denom){
        printf("subtracao nao possivel\n");
        return;
    }    

    if(!result.numer){
        printf("0 (subtracao)\n");
        return;
    }

    printf("%d / %d (subtracao)\n", result.numer, result.denom);
}

void mult(fracao n1, fracao n2){ //pra multiplicar 
    int aux;
    fracao result;

    result.numer = n1.numer * n2.numer;
    result.denom = n1.denom * n2.denom;

    if(result.numer > result.denom) aux = result.denom; //mesma logica da outra funçao, uso isso pra simplificar
    else aux = result.numer;

    for(int i = aux; i > 0; i--){ 
        if(!(result.numer % i) && !(result.denom % i)){
            result.numer /= i;
            result.denom /= i;
        }
    }

    if(!result.denom){
        printf("multiplicacao nao possivel\n");
        return;
    }    


    if(!result.numer){
        printf("0 (multiplicacao)\n");
        return;
    }

    printf("%d / %d (multilplicacao)\n", result.numer, result.denom);
}

void div(fracao n1, fracao n2){
    int aux;
    fracao result;

    result.numer = n1.numer * n2.denom;
    result.denom = n1.denom * n2.numer;

    if(result.numer > result.denom) aux = result.denom; //mesma logica da outra funçao, uso isso pra simplificar
    else aux = result.numer;

    for(int i = aux; i > 0; i--){ 
        if(!(result.numer % i) && !(result.denom % i)){
            result.numer /= i;
            result.denom /= i;
        }
    }

    if(!result.denom){
        printf("divisao nao possivel\n");
        return;
    }    

    if(!result.numer){
        printf("0 (divisao)\n");
        return;
    }

    printf("%d / %d (divisao)", result.numer, result.denom);
}

int main(void){
    fracao n1, n2;
    scanf("%d %d %d %d", &n1.numer, &n1.denom, &n2.numer, &n2.denom);
    soma(n1, n2);
    subt(n1, n2);
    mult(n1, n2);
    div(n1, n2);

    return 0;
}

//ficou meio comprido mais pelas repetiçao de logica no codigo, mas nao é nada complexo