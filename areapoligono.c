#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846;
int main(){
    int n;
    double l, area, pi = M_PI;
    scanf("%d%lf", &n, &l);
    area = (n * l * l)/(4 * tan(pi / n));
    printf("%lf\n", area);

}