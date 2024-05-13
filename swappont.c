#include <stdio.h>
int main(){
    int num1, num2, num3, *pont1, *pont2;
    scanf("%d %d", &num1, &num2);
    num3 = num1;
    pont1 = &num2;
    num1 = *pont1;
    pont2 = &num3;
    num2 = *pont2;
    printf("%d %d", num1, num2);
}
//muito inutil usar ponteiro aqui, é só pra exercitar