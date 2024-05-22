#include <stdio.h>
#include <stdlib.h>
//repetindo aquele exercicio dos conjuntos dos vetores (nome do bagui: conjuntosvetores.c)
//SÓ QUE dessa vez com locação de memória dinâmica e uns negocio a mais

void ordena(int *vetor, int n){ //funcao pra ordenar os vetor
    int compara;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(vetor[j] < vetor[k]){
                compara = vetor[j];
                vetor[j] = vetor[k];
                vetor[k] = compara;
            }
        }
    }
    return;
}

int *le(int n){ ///funçao pra ler e mandar de volta o vetor que eu quiser trazer pra cá (uso pro vet1 e vet2)
    int *vetor = NULL;
    vetor = (int *) malloc (sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf(" %d", &vetor[i]);
    }
    return vetor;
}

void printa(int *vetor, int n){ //funçao pra printar as funçoes que eu quiser trazer pra cá (uso pro vet1, vet2, uniao e uniao - interseçao)
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    return;
}

int *intersecao(int *vet1, int *vet2, int n1, int n2, int *cont){ //uso a funçao pra criar a interseçao 
    int *inter = NULL;

    if(!n1 || !n2) return inter; //caso algum conjunto seja vazio, a interseçao volta nula

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(vet1[i] == vet2[j]){
                (*cont)++;
                inter = (int*) realloc(inter, (*cont)*sizeof(int)); //esse lance de realocar a cada um que adiciona é ideia do bernardo
                inter[(*cont)-1] = vet1[i]; //(eu nunca daria conta de fazer isso certo, obg bernas)
                break;
            }
        }
    }
    return inter;
}

int *uniao(int *vet1, int *vet2, int n1, int n2, int *cont){ //assim como na interseçao, crio a uniao aqui
    int *un = NULL;

    if(!n1 && !n2){ //caso os dois conjuntos sejam vazios, volto com "un" nulo (nao tem nos casos testes, mas se tivesse daria certo ok)
        printf("vazio");
        return un;
    }

    for(int i = 0; i < n1; i++){ //adiciona na uniao todos os numeros do primeiro vetor
        (*cont)++;
        un = (int*) realloc(un, (*cont)*sizeof(int)); //denovo o lance de realocar os que adiciona
        un[(*cont)-1] = vet1[i]; 
    }

    for(int i=0; i<n2; i++){ //agora adiciona os do vetor 2
        int tem=0;
        for(int j=0; j<n1; j++) {
            if(vet1[j] == vet2[i]){ //verifica se o numero ta dentro do vetor 1
                tem=1; //se tiver, nao coloco la dentro (usa o "tem" como flag)
                break;
            }
        }
        if(!tem){
            (*cont)++;
            un = (int*) realloc(un, (*cont)*sizeof(int));
            un[(*cont)-1] = vet2[i]; 
        }
    }
    return un;
}

int *subtrai(int *un, int *inter, int tamU, int tamI, int *tamSub){ //funcao pra achar o vetor da subtraçao entre a uniao e a interseçao
    int *sub = NULL; 

    if(!tamU && !tamI){ //se ambos forem vazios printa aqui
        return sub; //(vou printar vazio na volta daqui pra main)
    }

    for(int i = 0; i < tamU; i++){
        int verifica = 0;
        for(int j = 0; j < tamI; j++){
            if(un[i] == inter[j]){
                verifica = 1;
                break;
            }
        }
        if(!verifica){
            (*tamSub)++;
            sub = (int*) realloc(sub, (*tamSub)*sizeof(int));
            sub[(*tamSub)-1] = un[i];
        }
    }
    return sub;
}

int main(void){
    int n1 = 0, n2 = 0, *vet1 = NULL, *vet2 = NULL;

    scanf("%d", &n1);
    vet1 = le(n1);
    ordena(vet1, n1);
    printf("conjunto A: ");
    if(n1){
        printa(vet1, n1);
    }else{
        printf("vazio");
    }

    scanf("%d", &n2);
    vet2 = le(n2);
    ordena(vet2, n2);
    printf("\nconjunto B: ");
    if(n2){
        printa(vet2, n2);
    }else{
        printf("vazio");
    }

    int tamI=0;
    int *inter = intersecao(vet1, vet2, n1, n2, &tamI);
    ordena(inter, tamI);

    int tamU = 0;
    int *un = uniao(vet1, vet2, n1, n2, &tamU);
    printf("\nA uniao B: ");
    if(un == NULL){
        printf("vazio");
    }else{
        ordena(un, tamU);
        printa(un, tamU);
    }

    printf("\n(A uniao B) - (A interseccao B): ");
    int tamSub = 0;
    int *sub = subtrai(un, inter, tamU, tamI, &tamSub);
    if(sub==NULL){
        printf("vazio"); //caso nao retorne nada la da funcao quer dizer que a subtraçao é vazia
    }else{
        ordena(sub, tamSub);
        printa(sub, tamSub); //senao, ordeno e printo ela pra acabar
    }

    free(un);
    free(inter);
    free(sub);
    free(vet1);
    free(vet2);
    sub = un = inter = vet1 = vet2 = NULL; //libera geral pra caba (faz alguma diferença?)
}
//aqui no final percebi que o certo é intersecçao mas agora ja é tarde pra mudar, eh nois
//tinha feito até uma certa parte que tava dando segfault em um caso particular, aí o bernardo deu uma arrumada geral rsrs