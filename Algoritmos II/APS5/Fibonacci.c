#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função recursiva de fibonacci
long long Fibonacci_recursivo(int x)
{
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    return Fibonacci_recursivo(x-1) + Fibonacci_recursivo(x-2);
}

//função iterativa de fibonacci
long long Fibonacci_iterativo(int n)
{
    long long x[n], i;
    x[0] = 0;
    x[1] = 1;

    for(i=2;i<=n;i++)
        x[i] = x[i-1] + x[i-2];

    return x[n];
}

int main(void)
{
    int num;
    unsigned long long rec, ite;
    clock_t t;

    printf("Que numero? ");
    scanf("%d",&num);

    t = clock();
    ite = Fibonacci_iterativo(num);
    t = clock() - t;
    printf("Para o numero %d, Fibonacci iterativo == %llu levou %f segundos.\n",num,ite,((float)t)/CLOCKS_PER_SEC);

    t = clock();
    rec = Fibonacci_recursivo(num);
    t = clock() - t;
    printf("Para o numero %d, Fibonacci recursivo == %llu levou %f segundos.\n",num,rec,((float)t)/CLOCKS_PER_SEC);

    return 0;
}

/*
    num == 15
        Para o numero 15, Fibonacci iterativo == 610 levou 0.000003 segundos.
        Para o numero 15, Fibonacci recursivo == 610 levou 0.000029 segundos.
    num == 30
        Para o numero 30, Fibonacci iterativo == 832040 levou 0.000002 segundos.
        Para o numero 30, Fibonacci recursivo == 832040 levou 0.008746 segundos.
    num == 45
        Para o numero 45, Fibonacci iterativo == 1134903170 levou 0.000002 segundos.
        Para o numero 45, Fibonacci recursivo == 1134903170 levou 11.544104 segundos.
    num == 60
        Para o numero 60, Fibonacci iterativo == 1548008755920 levou 0.000003 segundos.
        *A versão recursiva leva mais de 1 hr.
*/
