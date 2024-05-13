#include <stdio.h>
int main(){
    unsigned int n, n1;
    scanf("%u", &n);
    unsigned int vetor[n];
    scanf("%u", &vetor[0]);
    n1 = vetor[0];
    for(unsigned int i = 1; i < n; i++){
        scanf("%u", &vetor[i]);
        if(vetor[i] > n1){
            n1 = vetor[i];
        }
    }
    printf("%u", n1);
}