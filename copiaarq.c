#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//programa que vai lendo um arquivo binario e printando o que tem nele
//bem basico mas bom pra treinar arquivos

int main(void){
    FILE *fp;
    char *nomearq = NULL, c; //char c vai receber o conteúdo do ponteiro de file e printar aqui no programa
    nomearq = malloc(15 * sizeof(char)); //aloco com a quantidade máxima possível de caracter (talvez até mais que o necessário rsrs)
    scanf("%s", nomearq); //leio o nome do arquivo
    nomearq = realloc(nomearq, strlen(nomearq) * sizeof(char)); //realoco com o tamanho necessário

    if((fp = fopen(nomearq, "rb")) == NULL){
        printf("Erro na abertura do arquivo\n");
        exit (1);
    }

    c = getc(fp); //daqui pra frente só vou lendo do arquivo e printando aqui
    while(!feof(fp)){
        printf("%c", c);
        c = getc(fp);
    }

    fclose(fp);
    free(nomearq);
    fp = nomearq = NULL;
    return 0;
}