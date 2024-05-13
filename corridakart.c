#include <stdio.h>
int main(){
    int n, t;
    float v1, v2, d1, d2, deltad;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%f %f %d", &v1, &v2, &t);
        if(t == 0){
            printf("A corrida ainda nao comecou\n");
        }else if(v1 == 0 && v2 == 0 && t != 0){
            printf("Os dois pilotos nao querem competir\n");
        }else if(v1 == 0 && v2 != 0){
            printf("O piloto A desistiu inesperadamente\n");
        }else if(v1 != 0 && v2 == 0){
            printf("O piloto B desistiu inesperadamente\n");
        }else if(t < 0){
            printf("De alguma forma os pilotos voltaram no tempo\n");
        }else if(v1 != 0 && v1 == v2){
            printf("Os karts empataram, percorrendo cada %.2fkm\n", v1 * t);
        }else if(v1 > v2){
            d1 = v1 * t;
            d2 = v2 * t;
            deltad = d1 - d2;
            printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", deltad);
        }else if(v1 < v2){
            d1 = v1 * t;
            d2 = v2 * t;
            deltad = d2 - d1;
            printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", deltad);
        }
    }
}