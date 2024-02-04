#include <stdio.h>
#include <stdlib.h>
#define QTD_MAX_LANCHONETE  1000
#define SUCESSO             1
#define FALHA              -1

struct Celula {
    int tamanho;
    int vetor[QTD_MAX_LANCHONETE];
    struct Celula* proximo;
};

struct ListaLinear {
    struct Celula* inicio;
};

void inicializarLista(struct ListaLinear* lista) {
    lista->inicio = NULL;
}

void inserirCelula(struct ListaLinear* lista, int tamanho, int vetor[QTD_MAX_LANCHONETE]) {
    struct Celula* novaCelula = (struct Celula*)malloc(sizeof(struct Celula));
    int i;
    
    if (novaCelula == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    
    novaCelula->tamanho = tamanho;
    for (i = 0; i < tamanho; i++) {
        novaCelula->vetor[i] = vetor[i];
    }
    
    novaCelula->proximo = NULL;
    
    if (lista->inicio == NULL) {
        lista->inicio = novaCelula;
        return;
    }
    
    struct Celula* atual = lista->inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    atual->proximo = novaCelula;
}

void imprimirLista(struct ListaLinear* lista) {
    struct Celula* atual = lista->inicio;
    int i;
    
    while (atual != NULL) {
        printf("%d ", atual->tamanho);
        for (i = 0; i < atual->tamanho; i++) {
            printf("%d ", atual->vetor[i]);
        }
        printf("\n");
        atual = atual->proximo;
    }
}


int main(){
    int             qtdDeLanchonetesInformada; 
    int             i,j;
    int             qtdDias;
    int             intResultado;
    struct ListaLinear minhaLista;

    inicializarLista(&minhaLista);

    scanf("%d",&qtdDeLanchonetesInformada);
    int lanchonetes[qtdDeLanchonetesInformada];

    //LEITURA DOS VALORES DOS CAFES
    for(i=0;i<qtdDeLanchonetesInformada;i++){
        scanf("%d",&lanchonetes[i]);
    }

    //LEITURA DE DIAS QUE PRETENDE-SE COMPRAR BEBIDAS
    scanf("%d",&qtdDias);    

    for(i=0;i<qtdDias;i++){
        int qtdDeMoedasDisponiveis;
        int lanchonetes_compraveis[qtdDeLanchonetesInformada];
        int count = 0; 

        scanf("%d",&qtdDeMoedasDisponiveis); 

        //PERCORRER O VETOR DE LANCHONETES
        for(j=0;j<qtdDeLanchonetesInformada;j++){
            if(qtdDeMoedasDisponiveis>=lanchonetes[j]){
                lanchonetes_compraveis[count] = j+1;
                count++;
            }
        }
        
        inserirCelula(&minhaLista, count, lanchonetes_compraveis);
    }

    imprimirLista(&minhaLista);   
}