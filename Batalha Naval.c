#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ZerarMatriz(int P1[6][7],int P2[6][7])
{
    int i,j;

    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            P1[i][j]=0;
            P2[i][j]=0;

        }
    }
}

void GerarBarco(int matriz[6][7])
{
    int navio=1,sub=3,i,j;

    while((navio!=0)||(sub!=0))
    {
        i=rand()%6;
        j=rand()%4;

        if((navio>0))/*Gerar o encouraçado*/
        {
            navio=navio-1;
            matriz[i][j]=4;
            matriz[i][j+1]=4;
            matriz[i][j+2]=4;
            matriz[i][j+3]=4;
        }

        i=rand()%6;
        j=rand()%6;

        if((sub>0)&&((matriz[i][j]<=0)&&(matriz[i][j+1]<=0))) /* Verifica se a posição esta livre e a próxima- E Gera Submarino*/
        {
            sub=sub-1;
            matriz[i][j]=2;
            matriz[i][j+1]=2;
        }
    }
}

int Tiro(int matriz[6][7], int P1[6][7],int P2[6][7])
{
    int i,j;
    P1=0;
    P2=0;
    
    printf("\nDigite a linha que deseja atirar: ");
    scanf("%d", &i);
    printf("\nDigite a coluna que deseja atirar: ");
    scanf("%d", &j);

    for(P1=0;P1<10;P1++){
    }    
    for(P2=0;P2<10;P2++){
    }
    
            while (((P1) && (P2) >=10)){
    
    if (matriz[i][j] !=0)
    {
        if (matriz[i][j] =4)
        {
            printf("Voce acertou parte de um navio");
            scanf(%d, P1)
        }
        if(matriz[i][j] =2)
        {
            printf("Voce acertou parte de um submarino");
            
        }
    }
    else
    {
        printf("Voce acertou agua");
       

    }

    }
}


void Tela(int P1Tela[6][7],int P2Tela[6][7])
{
    int i,j;

    printf(" ____        _        _ _             _   _                  _\n| __ )  __ _| |_ __ _| | |__   __ _  | \\ | | __ ___   ____ _| |\n|  _ \\ / _` | __/ _` | | '_ \\ / _` | |  \\| |/ _` \\ \\ / / _` | |\n| |_) | (_| | |_ (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |\n|____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| |_| \\_|\\__,_| \\_/ \\__,_|_|\n");
    printf("\n\t     JOGADOR 1\t\t     JOGADOR 2\n\t   ");

    for(j=0; j<7; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }

    printf("\t   ");

    for(j=0; j<7; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }

    printf("\n");/*NOME BATALHA NAVAL GIGANTE \/*/
    printf("\t O---------------O\t O---------------O\n");/*@@@@SÓ PARTE GRÁFICA!@@@@*/

    for(i=0; i<6; i++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("\t |\t\t |\t |\t\t |\n");
        printf("\t%d| ",i+1);

        for(j=0; j<7; j++)
        {
            printf("%d ",P1Tela[i][j]);
        }

        printf("|\t%d| ",i+1);

        for(j=0; j<7; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
        {
            printf("%d ",P2Tela[i][j]);
        }

        printf("|");

        if(i==0){
            printf("      INDICE");
        }
        if(i==1){
            printf("  0=Nao Descorberto");
        }
        if(i==2){
            printf("  2=Submarino");
        }
        if(i==3){
            printf("  4=Encouracado");
        }
        if(i==4){
            printf("  X=Agua");
        }

        printf("\n");
    }
    printf("\t |\t\t |\t |\t\t |\n");
    printf("\t O---------------O\t O---------------O");
    printf("\n");
}

int main()
{
    int P1[6][7],P2[6][7],P1Tela[6][7],P2Tela[6][7];
    int i,j;
    srand(time(NULL));

    ZerarMatriz(P1,P2);
    ZerarMatriz(P1Tela,P2Tela);
    GerarBarco(P1);
    GerarBarco(P2);
    Tela(P1Tela,P2Tela);
    Tiro(P1,P2);


    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            printf("%d ",P1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            printf("%d ",P2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
