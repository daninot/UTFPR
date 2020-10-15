#include <stdio.h>

int main(void)
{
    int R1, R2, R3, R4, qtd;

    scanf("%d %d %d %d",&R1,&R2,&R3,&R4);

    qtd = (R1 + R2 + R3 + R4) - 3;
    printf("%d\n",qtd);

    return 0;
}
