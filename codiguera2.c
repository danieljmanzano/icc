#include <stdio.h>
int main(){
int dia, mes, ano;

scanf("%2d", &dia);
scanf("%2d", &mes);
scanf("%4d", &ano);

printf("%02d/%02d/%d\n", dia, mes, ano);
return 0;
}
//formatador de data (caso nao tenha dado pra perceber)