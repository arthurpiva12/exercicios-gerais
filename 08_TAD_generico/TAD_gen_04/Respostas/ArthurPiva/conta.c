#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conta.h"

struct Conta{
    int num;
    char nome[50];
    float saldo;
};

tConta *CriaConta(){
    tConta* conta = malloc(sizeof(tConta));

    if(conta == NULL){
        return NULL;
    }

    //inicializando as variaveis
    conta->saldo = 0.0;
    conta->num = 0;

    return conta;
}

void DestroiConta(DataType conta){
    free(conta);
}

void LeConta(tConta *conta){
    scanf("%d", &conta->num);
    scanf(";%[^;]", &conta->nome);
    scanf(";%f", &conta->saldo);
}

float GetSaldoConta(tConta *conta){
    return conta->saldo;
}


