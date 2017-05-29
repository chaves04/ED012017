/* TRABALHO ESTRUTURA DE DADOS (Agenda Eletrônica)
RAFAEL WAITI  GITIRANA UMETSU - 16/0017114
EMERSON SOUSA CHAVES - 16/0005523
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elemento /*Elementos criados e prontos para dar seguimento a lista encadeada*/
{
    char nome[30];
    char endEletronico[30];
    char num[14];
    struct elemento* proximo;
} t_elemento;

typedef struct lista
{
    t_elemento* primeiro;
} t_lista;

/*------------------------------------------------liberaAgenda----------------------------------------------------------*/

void liberaAgenda(t_lista* lista)
{
    t_elemento* aux = lista->primeiro;

    while( aux != NULL )
    {
        lista->primeiro = lista->primeiro->proximo;
        free(aux);
        aux = lista->primeiro;
    }

    free(aux);
}

/*-----------------------------------------------InsereInicio-----------------------------------------------------------*/

void InsereContato(t_lista* lista)
{
    t_elemento* elemento= (t_elemento *)malloc(sizeof(t_elemento));
    t_elemento* ant = NULL;
    t_elemento* p;
    do
    {
        elemento->nome[29]='\0';
        elemento->nome[0]='\0';
        printf("Digite o nome: ");
        scanf("%[^\n]s", &elemento->nome);
        getchar();
    }
    while((elemento->nome[29] != '\0') && (elemento->nome[0] == '\0'));

    do
    {
        elemento->endEletronico[29]='\0';
        elemento->endEletronico[0]='\0';
        printf("Digite o endereco: ");
        scanf("%[^\n]s", &elemento->endEletronico);
        getchar();
    }
    while((elemento->endEletronico[29] != '\0') && (elemento->endEletronico[0] == '\0'));

    do
    {
        elemento->num[13]='\0';
        printf("Digite o telefone: ");
        scanf("%[^\n]s", &elemento->num);
        getchar();
    }
    while(elemento->num[13]!='\0');

    p = lista->primeiro;

    if(lista->primeiro == NULL){
        elemento->proximo = NULL;
        lista->primeiro = elemento;
    }
    else{ /*  Ordena agenda - foi usado funcoes da biblioteca de string */
        while(p != NULL && strcmp(p->nome, elemento->nome) < 0){
            ant = p;
            p = p->proximo;
        }
        elemento->proximo = p;

        if(ant == NULL)
            lista->primeiro = elemento;
        else
            ant->proximo = elemento;
    }
/*------------------------------------------------------------------------------------------------------*/
    printf("%s\n",elemento->nome);
    printf("%s\n",elemento->endEletronico);
    printf("%s\n",elemento->num);
    getchar();
}/*Fim da funcao insere*/

void imprimeAgenda( t_lista* lista)
{
    t_elemento* elemento = lista->primeiro;

    if(elemento == NULL) /*Ve se a agenda nao esta vazia*/
    {
        printf("@@@@Agenda Vazia!!!@@@\n");
        getchar();
        return;
    }

    for(elemento = lista->primeiro; elemento != NULL; elemento = elemento->proximo) /*Imprime informacoes dos contatos na agenda.*/
    {
        printf("%s\n",elemento->nome);
        printf("%s\n",elemento->endEletronico);
        printf("%s\n",elemento->num);
        printf("\n\n");
    }

    printf("\n");

    getchar();
}

/*----------------------------------------------------------------------------------------------------------*/


/*Busca contatos na agenda, tanto para editar e excluir*/
void buscaContato( t_lista* lista)
{
    t_elemento* elemento;
    t_elemento* elementoAux = lista->primeiro;
    char nome[30];
    int menu;

    if(elemento == NULL) /*Se nao tiver elemento na lista ele retorna informacao para usuario*/
    {
        printf("@@@@Agenda Vazia!!!@@@@\n");
        getchar();
        return;
    }

    printf("Digite o nome do contato(Nao precisa de sobrenome)\n"); /*Busca contatos*/
    scanf("%[^\n]s",&nome);
    getchar();

    for(elemento = lista->primeiro; elemento != NULL; elemento = elemento->proximo) /*Percorre todos os elementos ate encontrar o que om usuario deseja*/
    {
        if(strncmp(elemento->nome, nome,strlen(nome)) == 0)/*compara*/
        {
            printf("%s\n",elemento->nome);
            printf("%s\n",elemento->endEletronico);
            printf("%s\n",elemento->num);
            printf("1. Editar\n");
            printf("2. Deletar\n");
            printf("3. Procurar proximo contato com o mesmo nome inicial\n");
            printf("0. Sair\n");
            scanf("%d",&menu);
            getchar();

            switch(menu)
            {
            case 1: /*Edita*/
                do
                {
                    elemento->nome[29]='\0';
                    elemento->nome[0]='\0';
                    printf("Digite o nome: ");
                    scanf("%[^\n]s", &elemento->nome);
                    getchar();
                }
                while((elemento->nome[29] != '\0') && (elemento->nome[0] == '\0'));

                do
                {
                    elemento->endEletronico[29]='\0';
                    elemento->endEletronico[0]='\0';
                    printf("Digite o endereco: ");
                    scanf("%[^\n]s", &elemento->endEletronico);
                    getchar();
                }
                while((elemento->endEletronico[29] != '\0') && (elemento->endEletronico[0] == '\0'));

                do
                {
                    elemento->num[13]='\0'; 
                    printf("Digite o telefone: ");
                    scanf("%[^\n]s", &elemento->num);
                    getchar();
                }
                while(elemento->num[13]!='\0');

                printf("Editado!");
                getchar();
                return;
            case 2: /*Deleta todas as informacoes de um contato na agenda*/
                if(elemento == elementoAux)
                {
                    lista->primeiro = elemento->proximo;
                    free(elemento);
                    printf("Contato apagado");
                    getchar();
                    return;
                }
                else
                {
                    elementoAux->proximo = elemento->proximo;
                    free(elemento);
                    printf("Contato apagado");
                    getchar();
                    return;
                }
            case 3:/*Procura o proximo nome igual, se tiver*/
                break;
            case 0:/*Sai da edicao*/
                return;
            default:
                printf("@@@@@Digite uma opcao valida!!@@@@@@");
                getchar();
            }
        }
        elementoAux=elemento;
    }

    printf("@@@ Contato Nao Existe@@@");
    getchar();
    return ;
} 

/*----------------------------------------------Fim de busca------------------------------------------------------------*/

int main()
{
    int menu;
    t_lista* lista  =  (t_lista *)  malloc(sizeof(t_lista));
    lista->primeiro = NULL;


    do
    {
        system("cls || clear");

        printf("Agenda-Lista de Contatos\n");
        printf("1. Inserir na lista\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar contato(Editar/Deletar)\n");
        printf("0. Sair\n");

        scanf("%d", &menu);
        getchar();

        switch(menu)
        {
        case 1:
            system("cls || clear");
            InsereContato(lista);
            break;

        case 2:
            system("cls || clear");
            imprimeAgenda(lista);
            break;

        case 3:
            system("cls || clear");
            buscaContato(lista);
            break;

        case 0:
            liberaAgenda(lista);
            return 0;

        default:
            printf("@@@@@Digite uma opcao valida!!@@@@@@");
            getchar();
        }
    }
    while(0==0);
}
