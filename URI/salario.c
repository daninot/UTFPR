#include <stdio.h>

int main (void)
{
    int funcionario, qtdhrs;
    float salario, valorhr;

    scanf("%d",&funcionario);
    scanf("%d",&qtdhrs);
    scanf("%f",&valorhr);

    salario = (float)(qtdhrs * valorhr);
    printf("NUMBER = %d\nSALARY = U$ %.2f\n",funcionario,salario);
    return 0;
}
