#include <stdio.h>
#include "utils.h"

int *CriaVetor(int tamanho){
    int *vetor = malloc(tamanho * sizeof(int));

    if(vetor == NULL){
        printf("Erro na criação do vetor\n");
    }

    return vetor;
}

void LeVetor(int *vetor, int tamanho){
    for(int i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float sum=0;
    
    for(int i=0; i<tamanho; i++){
        sum += vetor[i];
    }

    return sum/tamanho;
}

void LiberaVetor(int *vetor){
    free(vetor);
}