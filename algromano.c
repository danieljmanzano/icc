#include <stdio.h>
#include <string.h>

void inteiropararomano(int n, char alg[13][3], int num[13]){
    int cont = 12;
    while(n > 0){
        if(n >= num[cont]){
            n -= num[cont];
            printf("%s", alg[cont]);
        }else if(num[cont] > n){
            cont--;
        }
    }
    printf("\n");
    return;
}

int main(){
    int n, x, num[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char alg[13][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        scanf(" %d", &n);
        inteiropararomano(n, alg, num);
    }
}
