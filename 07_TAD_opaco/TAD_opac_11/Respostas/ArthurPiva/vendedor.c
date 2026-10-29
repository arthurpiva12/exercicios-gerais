#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vendedor.h"

struct Vendedor{
    char* nome;
    float totalVendido;
    float salario;
    float comissao;
};

tVendedor* RegistraVendedor(char* nome, float salario, float prct_comissao){
    tVendedor* vendedor = malloc(sizeof(tVendedor));

    if(vendedor == NULL){
        return NULL;
    }

    //inicializando as variaveis
    vendedor->nome = malloc(strlen(nome) +1);
    if(vendedor->nome == NULL){
        free(vendedor);
        return NULL;
    }
    strcpy(vendedor->nome, nome);

    vendedor->salario = salario;
    vendedor->comissao = prct_comissao;
    vendedor->totalVendido = 0;

    return vendedor;
}

void ApagaVendedor(tVendedor* vendedor){
    if(vendedor == NULL){
        return;
    }
    
    free(vendedor->nome);
    free(vendedor);
}

int VerificaNomeVendedor(tVendedor* vendedor, char* nome){
    if(strcmp(vendedor->nome, nome) == 0){
        return 1;
    }

    return 0;
}

void ContabilizaVenda(tVendedor* vendedor, float valor){
    vendedor->totalVendido += valor;
}

float GetSalario(tVendedor* vendedor){
    return vendedor->salario;
}

float GetComissao(tVendedor* vendedor){
    return vendedor->comissao * vendedor->totalVendido;
}

float GetTotalVendido(tVendedor* vendedor){
    return vendedor->totalVendido;
}

float GetTotalRecebido(tVendedor* vendedor){
    float total = vendedor->salario + (vendedor->comissao * vendedor->totalVendido);
    return total;
}

void ImprimeRelatorioVendedor(tVendedor* vendedor){
    printf("    %s > Total vendido: R$%.2f\n", vendedor->nome, vendedor->totalVendido);

    float total = GetTotalRecebido(vendedor);
    printf("        Total recebido: R$%.2f\n", total);
}

