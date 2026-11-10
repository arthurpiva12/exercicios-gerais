#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote{
    Type tipo;
    int qtdElem;
    void* conteudo;
    int soma;
};


tPacote* CriaPacote(Type type, int numElem){
    tPacote* pacote = malloc(sizeof(tPacote));

    if(pacote == NULL){
        return NULL;
    }

    //inicializando as variaveis
    pacote->tipo = type;
    pacote->qtdElem = numElem;
    pacote->soma = 0;
    
    if(pacote->tipo == INT){
        pacote->conteudo = malloc(sizeof(int) * numElem);
    }
    else{
        pacote->conteudo = malloc(sizeof(char) * numElem);
    }

    return pacote;
}

void DestroiPacote(tPacote* pac){
    free(pac->conteudo);
    free(pac);
}

void LePacote(tPacote* pac){
    for(int i=0; i<pac->qtdElem; i++){
        if(pac->tipo == INT){
            scanf("%d", &((int*)pac->conteudo)[i]);
        }
        else{
            scanf(" %c", &((char*)pac->conteudo)[i]);
        }
    }
}

void ImprimePacote(tPacote* pac){
    printf("%d ", pac->soma);

    if(pac->tipo == INT){
        for(int i=0; i<pac->qtdElem; i++){
            printf("%d ", ((int*)pac->conteudo)[i]);
        }
    }
    
    else{
        for(int i=0; i<pac->qtdElem; i++){
            printf("%c", ((char*)pac->conteudo)[i]);
        }
    }

    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->soma = 0;
    
    for(int i=0; i<pac->qtdElem; i++){

        if(pac->tipo == INT){
            pac->soma += ((int*)pac->conteudo)[i];
        }
        else{
            pac->soma += ((char*)pac->conteudo)[i];
        }
    }
}
