#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agencia.h"

struct Agencia{
    int num;
    int qtdContas;
    float saldoMedio;
    char nome[50];
    Vector* dadosContas;
};

tAgencia *CriaAgencia(){
    tAgencia* agencia = malloc(sizeof(tAgencia));

    if(agencia == NULL){
        return NULL;
    }  

    //inicializando as variaveis 
    agencia->dadosContas = VectorConstruct();
    agencia->num = 0;
    agencia->saldoMedio = 0.0;
    agencia->qtdContas = 0;

    return agencia;
}

void DestroiAgencia(DataType agencia){
    tAgencia* aux = (tAgencia*) agencia;

    VectorDestroy(aux->dadosContas, DestroiConta);
    free(aux);
}

void LeAgencia(tAgencia *agencia){
    scanf("%d;", &agencia->num);
    scanf("%[^\n]\n", &agencia->nome);
}

void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->dadosContas, conta);
    agencia->qtdContas++;
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->num){
        return 1;
    }

    return 0;
}

float GetSaldoMedioAgencia (tAgencia *agencia){
    float saldoTotal = 0.0;

    for(int i=0; i<agencia->qtdContas; i++){
        tConta* contaTemp = (tConta*) VectorGet(agencia->dadosContas, i);
        float num = GetSaldoConta(contaTemp);
        saldoTotal += num;
    }

    agencia->saldoMedio = saldoTotal/agencia->qtdContas;
    return agencia->saldoMedio;
}

void ImprimeDadosAgencia(tAgencia *agencia){
    printf("    Nome: %s\n", agencia->nome);
    printf("    Numero: %d\n", agencia->num);
    printf("    Numero de contas cadastradas: %d\n", agencia->qtdContas);
    printf("    Saldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
    printf("\n");
}