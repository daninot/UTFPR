#include <stdio.h>

int Fat(int x)
{
    if(x == 0)
        return 1;

    return (x * Fat(x-1));
}

int main(void)
{
    int numero, fat;
    printf("Deseja saber o fatorial de que numero? ");
    scanf("%d",&numero);
    fat = Fat(numero);
    printf("O fatorial de %d eh: %d\n",numero,fat);
    return 0;
}
