#include <stdio.h>
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
