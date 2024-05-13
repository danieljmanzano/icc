#include <stdio.h>
int main(){
    int n, i = 1;
    unsigned long long int res = 1;
    scanf("%d", &n);
    if(n == 1){
        printf("1");
        return 0;
    }
    while(i <= n){
        res = res * i;
        i++;
        printf("%lu (no momento) ", res);
    }
    printf("%llu", res);
}