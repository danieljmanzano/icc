#include <stdio.h>
int main(){
char carac;
int num;

scanf("%c%d", &carac, &num);

printf("numero correspondente: %d\n", carac);
printf("caracter correspondente: %c\n", num);
printf("octal: %o\n", num);
printf("hexadecimal: %x\n", num);
}

