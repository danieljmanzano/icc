#include <stdio.h>
int main(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a == 0 || b == 0 || c == 0 || d == 0){
        printf("nenhum!");
        return 0;
    }
    if(a == b  &&  c == d  &&  a == c){
        printf("quadrado!");
    }else if(a == c && b == d){
        printf("retangulo!");
    }else{
        printf("nenhum!");
    }
}