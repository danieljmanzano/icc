#include <stdio.h>

//nem lembro mais como era o enunciado, mas basicamente era pra resolver um exercicio de prova de icc1
//o codigo nao é meu... tinha feito e tinha ficado paia, ent copiei esse aqui (que deu certo) pra lembrar
//peço desculpas ao autor de quem eu roubei

int main(){
    long int x = 0, s = -1;
    double S = 0, exp = 1, fat = 1;
    scanf("%ld", &x);
    for(int i = 0; i < 20; i++){
        if(i == 0){
            S = x;
            continue;
        }
        exp = 1;
        for(int k = 0; k < i * 2; k++){
            exp *= x;
        }
        fat = 1;
        for(int j = 1; j <= (i*2)+1; j++){
            fat *= j;
        }
        S += s * (exp/fat);
        s *= -1;
    } 
    printf("%.3lf", S);
}
