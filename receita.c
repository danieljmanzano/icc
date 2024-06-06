#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ex. pra guardar receitas, ingredientes e fazer as receitas com base nos ingredientes que tenho

typedef struct{ //todas informações que uma receita pode possuir
    char *nome; //nome da receita
    int farin, ovo, oleo, acuc, choc; //ingredientes que ela precisa pra ser feita
}rec; 

typedef struct{
    int farin, ovo, oleo, acuc, choc; //numero de ingredientes que tenho guardados (dep == deposito)
}dep; 

rec novareceita(){ //uso essa função pra guardar uma nova receita
    rec receita;
    char nome[20]; //vou usar como auxiliar pra receber os nomes de receitas
    
    scanf(" %s", nome); 
    receita.nome = (char*) malloc (sizeof(char) * (strlen(nome) + 1));
    strcpy(receita.nome, nome); //coloco o nome numa string alocada certin

    scanf("%d %d %d %d %d", &receita.farin, &receita.ovo, &receita.oleo, &receita.acuc, &receita.choc); //recebo as outras informações
    return receita;
}

int vedeposito(dep *deposito, rec *receita){ //quando chamo essa função ele analisa se é possível fazer a receita (e já faz se for possível)
    if(deposito->farin >= receita->farin && deposito->ovo >= receita->ovo && deposito->oleo >= receita->oleo && deposito->acuc >= receita->acuc && deposito->choc >= receita->choc){
        deposito->farin -= receita->farin;
        deposito->ovo -= receita->ovo;
        deposito->oleo -= receita->oleo;
        deposito->acuc -= receita->acuc;
        deposito->choc -= receita->choc;
        return 1; //retorna 1 pra uma flag se fez a receita
    }
    return 0; //retorna 0 caso não tenha conseguido fazer
}

void compraingr(dep *deposito){ //meio óbvio sobre o que faz 
    int quant;
    scanf(" %d", &quant);
    deposito->farin += quant;
    scanf(" %d", &quant);
    deposito->ovo += quant;
    scanf(" %d", &quant);
    deposito->oleo += quant;
    scanf(" %d", &quant);
    deposito->acuc += quant;
    scanf(" %d", &quant);
    deposito->choc += quant;
}

void fazreceita(dep *deposito, int i, rec *receita){
    int flag = 0, flag2 = 0, index; //flag eu uso pra ver se consigo fazer a receita ou não (caso não consiga, eu procuro o ingrediente que falta)
    scanf("%d", &index);            //a flag2 é pra verificar se a receita digitada realmente existe
    for(int j = 0; j < i; j++){
        if(j == index){
            flag2 = 1;
            flag = vedeposito(deposito, &receita[j]);
            if(flag){
                printf("%s feita com sucesso!\n", receita[index].nome);
                break;
            }
            if(!flag){
                if(deposito->farin < receita[j].farin){
                    printf("Farinha insuficiente\n");
                    return;
                }
                if(deposito->ovo < receita[j].ovo){
                    printf("Ovos insuficientes\n");
                    return;
                }
                if(deposito->oleo < receita[j].oleo){
                    printf("Oleo insuficiente\n");
                    return;
                }
                if(deposito->acuc < receita[j].acuc){
                    printf("Acucar insuficiente\n");
                    return;
                }
                if(deposito->choc < receita[j].choc){
                    printf("Chocolate insuficiente\n");
                    return;
                }
            }
        }
    }
    if(!flag2) printf("Receita nao encontrada!\n"); 
    return;
}

int main(void){
    rec *receita = NULL; //vou guardar as informações de cada respectiva receita aqui (vai virar um vetor dps)
    dep deposito;
    deposito.farin = deposito.ovo = deposito.oleo = deposito.acuc = deposito.choc = 0;
    char comando;
    int i = 0;

    while(1){
        scanf(" %c", &comando);
        if(comando != 82 && comando != 67 && comando != 83 && comando != 70) printf("Codigo invalido\n");
        if(comando == 82){ //82 == R
            receita = realloc(receita, sizeof(rec) * (i + 1));
            receita[i] = novareceita();
            i++;
        }
        if(comando == 67){ //67 == C
            compraingr(&deposito);
            
        }
        if(comando == 70){ //70 == F
            fazreceita(&deposito, i, receita);
        }
        if(comando == 83){ //83 == S
            printf("Quantidade no estoque:\n");
            printf("Acucar: %d\n", deposito.acuc);
            printf("Chocolate: %d\n", deposito.choc);
            printf("Farinha: %d\n", deposito.farin);
            printf("Oleo: %d\n", deposito.oleo);
            printf("Ovos: %d\n", deposito.ovo);
            printf("Receitas cadastradas: %d", i);
            return 0;
        }
    }
    free (receita);
    receita = NULL;
}