#include <stdio.h>

int main (void)
{
    int n, teste, i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&teste);
        if(teste % 2 == 0)
            printf("Jedi\n");
        else
            printf("Sith\n");
    }
    return 0;
}
