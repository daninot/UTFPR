#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define ID 100001

int main (void)
{
    int N, M, i, filafinal[ID];

    //leitura da fila inicial
    scanf("%d",&N);
    int fila[N];
    for(i=0; i<N; i++)
        scanf("%d",&fila[i]);

    //leitura da fila dos que saíram
    scanf("%d",&M);
    int sairam[M];

    //inicializo a minha lista final marcando como se todas as pessoas com todas as IDs possíveis estivessem na fila
    for(i=0; i<ID; i++)
        filafinal[i] = 1;

    //leio as IDs de quem saio e nos respectivos índices da minha filafinal, marco um 0 para as IDs das pessoas que saíram
    for(i=0; i<M; i++)
    {
        scanf("%d",&sairam[i]);
        filafinal[sairam[i]] = 0;
    }

    //imprimo os valores das pessoas que ficaram na fila (e que já estavam na fila inicial) a partir da marcação que elas já tinham
    for(i=0;i<N;i++)
    {
        if(filafinal[fila[i]] == 1)
            printf("%d ",fila[i]);
    }
    printf("\n");

    return 0;
}
