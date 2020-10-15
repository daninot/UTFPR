#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int N, M, i, j, T=0, l, k, ordenadas, abscissas, altura, l_inicio, l_fim, quadradinho, c_inicio, c_fim;
    scanf("%d %d",&N,&M);
    char terreno[N][M];
    int y[N*M], x[N*M];

    l=0;
    for(i=0; i<N; i++)                          //leio a matriz
    {
        for(j=0; j<M; j++)
        {
            scanf(" %c",&terreno[i][j]);
            if(terreno[i][j] == 't')
            {
                T++;
                y[l] = i;                       //gravo as posições das torres
                x[l] = j;
                l++;
            }
        }
    }

    int torres[T];                              //leio as alturas das torres
    for(i=0; i<T; i++)
        scanf("%d",&torres[i]);

    quadradinho=0;
    for(k=0; k<T; k++)
    {
        ordenadas = y[k];
        abscissas = x[k];
        altura = torres[k];

        l_inicio = ordenadas - altura;
        c_inicio = abscissas - altura;
        if(l_inicio < 0)
            l_inicio = 0;
        if(c_inicio < 0)
            c_inicio = 0;
        l_fim = ordenadas + altura;
        c_fim = abscissas + altura;
        if(l_fim >= N)
            l_fim = N-1;
        if(c_fim >= M)
            c_fim = M-1;

        for(i=l_inicio; i<=l_fim; i++)
        {
            for(j=c_inicio; j<=c_fim; j++)
            {
                if(terreno[i][j] == '#')
                {
                    terreno[i][j] = '.';
                    quadradinho++;
                }
            }
        }
    }
    printf("%d\n",quadradinho);
    for(i=0; i<N; i++)                          //imprimo a matriz
    {
        for(j=0; j<M; j++)
        {
            printf("%c",terreno[i][j]);
        }
        printf("\n");
    }
    return 0;
}
