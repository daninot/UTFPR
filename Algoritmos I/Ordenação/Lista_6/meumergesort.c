#include <stdio.h>
#include <stdlib.h>

void merge(int *vet, int tam)
{
    int metade, i, j, k, *w;

    w = (int*)malloc(tam*sizeof(int)); //malloc cria o vetor do tamanho tam
    metade = tam/2;
    i = 0;
    j = metade;
    k = 0;
    while(i < metade && j < tam)
    {
        if (vet[i] <= vet[j])
            w[k] = vet[i++];
        else
            w[k] = vet[j++];
        ++k;
    }
    if(i == metade)
    {
        while (j < tam)
            w[k++] = vet[j++];
    }
    else
    {
        while(i < metade)
            w[k++] = vet[i++];
    }
    for (i=0; i<tam;i++)
        vet[i] = w[i];

    free(w);
}
void MeuMergeSort(int *vet, int tam)
{
    int metade;
    if(tam > 1)
    {
        metade = (tam/2);
        MeuMergeSort(vet,metade);
        MeuMergeSort(vet + metade,tam - metade);
        merge(vet,tam);
    }
}

int main(void)
{
    int num[100000], i=0, j, cont=1;

    while(scanf("%d",&num[i]) == 1 && num[i] != EOF)
        i++;

    MeuMergeSort(num,i);

    for(j=0; j<i; j++)
    {
        if(cont == i)
            printf("%d\n",num[j]);
        else
            printf("%d ",num[j]);
        cont++;
    }

    return 0;
}
