#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

//exercício pra contar a quantidade de vezes que uma certa palavra aparece em um certo arquivo de texto (desconsiderando diferenças em maiusculo ou minusculo)

int procura(FILE *fp, char palavra[], int tamP){
    char c;
    int cont = 0, flag = 0, flagespaco = 0, flagespaco2 = 0; ///cont conta a quantidade de palavra que me interessa, flag é pra verificar se achei de fatoa palavra e as flagespaco tem explicado ali embaixo
    
    c = getc(fp); //pego o primeiro caractere do arquivo fora do while (não gosto de do while, desculpa)
    while(!feof(fp)){ 
        if((c == palavra[0] || c == palavra[0] - 32 || c == palavra[0] + 32) && flagespaco){ //testa se c é igual à primeira letra da palavra (o -32 e +32 é pra considerar maiusculo e minusculo) / a flag espaço da pra entender ali embaixo
            for(int i = 0; i < tamP; i++){ //se for, entra no for (trocadilho não intencional) e vou comparando até acabar a minha palavra
                if(c == palavra[i] || c == (palavra[i] - 32) || c == (palavra[i] + 32)){ 
                    flag = 1; //coloco a flag 1
                    c = getc(fp); //pego o próximo caractere
                }else{ //se tiver alguma letra diferente, coloco a flag 0 (não achei a palavra) e dou break
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){ //caso tenha saído do for com a flag ativa, quer dizer que encontrei a palavra
            cont++; //add no contador
            flag = 0; //coloco a flag 0 pra voltar a checar denovo depois
        }

        c = getc(fp); //sempre pego o próximo caractere

        //todo esse bloco abaixo é pra não contar quando acho uma palavra dentro de outra (ex.: 'ana' em 'banana', não posso contar)
        //pra isso, tenho que ver se antes do caractere em que comecei a comparação tinha um espaço
        if(c == 32){ //vejo se o caractere que peguei é um espaço
            flagespaco = 1;  //coloco as duas flags como 1 
            flagespaco2 = 1;
        }else if(flagespaco && flagespaco2){ //se as duas flags forem 1, quer dizer que o caractere anterior foi um espaço
            flagespaco2 = 0; //puxo a seguna flag pra 0 mas mantenho a flagespaco como 1 pra mostrar que antes teve um espaço, aí vai fazer a condiçao la de cima funcionar normal
        }else if(flagespaco && !flagespaco2){ //se a flagespaco é 1 e a 2 é 0, quer dizer que ja passei o caractere que tava logo depois do espaço
            flagespaco = 0; //aí coloco a flag pra 0 pra poder fazer sentido
        } //basicamente, as duas flags em conjunto teoricamente representam o funcionamento de uma flag que teria um ciclo de delay dentro do laço pra desativar
    }

    return cont; //retorno quantas palavra achei
}

int main(void){
    char *palavra = NULL, *nomearq = NULL;
    int quant, tamP;
    FILE *fp;

    nomearq = (char *) malloc(sizeof(char) * 6);  //tamanho fixo do nome de arquivo
    palavra = (char *) malloc(sizeof(char) * 11); //tamanho maximo que a palavra pode ter

    scanf("%s", nomearq); //le o nome do arquivo
    scanf(" %s", palavra);//le a palavra que quero procurar

    tamP = strlen(palavra);
    palavra = realloc (palavra, tamP * sizeof(char));

    if((fp = fopen(nomearq, "r")) == NULL){ //vejo se a abertura de arquivo deu certo (só nessa condicional eu ja abro com o fp)
        printf("Erro na abertura do arquivo\n");
        exit (1);
    }

    quant = procura(fp, palavra, tamP); //funçao volta a quantidade de palavras (obrigado por avisar daniel)
    printf("quantidade: %d", quant); //printa, cabo, é nois

    free(palavra);
    free(nomearq);
    nomearq = palavra = NULL;

    return 0;
}

//colocaram a letra de lateralus do tool no arquivo de teste, valeu monitores