#include <stdio.h>
int main(){
    unsigned short int a, b, c;
    long long int d;
    scanf(" %hu %hu %hu", &a, &b, &c);
    d = c;
    d = d<<16;
    d += b;
    d = d<<16;
    d += a;
    printf("%llu\n", d);
}
