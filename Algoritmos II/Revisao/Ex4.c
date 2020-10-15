#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int encontreosete(char resposta)
{
    srand((unsigned)time(NULL));

    int A[4][4], i, j, k, qtd, B[16][2];

    if(resposta == 'S')
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
    }
    else
    {
        for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				A[i][j] = (rand()%3) + 7;
			}
		}
    }

    for(i=0;i<16;i++)
	{
		for(j=0;j<2;j++)
		{
			B[i][j] = 0;
		}
	}

    /*printf("A:\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }*/
    qtd=0;
    k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(A[i][j] == 7)
            {
                qtd++;
                B[k][0] = i;
                B[k][1] = j;
                k++;
            }
        }
    }

    /*printf("qtd = %d\n",qtd);
    printf("B:\n");
    for(i=0; i<16; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }*/
    
    return qtd;
}

int main (void)
{
    int setes;
    char resposta;

    printf("Deseja criar a matriz? (Entre com 'S' para sim e 'N' para nao): ");
    scanf(" %c",&resposta);
    setes = encontreosete(resposta);
    printf("Foram gerados %d 7's.\n",setes);

    return 0;
}
