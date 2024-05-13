#include <stdio.h>
int main(){
    
    char palavra[26], *pont;
    scanf("%[^\n]", palavra);
    pont = &palavra[0];
    
    while(*pont != '\0'){
        printf("%c\n", *pont);
        pont++;
    }
}