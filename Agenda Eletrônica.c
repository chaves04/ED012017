#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agenda{
    char nome[30];
    char telefone[11];
    char endereço[30];

    struct agenda *prox;
}agenda;

struct agenda *aloca(){
    return malloc(sizeof(agenda));
}

void InsereNome (agenda *cabeca){
    agenda *aux, *novo;

    aux = cabeca;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    novo = aloca();

    printf("Digite o nome: ");
    gets (novo->nome);
    novo->prox = NULL;

    aux->prox = novo;
};

int main(){
    agenda acervo;
    acervo.prox = NULL;

    InsereNome (&acervo);
    printf("%s\n",acervo.prox->nome);

}
