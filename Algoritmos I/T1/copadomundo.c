#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int T, N, i, ptsdisputados, pontos, somapts, empates;
    char name[11];

    while(scanf("%d %d",&T,&N) == 2 && T != 0)
    {
        ptsdisputados = 3*N;
        somapts=0;
        for(i=0; i<T; i++)
        {
            scanf("%s" "%d",name,&pontos);
            somapts = somapts + pontos;
        }
        empates = ptsdisputados - somapts;
        printf("%d\n",empates);
    }
    return 0;
}
