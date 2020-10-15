#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int N, M, i, j=0, k, l, qtos, remover;

    //leitura da fila inicial
    scanf("%d",&N);
    int fila[N],  filafinal[N], aux[N];
    for(i=0; i<N; i++)
        scanf("%d",&fila[i]);

    //leitura da fila dos que saíram
    scanf("%d",&M);
    int sairam[M];
    for(i=0; i<M; i++)
    {
        scanf("%d",&sairam[i]);
    }
    qtos=(N-1);
    int ff[qtos];
    for(l=0; l<qtos; l++)
        ff[l] = 0;
    j=0;
    while(j <= M)
    {
        remover = sairam[j];
        i=0;
        k=0;
        while(fila[i] != remover)
        {
            ff[k] = fila[i];
            k++;
            i++;
        }
        if(fila[i] == remover)
        {
            ff[k] = fila[i+1];
            k++;
            i = i+2;
            j++;
            while(i < qtos)
            {
                ff[k] = fila[i];
                k++;
                i++;
            }
        }
        qtos=k;
        for(l=0; l<qtos; l++)
            fila[l] = ff[l];
        for(l=0; l<qtos; l++)
            ff[l] = 0;
    }
    /*while(removi < M)
    {
        jasaiu = sairam[j];
        i=0;
        if(saiudaqui > 0)
        {
            for(i=0; i<k; i++)
                aux[i] = filafinal[i];
            for(i=0; i<k; i++)
                filafinal[i] = aux[i];
            k=0;
        }
        while(i < N)
        {
            if(fila[i] == jasaiu)
            {
                j++;
                jasaiu = sairam[j];
                removi++;
            }
            else
            {
                filafinal[k] = fila[i];
                k++;
            }
            i++;
        }
        saiudaqui++;
    }*/

    for(i=0;i<qtos;i++)
        printf("%d ",fila[i]);
    printf("\n");

    return 0;
}
