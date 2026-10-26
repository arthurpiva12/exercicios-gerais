#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
#include "ponto.h"

struct circulo{
    tPonto centro;
    float r;
};

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo circulo = malloc(sizeof(struct circulo));

    if(circulo == NULL){
        return NULL;
    }

    circulo->centro = Pto_Cria(x, y);
    circulo->r = r;

    return circulo;
}

void Circulo_Apaga (tCirculo c){
    Pto_Apaga(c->centro);
    
    free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c){
    return c->r;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    c->r = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    float distancia = Pto_Distancia(c->centro, p);

    if(distancia <= c->r){
        return 1;
    }

    return 0;
}
