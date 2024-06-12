#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//recebe uma palavra e um arquivo binario, tenho que printar todo o arquivo como texto SEM a palavra que foi digitada
//basicamente, eu copio o arquivo e limpo as ocorrências daquela palavra específica nele

int main(void){
    FILE *fp;
    char *palavra = NULL, *nomearq = NULL, c;
    unsigned int posicao, flag = 0, flagespaco = 0; //flag verifica se eu não achei a palavra que procuro, flagespaco é pra arrumar os casos que tao saindo espaço a mais na saida (creio que o problema nao seja meu codigo e sim a saida esperada, mas de qualquer forma dei um jeito)

    palavra = malloc(20 * sizeof(char)); //coloquei 20 pra ter um certo coeficiente de cagaço pra possibilidade de palavra maior
    scanf("%s", palavra);
    palavra = realloc(palavra, strlen(palavra) * sizeof(char));

    nomearq = malloc(9 * sizeof(char)); //9 é o tamanho máximo que o nome do arquivo pode ter
    scanf(" %s", nomearq);
    nomearq = realloc(nomearq, strlen(nomearq) * sizeof(char));

    if((fp = fopen(nomearq, "rb")) == NULL){
        printf("Erro na abertura do arquivo\n");
        exit (1);
    }

    c = getc(fp); //pego a primeira posição do arquivo
    while(!feof(fp)){
        if(!flag){ //essa flag vai dar pra entender mais pra frente
            if(c == palavra[0]){  //se o caractere que to vendo é igual ao incial da palavra, começo a comparar pra ver se é a palavra
                posicao = ftell(fp);                                //guardo a posição que tava antes de entrar no for, caso não seja a palavra que to procurando vou voltar aqui
                for(unsigned int i = 0; i < strlen(palavra); i++){
                    if(c == palavra[i]){                            //caractere do arquivo e da palavra são iguais, vou continuar comparando pra ter certeza que a palavra ta ali mesmo
                        c = getc(fp);                               //ando um caractere pra frente toda vez que a palavra que to procurando tem um caractere aparecendo no arquivo
                        flagespaco = 1;
                    }else{                                          //não é a palavra que to procurando, ent dou break e coloco a flag como 1
                        fseek(fp, (posicao - 1) * sizeof(char), SEEK_SET);//volto pra posição inicial do fp antes de entrar no for
                        c = getc(fp);
                        flagespaco = 0;
                        flag = 1;                                   //ativo a flag (vai servir pra printar a palavra que acabei de analisar sem ter que analisar denovo)
                        break;
                    }
                }
            }
        }

        if(flagespaco){ //toda essa brincadeira pra baixo é só pra nao printar um possivel espaço depois da palavra que eu pulei
            if(c != 32){ //caso o caractere não seja espaço (32 em ASCII)
                printf("%c", c); //printa normal
                c = getc(fp);
                flagespaco = 0; //troca a flag pra 0, não vou querer testar mais se tem espaço ali
            }else{ //caso a flag esteja ativa e o caractere seja, de fato, um espaço, eu não printo ele 
                c = getc(fp); //aqui só to passando pra c o próximo caractere depois do espaço (ou seja, eu "pulo" o espaço)
                flagespaco = 0; //troco pra 0 pq ja testei aqui nesse caso
            }
        }else{ //caso nem a flag esteja ativa (maioria dos casos)
            printf("%c", c); //sigo a lógica normalmente (printo o c e pego o proximo caractere de fp)
            c = getc(fp);
        }

        if(c == 32) { //quando chego no espaço (32 em ASCII), volto com a flag 0 pra poder continuar analisando se eu acho a palavra mais pra frente
            flag = 0; 
        }
    }

    fclose(fp);
    free(nomearq);
    free(palavra);
    nomearq = palavra = NULL;
}