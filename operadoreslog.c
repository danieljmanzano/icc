#include <stdio.h>
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b  &&  (a - b) % 3 == 0){
        printf("%d", a + b);
    }else if(b > a  &&  a + b > 400){
        printf("%d", a + b);
    }else if(a == b  &&  b % 2 == 1){
        printf("%d", a + b);
    }else{
        printf("Nenhuma condicao foi satisfeita\n");
    }
}