#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ZerarMatriz(int P1[6][8],int P2[6][8])
{
    int i,j;

    for(i=0; i<6; i++)
    {
        for(j=0; j<8; j++)
        {
            P1[i][j]=0;
            P2[i][j]=0;

        }
    }
}

void GerarBarco(int matriz[6][8])
{
    int navio=1,sub=3,i,j;

    while((navio!=0)||(sub!=0))
    {
        i=rand()%6;
        j=rand()%5;

        if((navio>0))/*Gerar o encouraçado*/
        {
            navio=navio-1;
            matriz[i][j]=4;
            matriz[i][j+1]=4;
            matriz[i][j+2]=4;
            matriz[i][j+3]=4;
        }

        i=rand()%6;
        j=rand()%7;

        if((sub>0)&&((matriz[i][j]<=0)&&(matriz[i][j+1]<=0))) /* Verifica se a posição esta livre e a próxima- E Gera Submarino*/
        {
            sub=sub-1;
            matriz[i][j]=2;
            matriz[i][j+1]=2;
        }
    }
}

int Tiro(int matriz[6][8],int Tela[6][8],int *Ponto)
{
    int i,j;

    printf("\n    Digite a linha que deseja atirar:");
    scanf("%d", &i);
    i=i-1;

    printf("    Digite a coluna que deseja atirar:");
    scanf("%d", &j);
    j=j-1;
    getchar();

    if (matriz[i][j] !=0)
    {
        if (matriz[i][j] ==4)
        {
            printf("\tVoce acertou parte de um encouracado!\n");
            printf("\t       aperte enter para continuar");
            getchar();
            *Ponto=*Ponto+1;
            Tela[i][j]=4;
            return 4;
        }
        else
        {
            printf("\tVoce acertou parte de um submarino\n");
            printf("\t      aperte enter para continuar");
            getchar();
            *Ponto=*Ponto+1;
            Tela[i][j]=2;
            return 2;
        }
    }
    else
    {
        printf("\t      Voce acertou agua\n");
        printf("\taperte enter para continuar");
        getchar();
        Tela[i][j]=3;
        return 0;

    }
}


void Tela(int P1Tela[6][8],int P2Tela[6][8],int P1Ponto,int P2Ponto)
{
    int i,j;
    printf("        JOGADOR 1         JOGADOR 2\n     ");
    printf("   PONTO = %d         PONTO = %d\n     ",P1Ponto,P2Ponto);

    for(j=0; j<8; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }

    printf("  ");

    for(j=0; j<8; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }

    printf("\n");
    printf("   O-----------------O-----------------O\n");/*@@@@SÓ PARTE GRÁFICA!@@@@*/

    for(i=0; i<6; i++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("   |\t\t     |\t\t       |\n");
        printf("  %d| ",i+1);

        for(j=0; j<8; j++)
        {
            if(P1Tela[i][j]==3)
            {
                printf("X ");
            }
            else
            {
                printf("%d ",P1Tela[i][j]);
            }
        }

        printf("| ",i+1);

        for(j=0; j<8; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
        {
            if(P2Tela[i][j]==3)
            {
                printf("X ");
            }
            else
            {
                printf("%d ",P2Tela[i][j]);
            }
        }

        printf("|%d",i+1);

        if(i==0)
        {
            printf("       INDICE");
        }
        if(i==1)
        {
            printf("   0=Nao Descorberto");
        }
        if(i==2)
        {
            printf("   2=Submarino");
        }
        if(i==3)
        {
            printf("   4=Encouracado");
        }
        if(i==4)
        {
            printf("   X=Agua");
        }
        if(i==5)
        {
            printf("   10 Pontos para ganhar");
        }
        printf("\n");
    }
    printf("   |\t\t     |\t\t       |\n");
    printf("   O-----------------O-----------------O");
    printf("\n     ");

    for(j=0; j<8; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }

    printf("  ");

    for(j=0; j<8; j++)/*@@@@SÓ PARTE GRÁFICA!@@@@*/
    {
        printf("%d ",j+1);
    }
    printf("\n");

}


int main()
{
    int P1[6][8],P2[6][8],P1Tela[6][8],P2Tela[6][8];
    int P1Ponto,P2Ponto;
    int i,j;
    char Jogar = 's';

    srand(time(NULL));

    printf(" ____        _        _ _             _   _                  _\n| __ )  __ _| |_ __ _| | |__   __ _  | \\ | | __ ___   ____ _| |\n| \\_ \\ / _` | __/ _` | | '_ \\ / _` | |  \\| |/ _` \\ \\ / / _` | |\n| |_) | (_| | |_ (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |\n|____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| |_| \\_|\\__,_| \\_/ \\__,_|_|\n");/*Nome batalha naval gigante*/
    printf("\t\tAperte enter para jogar...");
    getchar();
    system("clear||cls");

    while ((Jogar == 's')||(Jogar == 'S'))
    {
        P1Ponto=0;
        P2Ponto=0;

        ZerarMatriz(P1,P2);
        ZerarMatriz(P1Tela,P2Tela);
        GerarBarco(P1);
        GerarBarco(P2);

        while((P1Ponto!=10)&&(P2Ponto!=10))
        {
            system("clear||cls");

            for(i=0; i<6; i++)
            {
                for(j=0; j<8; j++)
                {
                    printf("%d ",P1[i][j]);
                }
                printf("\n");
            }

            printf("\n");

            for(i=0; i<6; i++)
            {
                for(j=0; j<8; j++)
                {
                    printf("%d ",P2[i][j]);
                }
                printf("\n");
            }

            Tela(P1Tela,P2Tela,P1Ponto,P2Ponto);/*jogada player 1*/
            printf("\t\t Jogador 1");/*jogada player 1*/
            Tiro(P2,P2Tela,&P1Ponto);/*jogada player 1*/

            system("clear||cls");

            if(P1Ponto!=10)/*jogada player 2,roda enquanto player 1 não ganhar*/
            {
                for(i=0; i<6; i++)
                {
                    for(j=0; j<8; j++)
                    {
                        printf("%d ",P1[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");

                for(i=0; i<6; i++)
                {
                    for(j=0; j<8; j++)
                    {
                        printf("%d ",P2[i][j]);
                    }
                    printf("\n");
                }

                Tela(P1Tela,P2Tela,P1Ponto,P2Ponto);/*jogada player 2*/
                printf("\t\t Jogador 2\n");/*jogada player 2*/
                Tiro(P1,P1Tela,&P2Ponto);/*jogada player 2*/
            }

        }
        system("clear || cls");
        if(P1Ponto == 10)
        {
            printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PLAYER 1 GANHOU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        }
        else
        {
            printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PLAYER 2 GANHOU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        }
        printf("\n\tQuer jogar de novo?(S/N)\n");
        scanf("%c",&Jogar);
    }

    return 0;
}
