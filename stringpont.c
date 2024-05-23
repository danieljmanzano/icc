#include <stdio.h>

//printa as letras de uma palavra linha por linha usando ponteiro
//bem paia mas bom pra exercitar ponteiro (e pra lembrar como aqule negocio da linha 9 funciona pra ler)

int main(){
    
    char palavra[26], *pont;
    scanf("%[^\n]", palavra);
    pont = &palavra[0];
    
    while(*pont != '\0'){
        printf("%c\n", *pont);
        pont++;
    }
}
