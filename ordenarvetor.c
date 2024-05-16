#include <stdio.h>

//obviamente, ordena um vetor

int main(){
    int n, vetor[100], compara = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(vetor[j] < vetor[k]){
                compara = vetor[j];
                vetor[j] = vetor[k];
                vetor[k] = compara;
            }
        }
    }
    for(int l = 0; l < n; l++){
        printf("%d ", vetor[l]);
    }
}