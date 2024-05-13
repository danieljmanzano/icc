#include <stdio.h>
#include <math.h>

float hipotenusa(float a, float b){
    int h;
    h = sqrt(pow(a,2) + pow(b,2));
    return h;
}

int main(void){
    float x, y;
    scanf("%f %f", &x, &y);
    printf("%.2f", hipotenusa(x, y));
}
//com math.h rsrsrs