#include <stdio.h>

//recebe uma palavra e ve se ela tem um anagrama que possa ser um palindromo

int main(){
    int n, cont = 0, verifica = 0, alfabeto[26];
    scanf("%d", &n);
    char palavra[n];
    
    for(int p = 0; p < n; p++){ 
        scanf(" %c", &palavra[p]);
    }

    for(int contalf = 0; contalf < 26; contalf++){ //for para colocar todas posições do vetor alfabeto = 0
        alfabeto[contalf] = 0;
    }

    if(n % 2 == 0){ //testando se existe anagrama palíndromo em palavra com letras pares
        for(int i = 0; i < n; i++){      //aqui coloco valor +1 cada vez que uma letra aparece na palavra
            alfabeto[palavra[i] - 97]++; //97 é 'a' na tabela ASCII, então a posição no alfabeto de uma letra específica cai no seu respectivo número no vetor
        }
        for(int j = 0; j < 26; j++){
            if(alfabeto[j] % 2 == 1){ //testando o caso de uma letra da palavra aparecer um número ímpar de vezes (impossibilita o palíndromo)
                printf("Nao\n");
                return 0;
            }else{
                verifica = 1; //variável para receber 1 caso o palíndromo seja possível (guarda pra printar sim mais pra frente)
            }
        }
    }else{ //testando se existe anagrama palíndromo em palavra com letras ímpares
        for(int i = 0; i < n; i++){
            alfabeto[palavra[i] - 97]++; //mesma lógica lá de cima
        }
        for(int k = 0; k < 26; k++){
            if(alfabeto[k] % 2){ //testa caso existe alguma letra que se repete um número ímpar de vezes
                cont++;          //acrescenta 1 se tem alguma
            }
        }
    }
    if(verifica){
        printf("Sim\n"); //printa pra palavra com par que tem palíndromo
        return 0;
    }else if(cont > 1){  //caso tenha mais de uma letra que se repete um número ímpar de vezes, não existe palíndromo
        printf("Nao\n");
        return 0;
    }else if(cont == 1){ //caso tenha uma única letra que apareça um número ímpar de vezes, é possível o palíndromo
        printf("Sim\n");
        return 0;
    }
}

