#include <stdio.h>
int main(){
    int n, m, vetorn[100], vetorm[100], soma = 0, pot2 = 1, *pontn, *pontm;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vetorn[i]);
    }
    pontn = &vetorn[n - 1];
    
    for(int j = 0; j < m; j++){
        scanf("%d", &vetorm[j]);
    }
    pontm = &vetorm[m - 1];
    
    for(int k = 0; k < n; k++){
        soma += pot2 * (*pontn);
        pot2 *= 2;
        pontn--;
    }
    pot2 = 1;
    for(int l = 0; l < m; l++){
        soma += pot2 * (*pontm);
        pot2 *= 2;
        pontm--;
    }
    printf("%d", soma);
}