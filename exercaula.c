#include <stdio.h>
int main(){
    unsigned long int a, b;
    scanf("%lu%lu", &a, &b);
    if(a % 2 == b % 2){
        if(a % 2 == 0){
            printf("o primeiro numero eh par\n");
            printf("o segundo numero eh par\n");
            printf("o resultado eh %lu, que eh par\n", a * b);
        }else{
            printf("o primeiro numero eh impar\n");
            printf("o segundo numero eh impar\n");
            printf("o resultado eh %lu, que eh impar", a * b);
        }
    }else{
        if(a % 2 == 0){
            printf("o primeiro numero eh par\n");
            printf("o segundo numero eh impar\n");
        }else{
            printf("o primeiro numero eh impar\n");
            printf("o segundo numero eh par\n");
        }
        printf("o resultado eh %lu, que eh impar", a + b);
    }
}
