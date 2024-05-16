#include <stdio.h>
int main(){
    //descobrir quantos zeros tem no resultado de um fatorial (do jeito otimizado)
    unsigned int n;
    int cont = 0, cinco = 1;
    scanf("%u", &n);
    for (int i = 1; i < 13; i++){
        cinco *= 5;
        cont += n/cinco;
    }
    printf("%d\n", cont); 
}