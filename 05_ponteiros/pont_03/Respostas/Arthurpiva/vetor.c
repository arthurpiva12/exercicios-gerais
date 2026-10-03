#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int *vet, int tam){
    int i=0;

    for(; i<tam; i++){
        scanf("%d", &vet[i]);
    }
}

void OrdeneCrescente(int *vet, int tam){
    int i=0, j=0, aux;

    for(; i+1<tam; i++){
        int menor = 10000, p;

        for(j=i+1; j<tam; j++){
            if(vet[j] < vet[i]){
                if(vet[j] < menor){
                    menor = vet[j];
                    p = j;
                }
            }
        }

        if(menor == 10000){
            menor = vet[i];
            p = i;
        }

        aux = vet[i];
        vet[i] = menor;
        vet[p] = aux;
    }
}

void ImprimeDadosDoVetor(int *vet, int tam){
    int i=0;

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
}