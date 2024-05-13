#include <stdio.h>
int main(){
    int v;
    scanf("%d", &v);
    printf("%d nota(s) de R$ 200\n", v / 200);
    v = v % 200;
    printf("%d nota(s) de R$ 100\n", v / 100);
    v = v % 100;
    printf("%d nota(s) de R$ 50\n", v / 50);
    v = v % 50;
    printf("%d nota(s) de R$ 20\n", v / 20);
    v = v % 20;
    printf("%d nota(s) de R$ 10\n", v / 10);
    v = v % 10;
    printf("%d nota(s) de R$ 5\n", v / 5);
    v = v % 5;
    printf("%d nota(s) de R$ 2\n", v / 2);
    v = v % 2;
    printf("%d moeda(s) de R$ 1\n", v);
}