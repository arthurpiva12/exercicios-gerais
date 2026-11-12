#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

struct Vector{
    DataType* dados;
    int tamanho;
};

Vector *VectorConstruct(){
    Vector* vetor = malloc (sizeof(Vector));

    if(vetor == NULL){
        return NULL;
    }

    //inicializando as variaveis
    vetor->dados = NULL;
    vetor->tamanho = 0;

    return vetor;
}

void VectorPushBack(Vector *v, DataType val){
    v->dados = realloc(v->dados, sizeof(DataType) * (v->tamanho+1));
    v->dados[v->tamanho] = val;
    v->tamanho++;
}

DataType VectorGet(Vector *v, int i){
    return v->dados[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i=0; i<v->tamanho; i++){
        destroy(v->dados[i]);
    }

    free(v->dados);
    free(v);
}