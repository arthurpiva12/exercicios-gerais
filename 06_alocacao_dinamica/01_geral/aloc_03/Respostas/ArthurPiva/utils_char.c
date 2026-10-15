#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho){
    char *vetor = malloc(tamanho * sizeof(char));

    if(vetor == NULL){
        return NULL;
    }

    for(int i=0; i<tamanho; i++){
        vetor[i] = '_';
    }

    return vetor;
}

void LeVetor(char *vetor, int tamanho){
    int i=0;
    scanf(" %c", &vetor[i]);

    while(vetor[i] != '\n'){
        if(i<tamanho-1){
            i++;
            scanf("%c", &vetor[i]);
        }
        else{
            break;
        }
    }

    if(vetor[i] == '\n'){
         vetor[i] = '_';
    }

}

void ImprimeString(char *vetor, int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}