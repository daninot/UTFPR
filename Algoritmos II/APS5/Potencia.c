#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Potencia(int x, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    return( )
}

2^3 = 2 * 2 * 2
void GeraVetorAleatorio(int *vet, int tam, int limInf, int limSup)
{
    srand(time(NULL));
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = (rand() % (limSup - limInf) + limInf);
    }
}

void ImprimeVet(int *vet, int tam)
{
    int i;

    for(i=0; i<tam; i++)
        printf("%d ",vet[i]);
    printf("\n");
}

int main(void)
{
    int tam=10, maiorElemento;
    int vet[tam];
    GeraVetorAleatorio(vet,tam,0,100);
    printf("Vetor gerado:\n");
    ImprimeVet(vet,tam);
    maiorElemento = MaiorElem(tam,vet);
    printf("%d eh o maior elemento do vetor.\n",maiorElemento);

    return 0;
}
