#include <stdio.h>
#include <stdlib.h>

char **alocamatriz(int n, int m){
    char **pont = NULL;
    pont = (char **) malloc (sizeof(char*) * n);
    if(pont == NULL) exit (1);
    for(int i = 0; i < m; i++){
        pont[i] = (char *) malloc (sizeof(char) * n);
        if(pont[i] == NULL) exit (1);
    }
}

int main(void){
    int n, m;
    char **matriz;
    scanf(" %d %d", &n, &m);
    matriz = alocamatriz(n, m);
}