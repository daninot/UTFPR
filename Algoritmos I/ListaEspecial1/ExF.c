#include <stdio.h>

int main (void)
{
    int C, D, valor_km, valor_ped, qtd_ped, ValorTotalPed, ValorTotalKm, Custo;

    scanf("%d %d",&C,&D);
    scanf("%d %d",&valor_km,&valor_ped);

    qtd_ped = C / D;
    ValorTotalPed = qtd_ped * valor_ped;
    ValorTotalKm = C * valor_km;
    Custo = ValorTotalKm + ValorTotalPed;

    printf("%d\n",Custo);

    return 0;
}
