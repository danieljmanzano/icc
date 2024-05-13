#include <stdio.h>
int main(){
    int n, *pont;
    scanf("%d", &n);
    int vetor[n];
    pont = vetor;
    for(int i = 0; i < n; i++){
        scanf("%d", pont);
        pont++;
    }
    pont--;
    for(int i = n; i > 0; i--){
        printf("%d ", *pont);
        pont--;
    }
}