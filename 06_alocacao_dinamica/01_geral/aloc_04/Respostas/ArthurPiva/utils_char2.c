#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

char *CriaVetorTamPadrao(){
    char *vetor = malloc((TAM_PADRAO + 1) * sizeof(char));
    int i = 0;

    if(vetor == NULL){
        printf("Vetor vazio\n");
        return NULL;
    }

    for(; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }

    vetor[i] = '\0';

    return vetor;
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo){
    int tamanhoNovo = tamanhoantigo + TAM_PADRAO;

    char *novo = realloc(vetor, (tamanhoNovo + 1) * sizeof(char));

    if(novo == NULL){
        printf("Vetor novo vazio\n");
        return NULL;
    }

    for(int i = tamanhoantigo; i < tamanhoNovo; i++){
        novo[i] = '_';
    }

    novo[tamanhoNovo] = '\0';

    return novo;
}

char *LeVetor(char *vetor, int *tamanho){
    int i = 0;
    char c;

    while(scanf("%c", &c) == 1 && c != '\n'){

        if(i >= *tamanho){
            char *novo = AumentaTamanhoVetor(vetor, *tamanho);

            if(novo == NULL){
                printf("Erro ao aumentar vetor\n");
                return vetor;
            }

            vetor = novo;
            *tamanho += TAM_PADRAO;
        }

        vetor[i] = c;
        i++;
    }

    return vetor;
}

void ImprimeString(char *vetor){
    printf("%s", vetor);
}

void LiberaVetor(char *vetor){
    free(vetor);
}