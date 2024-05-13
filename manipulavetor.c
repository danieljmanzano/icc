#include <stdio.h>
#include <ctype.h>
int main(){
    int num, vet[100], vetfib[20], compara = 0, nummax, fib1 = 0, fib2 = 1, fibaux;
    char carac;
    scanf("%d", &num);
    for(int i = 0; i < 100; i++){
        if(num == 1){
            break;
        }
        vet[i] = num;
        scanf("%d", &num);
        nummax = i + 1;
    }

    scanf(" %c", &carac);
    
    if(carac != 'a' && carac != 'b' && carac != 'c'){
        printf("Comando inexistente\n");
        return 0;
    }

    if(carac == 'a'){
        for(int j = 0; j < nummax; j++){
            for(int k = 0; k < nummax; k++){
                if(vet[j] < vet[k]){
                    compara = vet[j];
                    vet[j] = vet[k];
                    vet[k] = compara;
                }
            }
        }
        printf("vetor ordenado:");
        for(int l = 0; l < nummax; l++){
            printf("%d ", vet[l]);
        }
    }
    
    if(carac == 'b'){
        for(int t = 0; t < 20; t++){
            fibaux = fib2;
            fib2 += fib1;
            fib1 = fibaux;
            vetfib[t] = fib2;
        }
        printf("Numeros de Fibonacci:");
        for(int a = 0; a < nummax; a++){
            for(int u = 0; u < 20; u++){
                if(vetfib[u] == vet[a]){
                    printf("%d ", vetfib[u]);
                }
            }
        }
    }

    if(carac == 'c'){
        printf("Vetor maiusculo:");
        for(int b = 0; b < nummax; b++){
            printf("%c ", toupper(vet[b]));
        }
    }
}