#include <stdio.h>
int main(){
    int dia, parar;
    scanf("%d%d", &dia, &parar);
    if(dia > 7){
        printf("Dia nao registrado\n");
        return 0;
    }
    switch(dia){
        case 1: printf("Segunda: Aula de computacao\n");
        if(parar == 1){
            break;
        }
        case 2: printf("Terca: Treino de volei\n");
        if(parar == 1){
            break;
        }
        case 3: printf("Quarta: Aula de calculo\n");
        if(parar == 1){
            break;
        }
        case 4: printf("Quinta: Lista de GA\n");
        if(parar == 1){
            break;
        }
        case 5: printf("Sexta: Festa da Sacim\n");
        if(parar == 1){
            break;
        }
        case 6: printf("Sabado: Jantar em familia\n");
        if(parar == 1){
            break;
        }
        case 7: printf("Domingo: Depressao pos final de semana\n");
    }
}