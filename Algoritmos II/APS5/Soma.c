#include <stdio.h>
#include <stdlib.h>

int soma(int n, int sum)
{
    if(n == 0)
        return sum;
    else
    {
        sum = sum + n;
        return soma(n-1,sum);
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
