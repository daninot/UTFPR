#include <stdio.h>
#include <stdlib.h>

typedef struct corpo
{
    //char nome[11];
    float altura;
    float peso;
}corpo;

typedef struct casal
{
    corpo pessoa1, pessoa2;
}casal;

int main (void)
{
    corpo Joao;

    Joao.altura = 1.68;
    printf("A altura de Joao eh: %.2f\n",Joao.altura);

    casal C[10];
    //C[0].pessoa1.nome = 'Maria';
    C[0].pessoa1.altura = 1.63;
    C[0].pessoa1.peso = 59.5;
    //C[0].pessoa2.nome = 'Jose';
    C[0].pessoa2.altura = 1.78;
    C[0].pessoa2.peso = 82.6;

    printf("Casal 1:\n");
    printf("Maria\nAltura: %.2f\nPeso: %.2f\n",C[0].pessoa1.altura,C[0].pessoa1.peso);
    printf("Jose\nAltura: %.2f\nPeso: %.2f\n",C[0].pessoa2.altura,C[0].pessoa2.peso);

    return 0;
}
