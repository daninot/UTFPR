#include <stdio.h>

int main (void)
{
    int N, i, alice=0, beto=0, resultados=0;

    scanf("%d",&N);

    do
    {
        for(i=0; i<N; i++)
        {
            scanf("%d",&resultados);

            if(resultados == 0)
            {
                alice++;
            }
            else
            {
                beto++;
            }
        }

    printf("Alice ganhou %d e Beto ganhou %d\n",alice,beto);

    alice=0;
    beto=0;

    scanf("%d",&N);

    }while(N != 0);

    return 0;
}
