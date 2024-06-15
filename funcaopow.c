#include <stdio.h>

double potencia(double x, int n){
    double result = x;
    for(int i = 2; i <= n; i++){
        result *= x;
    }
    return result;
}

int main(void){
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%lf", potencia(x, n));
    return 0;
}
//exercicio de lista, bem basico mas daorinha (nome autoexplicativo entao nem vou comentar nada)