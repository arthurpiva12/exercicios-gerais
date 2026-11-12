#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"

struct Banco{
    Vector* dadosAgencias;
    char nome[50];
    int qtdAgencias;
};

tBanco *CriaBanco(){
    tBanco* banco = malloc(sizeof(tBanco));

    if(banco == NULL){
        return NULL;
    }

    //inicializando as varaiveis
    banco->qtdAgencias = 0;
    banco->dadosAgencias = VectorConstruct();

    return banco;
}

void DestroiBanco(tBanco *banco){
    VectorDestroy(banco->dadosAgencias, DestroiAgencia);
    free(banco);
}

void LeBanco(tBanco *banco){
    scanf("%[^\n]\n", banco->nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->dadosAgencias, agencia);
    banco->qtdAgencias++;
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    for(int i=0; i<banco->qtdAgencias; i++){
        tAgencia* agencia = (tAgencia*) VectorGet(banco->dadosAgencias, i);

        if(ComparaAgencia(numAgencia, agencia) == 1){
            AdicionaConta(agencia, cliente);
            break;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for(int i=0; i<banco->qtdAgencias; i++){
        tAgencia* agencia = (tAgencia*) VectorGet(banco->dadosAgencias, i);
        ImprimeDadosAgencia(agencia);
    }
}

