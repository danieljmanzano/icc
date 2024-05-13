#include <stdio.h>
int main(){
    int n, a,cont = 0;
    scanf("%d", &n);
    a = n % 5; 
    n -= a;
    while(n > 0){
        if(n % 1953125 == 0){
            cont += 9;
        }else if(n % 390625 == 0){
            cont += 8;
        }else if(n % 78125 == 0){
            cont += 7;
        }else if(n % 15625 == 0){
            cont += 6;
        }else if(n % 3125 == 0){
            cont += 5;
        }else if(n % 625 == 0){
            cont += 4;
        }else if(n % 125 == 0){
            cont += 3;
        }else if(n % 25 == 0){
            cont += 2;
        }else if(n % 5 == 0){
            cont++;
        }
        n -= 5;
    }
    printf("%d\n", cont);
}
//intankavel