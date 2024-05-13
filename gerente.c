#include <stdio.h>
int main(){
    int n, indprod;
    float precoc, precov, quantc, quantv; //o c em precoc é de comprado, o v é em vendido
    scanf("%d", &n);
    if(n == 0){
        printf("Sem atividades registradas hoje\n");
        return 0;
    }
    float lucro, lucrorel[n], lucrorelfinal;
    for(int i = 0; i < n; i++){
        scanf("%f %f %f %f", &precoc, &precov, &quantc, &quantv);
        lucro += (precov * quantv) - (precoc * quantc);
        lucrorel[i] = (precov * quantv) - (precoc * quantc);
    }
    if(lucro > 0){
        printf("lucro: %.2f\n", lucro);
    }else{
        lucro *= -1;
        printf("prejuizo: %.2f\n", lucro);
    }
    lucrorelfinal = lucrorel[0];
    for(int j = 0; j < n; j++){
        if(lucrorelfinal <= lucrorel[j]){
            indprod = j + 1;
            lucrorelfinal = lucrorel[j];
        }
    }
    printf("produto: %d lucro relativo: %.2f\n", indprod, lucrorelfinal);
}