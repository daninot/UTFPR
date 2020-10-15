#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct itens
{
    int lucro, peso;
    float X;                //X = lucro/peso
}itens;

void inicializa_com_valores(itens *s)
{
    s[0].lucro = 14;
    s[0].peso = 3;
    s[0].X = ((float)s[0].lucro / s[0].peso);
    s[1].lucro = 5;
    s[1].peso = 1;
    s[1].X = ((float)s[1].lucro / s[1].peso);
    s[2].lucro = 10;
    s[2].peso = 6;
    s[2].X = ((float)s[2].lucro / s[2].peso);
    s[3].lucro = 12;
    s[3].peso = 4;
    s[3].X = ((float)s[3].lucro / s[3].peso);
    s[4].lucro = 8;
    s[4].peso = 2;
    s[4].X = ((float)s[4].lucro / s[4].peso);
    s[5].lucro = 10;
    s[5].peso = 4;
    s[5].X = ((float)s[5].lucro / s[5].peso);
    s[6].lucro = 16;
    s[6].peso = 8;
    s[6].X = ((float)s[6].lucro / s[6].peso);
    s[7].lucro = 9;
    s[7].peso = 9;
    s[7].X = ((float)s[7].lucro / s[7].peso);
}

void troca(itens *a,itens *b)
{
    itens aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void SelectionSort(itens *v, int tam)
{
    int i, j, min;

    for(i=0; i<(tam-1); i++)
    {
        min = i;
        for(j=(i+1); j<tam; j++)
        {
            if(v[j].X < v[min].X)
                min = j;
        }
        troca(&v[i],&v[min]);
    }
}

void imprime(itens *s, int tam)
{
    int i;
    for(i=0;i<tam;i++)
        printf("i=%d\tLucro: %d\tPeso: %d\tX: %.2f\n",i,s[i].lucro,s[i].peso,s[i].X);
}

int main()
{
    int W=15, maior, tam=8;
    itens S[tam];
    float porcentagem, soma_lucro=0, soma_peso=0;

    inicializa_com_valores(S);
    SelectionSort(S,tam);
    //imprime(S,tam);

    maior = tam-1;
    while(soma_peso < W)
    {
        if((soma_peso + S[maior].peso) >= W)
        {
            porcentagem = (W - soma_peso)/W;            //qual a porcentagem que falta para encher a mochila?
            soma_peso = ceil(soma_peso + (float)(S[maior].peso * porcentagem));   //arredonda para cima e sai do while
            soma_lucro = soma_lucro + (float)(S[maior].lucro * porcentagem);      //utiliza a mesma porcentagem no lucro
        }
        else
        {
            soma_peso = soma_peso + S[maior].peso;
            soma_lucro = soma_lucro + S[maior].lucro;
            maior--;
        }
    }
    printf("O lucro total eh de R$ %.2f \n",soma_lucro);

    return 0;
}
