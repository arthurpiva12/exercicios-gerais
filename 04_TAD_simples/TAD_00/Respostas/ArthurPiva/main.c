#include "ponto.h"
#include <stdio.h>

int main(){
    Ponto p1, p2;
    float a, b, x, y;
    scanf("%f %f %f %f", &a, &b, &x, &y);

    p1 = pto_cria(a, b);
    p2 = pto_cria(x, y);

    float distancia;
    distancia = pto_distancia (p1, p2);

    printf("%g", distancia);

    return 0;
}