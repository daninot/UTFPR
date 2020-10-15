#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void strinv(char *string, int tam)
{
    int i;

    for(i=tam; i>=0; i--)
        printf("%c",string[i]);
    printf("\n");
}

int main(void)
{
    char string[MAX];
    int tam;

    scanf("%s",string);
    tam = strlen(string);
    strinv(string,tam);

    return 0;
}
