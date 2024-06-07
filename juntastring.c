#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vou receber uma string a, uma string b e uma string de parametro
//a ideia é que eu tenha que printar a string a até aparecer o parametro nela
//e depois printo a string b a partir do momento que termina o parametro nela
//ex.: palmeiras campeao (stra)/ campeao palmeiras (strb)/ campeao (parametro) -> printa palmeiras palmeiras

char *lestring(){
    char *string, stringaux[130];
    scanf(" %[^\n]", stringaux);
    fflush(stdin);
    string = (char*) calloc (sizeof(char), strlen(stringaux));
    strcpy(string, stringaux);
    return string;
}

int comparastringA(char *str, char *strp, int t, int tp){
    int ponto = t; //vou guardar o ponto na string em que o parametro aparece (inicializa no t pra caso o parametro não apareça em nenhum momento e não printe na volta)
    for(int i = 0; i < t; i++){
        for(int j = 0; j < tp; j++){
            if(str[i] == strp[j]){ //caso o caracter nessa posição seja igual nos dois, checo se vai ser o parametro mesmo
                for(int k = 0; k < tp; k++){
                    if(str[i + k] == strp[k]){ //vou checando os caracteres até o fim do parametro
                        if(k == 0){
                            ponto = i; //marco onde começa o parametro na string 
                        }
                    }else{ //caso a comparação não dê certo, saio desse for e volto pra procurar o parametro denovo
                        ponto = t;
                        break;
                    }
                    if(k == tp - 1){
                        return ponto; //quando chegar no final da string parametro e tiver tudo certo, ja retorno o ponto
                    } //alias, coloquei esse if dps de tudo pq se tivesse dado errado antes ele ja teria saido no break de cima
                }
            }else break; //mesma coisa da linha 24 (só não altero o valor de ponto)
        }
    }
    return ponto + 1;
}

int comparastringB(char *str, char *strp, int t, int tp){ //mais ou menos igual a função de cima (comentarios quase identicos pq dei ctrl c ctrl v rsrs)
    int ponto = 0; //vou guardar o ponto na string em que o parametro termina (começa no 0 pra caso o parametro não apareça em nenhum momento)
    for(int i = 0; i < t; i++){
        for(int j = 0; j < tp; j++){
            if(str[i] == strp[j]){ //caso o caracter nessa posição seja igual nos dois, checo se vai ser o parametro mesmo
                for(int k = 0; k < tp; k++){
                    if(str[i + k] == strp[k]){ //vou checando os caracteres até o fim do parametro
                        if(k == tp - 1){
                            ponto = i + tp; //marco onde termina o parametro na string
                            return ponto;
                        }
                    }else{ //caso a comparação não dê certo, saio desse for e volto pra procurar o parametro denovo
                        ponto = 0;
                        break;
                    }
                }
            }else break; //mesma coisa do comentário de cima
        }
    }
    return t; //caso eu não tenha achado o parametro, mando de volta o proprio tamanho da string (pra nao printar quando voltar)
}
//esses for's são um tanto complexos mas tentei sempre que possível colocar um break na situação pra aliviar

int main(void){
    char *stra = NULL, *strb = NULL, *strp = NULL; //string A, string B e string parametro
    int ta, tb, tp, pontoa, pontob; //tamanho A, tamanho B e tamanho parametro

    stra = lestring();
    ta = strlen(stra);
    strb = lestring();
    tb = strlen(strb);
    strp = lestring();
    tp = strlen(strp);

    pontoa = comparastringA(stra, strp, ta, tp); //pego o ponto em que o parametro começa na string a
    pontob = comparastringB(strb, strp, tb, tp); //pego o ponto em que o parametro termina na string b

    for(int i = 0; i < pontoa - 1; i++){
        printf("%c", stra[i]); //vou printando o que preciso, nada mais nada menos
    }

    if(pontoa == 0){ //como dentro do primeiro for eu tiro o espaço, caso a primeira string seja só o parametro, eu "pulo" o espaço nesse for de baixo
        for(int i = pontob + 1; i < tb; i++){ //o pulo de espaço eu faço na "pontob + 1"
            printf("%c", strb[i]);
        }
        return 0;
    }

    for(int i = pontob; i < tb; i++){
        printf("%c", strb[i]);
    }
    
    return 0;
}
//acho que em casos extremamente nada ver a logica nao funciona, mas como nos casos testes (e no proprio enunciado) nao somos obrigados a lidar com eles meio que ignorei