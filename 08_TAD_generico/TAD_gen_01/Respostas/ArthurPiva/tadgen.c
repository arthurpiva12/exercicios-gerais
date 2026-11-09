#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{
    Type tipo;
    int qtd;
    void* numero;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* generico = malloc(sizeof(tGeneric));

    if(generico == NULL){
        return NULL;
    }

    //definindo as variaveis
    generico->tipo = type;
    generico->qtd = numElem;

    if(type == INT){
        generico->numero = malloc(numElem * sizeof(int));
    }
    else{
        generico->numero = malloc(numElem * sizeof(float));
    }

    if(generico->numero == NULL){
        free(generico);
        return NULL;
    }

    return generico;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->numero);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    for(int i=0; i<gen->qtd; i++){
        if(gen->tipo == INT){
            scanf("%d", &((int*)gen->numero)[i]);
        }
        else{
            scanf("%f", &((float*)gen->numero)[i]);
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");

    for(int i=0; i<gen->qtd; i++){
        if(gen->tipo == INT){
            printf("%d ", ((int*)gen->numero)[i]);
        }
        else{
            printf("%.2f ", ((float*)gen->numero)[i]);
        }
    }

    printf("\n");

}