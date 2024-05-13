#include <stdio.h>
int main(){
    int a, b, maior = 0, menor;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++){
        for(int j = 2; j <= i; j++){
            if(i % j == 0 && i != j){    
                break;
            }else if(i % j == 0 && j == i){
                maior = j;
            }
        }
    }
    menor = maior;
    for(int i = b; i >= a; i--){
        for(int j = 2; j <= i; j++){
            if(i % j == 0 && j != i){
                break;
            }else if(i % j == 0 && j == i){
                menor = j;
            }
        }
    }
    if(maior != 0){
        printf("menor primo: %d\n", menor);
        printf("maior primo: %d\n", maior);
    }else{
        printf("nenhum primo no intervalo\n");
    }
}