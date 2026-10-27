#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"
#include "banco.h"

struct Conta{
    tUsuario* usuario;
    int numConta;
    float saldo;
};

tConta *CriaConta(){
    tConta* conta = malloc(sizeof(struct Conta));

    if(conta == NULL){
        exit(1);
    }

    //inicializando
    conta->usuario = CriaUsuario();
    conta->numConta = -1;
    conta->saldo = 0;

    return conta;
}

void DestroiConta(tConta *conta){
    DestroiUsuario(conta->usuario);
    free(conta);
}

void LeConta(tConta *conta){
    LeUsuario(conta->usuario);
    scanf("%d\n", &conta->numConta);
}

void ImprimeConta(tConta *conta){
    printf("Conta: %d\n", conta->numConta);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->usuario);
}

int VerificaConta(tConta *conta, int numero){
    if(conta->numConta == numero){
        return 1;
    }

    return 0;
}

void SaqueConta(tConta *conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo = conta->saldo - valor;
    }
}

void DepositoConta(tConta *conta, float valor){
    conta->saldo = valor + conta->saldo;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(origem->saldo >= valor){
        origem->saldo = origem->saldo - valor;
        destino->saldo = valor + destino->saldo;    
    }
}