#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

struct gerenciadorpacotes{
    tPacote** pacote;
    int qtdPacote;
};

tGerenciador* CriaGerenciador(){
    tGerenciador* gerenciador = malloc(sizeof(tGerenciador));

    if(gerenciador == NULL){
        return NULL;
    }

    gerenciador->pacote = NULL;
    gerenciador->qtdPacote = 0;

    return gerenciador;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->pacote = realloc(geren->pacote, sizeof(tPacote*) * (geren->qtdPacote + 1));

    geren->pacote[geren->qtdPacote] = pac;
    geren->qtdPacote++;
}

void DestroiGerenciador(tGerenciador* geren){
    for(int i=0; i<geren->qtdPacote; i++){
        DestroiPacote(geren->pacote[i]);
    }

    free(geren->pacote);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacote[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i=0; i<geren->qtdPacote; i++){
        ImprimePacote(geren->pacote[i]);
    }
}