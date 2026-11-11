#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

struct Vector{
    data_type* dados;
    int tamanho;
};

Vector *VectorConstruct(){
    Vector* vetor = malloc(sizeof(Vector));

    if(vetor == NULL){
        exit(1);
    }

    //inicializando as variaveis
    vetor->tamanho = 0;
    vetor->dados = NULL;

    return vetor;
}

void VectorPushBack(Vector *v, data_type val){
    v->dados = realloc(v->dados, sizeof(data_type) * (v->tamanho + 1));
    v->dados[v->tamanho] = val;
    v->tamanho++;
}

data_type VectorGet(Vector *v, int i){
    return v->dados[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i=0; i<v->tamanho; i++){
        destroy(v->dados[i]);
    }

    free(v->dados);
    free(v);
}

