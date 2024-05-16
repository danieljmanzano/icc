#include <stdio.h>
#include <string.h>

//printa uma string partindo do meio e indo pros canto

int main(){
    char vetor[100], vetor2[100];
    scanf("%s", vetor);
    int desgraca;
    int tamanho = strlen(vetor);
    if(tamanho % 2 == 1){
        desgraca = (tamanho / 2) + 1;
    }else{
        desgraca = tamanho / 2;
    }
    for(int i = 0; i <= tamanho; i++){
            vetor2[i] = vetor[desgraca - 1];
            if(i % 2 == 0){
                desgraca += (i + 1);
            }else{
                desgraca -= (i + 1);
            }
        }
    for(int j = 0; j < tamanho; j++){
        printf("%c", vetor2[j]);
    }
}
//muito loco deu tudo certo
//ex.: digita abcde e sai cdbae