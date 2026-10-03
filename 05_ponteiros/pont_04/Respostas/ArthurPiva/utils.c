#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho){
    int i=0;
    for(; i<tamanho; i++){
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    //ENCONTRA O MENOR
    int i=0, minimo=10000;

    for(i=0; i<tamanho; i++){
        if(array[i] < minimo){
            minimo = array[i];
        }
    }
    *menor = minimo;

    //ENCONTRA O MAIOR
    int j=0, maximo=-10000;

    for(j=0; j<tamanho; j++){
        if(array[j] > maximo){
            maximo = array[j];
        }
    }
    *maior = maximo;

    //ENCONTRA A MEDIA
    int k=0;
    float soma=0;

    for(k=0; k<tamanho; k++){
        soma = array[k] + soma;
    }

    *media = soma/tamanho;
}