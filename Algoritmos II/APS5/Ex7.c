#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Soma_Trivial(int *vet, int N)
{
    int i, soma=0;

    for(i=0; i<N; i++)
        soma = soma + vet[i];

    return soma;
}

int soma_recursiva(int *vet, int e, int d)
{
    int soma1,soma2, m;

    if((d - e) == 0)       //isso significa que fim == inicio (1 elemento)
        return(vet[d]);
    else if((d - e) == 1)       //isso significa que o fim do vetor está do lado do início (2 elementos)
        return(vet[d] + vet[e]);
    else
    {
        m = (e+d)/2;
        soma1 = soma_recursiva(vet,e,m);
        soma2 = soma_recursiva(vet,m+1,d);
        return(soma1+soma2);
    }
}

void GeraVet(int tam, int *vet)
{
    int i;
    for(i=0; i<tam; i++)
        vet[i] = i+1;
}

int main (void)
{
    int num, somatri, somadividida;
    clock_t rec;
    clock_t tri;

    printf("Que numero deseja somar? ");
    scanf(" %d",&num);
    int vet[num];
    GeraVet(num,vet);

    rec = clock();
    somatri = Soma_Trivial(vet,num);
    rec = clock() - rec;
    printf("A soma trivial = %d levou %f segundos.\n",somatri,((float)rec)/CLOCKS_PER_SEC);

    tri = clock();
    somadividida = soma_recursiva(vet,0,num-1);
    tri = clock() - tri;
    printf("A soma recursiva = %d levou %f segundos.\n",somadividida,((float)tri)/CLOCKS_PER_SEC);
    
    return 0;
}
