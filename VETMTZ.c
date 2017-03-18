#include<stdio.h>

int main (){

int i, j;
int mtz [3][4];
int vet [10];


for(i=0;i<10;i++){
    printf("Digite os valores: ");
    scanf("%d", &vet[i]);
}
for(i=0;i<10;i++){
    printf("%d\n", vet[i]);
}
printf("\n\n");

/* MATRIZ */
for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("Digite os valores de linha %d e coluna %d: ", i+1, j+1);
            scanf("%d", &mtz[i][j]);
        }

}

for(i=0;i<3;i++){
        for(j=0;j<4;j++){
                printf("%d ", mtz[i][j]);

    }
printf("\n");
}



return 0;
}
