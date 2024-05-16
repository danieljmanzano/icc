#include <stdio.h>
int main(){
    int a, b, vazio = 1, numdif = 0;
    int veta[10], vetb[10];
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        scanf("%d", &veta[i]);
    }
    scanf("%d", &b);
    printf("intersecao: ");
    for(int j = 0; j < b; j++){
        scanf("%d", &vetb[j]);
    }
    for(int d = 0; d < a; d++){
        for(int e = 0; e < b; e++){
            if(veta[d] == vetb[e]){
                printf("%d ", vetb[e]);
                vazio = 0;
            }
        }
    }
    if(vazio){
        printf("vazio");
    }
    vazio = 1;
    printf("\na - b: ");
    if(b == 0){
        for(int z = 0; z < a; z++){
            printf("%d ", veta[z]);
        }
        return 0;
    }
    for(int l = 0; l < a; l++){
        for(int m = 0; m < b; m++){
            if(veta[l] != vetb[m]){
                numdif = 1;
            }else{
                numdif = 0;
                break;
            }
        }
        if(numdif){
            printf("%d ", veta[l]);
            vazio = 0;
        }
        numdif = 0;
    }
    if(vazio){
        printf("vazio\n");
    }
}
//misericordia
//printar a interseção e a diferença entre dois conjuntos de números fornecidos