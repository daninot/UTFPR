#include <stdio.h>

int main(void)
{
    double A, B, C, triangulo, circulo, trapezio, quadrado, retangulo;
    scanf("%lf %lf %lf",&A,&B,&C);

    triangulo = (A * C)/2;
    printf("TRIANGULO: %.3lf\n",triangulo);

    circulo = 3.14159 * C * C;
    printf("CIRCULO: %.3lf\n",circulo);

    trapezio = ((A + B) * C)/2;
    printf("TRAPEZIO: %.3lf\n",trapezio);

    quadrado = B * B;
    printf("QUADRADO: %.3lf\n",quadrado);

    retangulo = A * B;
    printf("RETANGULO: %.3lf\n",retangulo);

    return 0;
}
