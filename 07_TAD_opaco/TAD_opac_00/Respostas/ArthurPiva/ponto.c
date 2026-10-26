#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    float x;
    float y;
};

tPonto Pto_Cria (float x, float y){
    tPonto ponto = malloc(sizeof(struct ponto));

    if(ponto == NULL){
        printf("NULL");
        return NULL;
    }

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

void Pto_Apaga (tPonto p){
    free(p);
}

float Pto_Acessa_x (tPonto p){
    return p->x;
}

float Pto_Acessa_y (tPonto p){
    return p->y;
}

void Pto_Atribui_x (tPonto p, float x){
    p->x = x;
}

void Pto_Atribui_y (tPonto p, float y){
    p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2){
    float dx = (p1->x - p2->x) * (p1->x - p2->x);
    float dy = (p1->y - p2->y) * (p1->y - p2->y);

    float distancia = sqrtf(dx + dy);

    return distancia;
}




