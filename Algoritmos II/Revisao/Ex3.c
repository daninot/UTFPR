#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int replace(char *string, char atual, char novo)
{
    int i=0, substituiu=0;
    while(string[i] != '\0')
    {
        if(string[i] == atual)
        {
            string[i] = novo;
            substituiu++;
        }
        i++;
    }
    return substituiu;
}

int main(void)
{
    char string[MAX], novo, atual;
    int i, n;

    printf("Insira sua string: ");
    scanf(" %s",string);
    printf("Insira o caractere a ser substituido: ");
    scanf(" %c",&atual);
    printf("Insira o novo caractere: ");
    scanf(" %c",&novo);

    n = replace(string,atual,novo);
    printf("Ocorreram %d substituicoes.\n",n);

    return 0;
}
