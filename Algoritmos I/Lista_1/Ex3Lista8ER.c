/* 3) Alice e Beto são amigos e sempre que se encontram relembram os tempos de infância tirando par-ou-ímpar para
decidir quem escolhe o filme a ser assistido, ou qual o restaurante em que vão almoçar, etc.
Escreva um programa para determinar quem ganhou a série de par-ou-ímpar. */

#include <stdio.h>

int main (void)
{
    int qtd_partidas;
    int i, resultado;
    int beto=0, alice=0;


    printf("Informe a quantidade de partidas: ");
    scanf("%d",&qtd_partidas);

    for( i=1; i<=qtd_partidas; i++)
    {
        do
        {
            printf("%do. resultado de %d jogadas: ",i,qtd_partidas);
            scanf("%d",&resultado);

        }while(resultado != 0 && resultado != 1);

        if(resultado == 0)
        {
            alice++;
        }
        else
        {
            beto++;
        }
    }
    printf("\nAlice ganhou %d partidas e Beto ganhou %d partidas\n",alice,beto);

}


