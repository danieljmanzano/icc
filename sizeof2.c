#include <stdio.h>
int main(){
    long int n;    
    scanf("%lu", &n);
    printf("char: %lu\n", n * sizeof(char));
    printf("int: %lu\n", n * sizeof(int));
    printf("double: %lu\n", n * sizeof(double));
}
    
