#include <stdio.h>
int main(){
    float p1, p2, l1, l2, l3, l4;
    scanf("%f%f%f%f%f%f", &p1, &p2, &l1, &l2, &l3, &l4);
    float nlistas = (l1 + l2 + l3 + l4)/4;
    if(nlistas == 0){
        printf("Reprovado");
        return 0;
    }
    if((p1 + p2 + nlistas)/3 >= 5){
        printf("Aprovado\n");
    }else if((p1 + p2 + nlistas)/3 >= 3 && (p1 + p2 + nlistas)/3 < 5){
        printf("Recuperacao\n");
    }else{
        printf("Reprovado\n");
    }
}