#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int *a,long int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int divide(long int *vet, int esquerda, int direita)
{
    int i = esquerda, j;

    for(j=esquerda + 1; j<=direita; j++)
    {
        if(vet[j] < vet[esquerda]) //se o valor do vetor no �ndice j for menor que o valor do vetor no �ndice 'esquerda'
        {
            ++i; //primeiro soma o valor e depois "coloca" no i
            swap(&vet[i],&vet[j]);
        }
    }
    swap(&vet[esquerda],&vet[i]);

    return i;
}
void QuickSort(long int *vet, int esquerda, int direita)
{
    int q;

    if(direita > esquerda)
    {
        q = divide(vet,esquerda,direita);
        QuickSort(vet,esquerda,q-1);
        QuickSort(vet,q+1,direita);
    }
}

int BB(long int *vet, int e, int d, long int x)
{
    if(e > d)
        return -1;

    int m = (e+d)/2;

    if(vet[m] == x)
        return m;
    if(vet[m] < x)
        return BB(vet,m+1,d,x);
    else
        return BB(vet,e,m-1,x);
}
int buscab(long int x, long int *v, int tam)
{
    return BB(v,0,tam-1,x);
}

int main (void)
{
    int N, i;

    scanf("%d",&N);
    long int numeros[N], teste;

    for(i=0; i<N; i++)
        scanf("%li",&numeros[i]);

    QuickSort(numeros,0,N-1);
    while(scanf("%li",&teste) == 1 && N != EOF)
    {
        i = buscab(teste,numeros,N);
        if(numeros[i] == teste)
            printf("sim\n");
        else
            printf("nao\n");
    }
    return 0;
}
