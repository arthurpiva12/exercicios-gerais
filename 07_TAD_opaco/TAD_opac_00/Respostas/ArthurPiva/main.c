#include <stdlib.h>
#include <stdio.h>
#include "ponto.h" 
#include "circulo.h"

int main(){
    float x, y, r;
    scanf("%f %f %f", &x, &y, &r);
    tCirculo circulo = Circulo_Cria(x, y, r);

    float px, py;
    scanf("%f %f", &px, &py);
    tPonto ponto = Pto_Cria(px, py);

    if(Circulo_Interior(circulo, ponto)){
        printf("1");
    }
    else{
        printf("0");
    }

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}