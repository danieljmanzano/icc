#include <stdio.h>
int main(){
    int n1, n2;
    for(int i = 1000; i < 10000; i++){
        n1 = i % 100;
        n2 = i / 100;
        if(i == (n1 + n2)*(n1 + n2)){
            printf("%d\n", i);
        }
    }
}
