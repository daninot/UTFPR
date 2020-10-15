#include <stdio.h>

int main (void)
{
    int Comp, MT, Finish;

    scanf("%d %d",&MT,&Comp);

    Finish = (MT % Comp);

    printf("%d\n",Finish);

    return 0;
}
