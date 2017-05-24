#include<stdio.h>
#include<stdlib.h>
 
typedef struct Agenda{
    char x[30];
    char y[30];
    int z[10];
    struct agenda *proximo;
}data_agenda;
 
int main(int argc, char *arqv[]){
    data_agenda *ini_agenda;
    data_agenda *proximo_agenda;
    int resp;
 
    ini_agenda = (data_agenda *)malloc(sizeof(data_agenda));
    if(ini_agenda == NULL)
        exit(1);
    proximo_agenda = ini_agenda;
    while(1)
    {
 
            printf("Digite o nome: ");
            scanf("%[^\n]s", &proximo_agenda->x);
            getchar();
 
            printf("Digite o endereco: ");
            scanf("%[^\n]s", &proximo_agenda->y);
           	
 
            printf("Digite o telefone: ");
            scanf("%s", &proximo_agenda->z);
 
            printf("Deseja continua? <1> <outro valor> NAO: ");
            scanf("%d", &resp);
 
            if(resp == 1)
            {
                proximo_agenda->proximo = (data_agenda *)malloc(sizeof(data_agenda));
                proximo_agenda = proximo_agenda->proximo;
            }
            else
                break;
 
    }
            printf("\n");
            proximo_agenda->proximo = NULL;
            proximo_agenda = ini_agenda;
            while(proximo_agenda != NULL)
            {
                    printf("nome: %s, endereco: %s, telefone: %s", proximo_agenda->x, proximo_agenda->y, proximo_agenda->z);
                    proximo_agenda = proximo_agenda->proximo;
            }
 
 return 0;
}
 
 
