#include <stdio.h>

int soma(int n)
{
    if(n == 1)
        return 1;
    else if(n == 0)
        return 0;
    else
    {
        return (n + soma(n-1));
    }
}

int main(void)
{
    int num, sum;
    printf("Deseja saber a soma de qual numero? ");
    scanf("%d",&num);
    sum = soma(num);
    printf("A soma eh: %d\n",sum);

    return 0;
}
