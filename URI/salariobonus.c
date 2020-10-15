#include <stdio.h>

int main(void)
{
    char nome;
    double salario, vendas, salariototal;

    scanf(" %s",&nome);
    scanf("%lf",&salario);
    scanf("%lf",&vendas);

    salariototal = salario + (0.15 * vendas);
    printf("TOTAL = R$ %.2lf\n",salariototal);

    return 0;
}
